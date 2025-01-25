import sys
import cv2
import time
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QVBoxLayout, QPushButton, QLabel, QSlider, QHBoxLayout, QLineEdit, QWidget
)
from PyQt5.QtCore import Qt, QThread, pyqtSignal
from PyQt5.QtGui import QImage, QPixmap


class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Teleoperation GUI")
        self.setGeometry(100, 100, 800, 600)

        # Main layout
        self.central_widget = QWidget()
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        # Add subsection button
        self.add_subsection_button = QPushButton("Add Subsection")
        self.add_subsection_button.clicked.connect(self.add_subsection)
        self.layout.addWidget(self.add_subsection_button)

        # Track open camera indices
        self.open_cameras = set()

        # Track subsection windows
        self.subsection_windows = []

    def add_subsection(self):
        """ Create and show a new subsection window for an available camera """
        available_camera = self.get_available_camera()
        if available_camera is None:
            print("No available cameras left.")
            return

        # Create a new subsection window for the available camera
        print(f"Adding subsection for Camera {available_camera + 1}")
        subsection_window = SubsectionWindow(available_camera)
        subsection_window.show()
        subsection_window.closed.connect(self.on_subsection_closed)
        self.subsection_windows.append(subsection_window)

    def get_available_camera(self):
        """ Get an available camera index that is not currently open """
        for camera_index in range(10):  # Assuming a maximum of 10 cameras to check
            if camera_index not in self.open_cameras:
                self.open_cameras.add(camera_index)
                return camera_index
        return None

    def on_subsection_closed(self, camera_index):
        """ Update the list of open cameras when a subsection is closed """
        self.open_cameras.remove(camera_index)
        print(f"Camera {camera_index + 1} is now available.")


class SubsectionWindow(QWidget):
    closed = pyqtSignal(int)  # Signal emitted when the window is closed

    def __init__(self, camera_index):
        super().__init__()
        self.setWindowTitle(f"Camera {camera_index + 1}")
        self.setGeometry(150, 150, 640, 480)

        self.camera_index = camera_index

        # Main layout
        self.layout = QVBoxLayout(self)

        # Video display
        self.video_display = QLabel(self)
        self.video_display.setStyleSheet("background: black;")
        self.layout.addWidget(self.video_display)

        # Control layout
        self.controls_layout = QHBoxLayout()
        self.layout.addLayout(self.controls_layout)

        # Add "Turn Feed On/Off" button
        self.toggle_button = QPushButton("Turn Feed On")
        self.toggle_button.setCheckable(True)
        self.toggle_button.clicked.connect(self.toggle_feed)
        self.controls_layout.addWidget(self.toggle_button)

        # Add resolution slider
        self.resolution_slider = QSlider(Qt.Horizontal)
        self.resolution_slider.setMinimum(1)
        self.resolution_slider.setMaximum(10)
        self.resolution_slider.setValue(5)
        self.resolution_slider.valueChanged.connect(self.change_resolution)
        self.controls_layout.addWidget(QLabel("Resolution:"))
        self.controls_layout.addWidget(self.resolution_slider)

        # Add bandwidth display
        self.bandwidth_display = QLineEdit("0 KB/s")
        self.bandwidth_display.setReadOnly(True)
        self.bandwidth_display.setMaximumWidth(150)
        self.controls_layout.addWidget(self.bandwidth_display)

        # Camera feed and thread management
        self.is_feed_on = False
        self.cap = None
        self.capture_thread = None
        self.resolution = 5  # Default resolution

    def toggle_feed(self):
        """ Start or stop the feed """
        if not self.is_feed_on:
            self.start_feed()
        else:
            self.stop_feed()

    def start_feed(self):
        """ Start the video feed """
        if self.cap is None:
            print(f"Opening camera {self.camera_index + 1}")
            self.cap = cv2.VideoCapture(self.camera_index)
            if not self.cap.isOpened():
                print(f"Failed to open camera {self.camera_index + 1}.")
                self.cap = None
                return

        self.capture_thread = CaptureThread(self.cap, self.resolution)
        self.capture_thread.update_frame.connect(self.display_frame)
        self.capture_thread.update_bandwidth.connect(self.update_bandwidth)
        self.capture_thread.start()

        self.is_feed_on = True
        self.toggle_button.setText("Turn Feed Off")

    def stop_feed(self):
        """ Stop the video feed """
        if self.capture_thread:
            self.capture_thread.stop()
            self.capture_thread.wait()
            self.capture_thread = None

        if self.cap:
            self.cap.release()
            self.cap = None

        self.is_feed_on = False
        self.toggle_button.setText("Turn Feed On")

    def change_resolution(self):
        """ Update resolution from slider """
        self.resolution = self.resolution_slider.value()
        if self.capture_thread:
            self.capture_thread.resolution = self.resolution

    def display_frame(self, frame):
        """ Update the video display with the latest frame """
        try:
            if frame is None or frame.size == 0:
                print("Received invalid frame.")
                return  # Skip processing invalid frames

            rgb_frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
            h, w, ch = rgb_frame.shape
            bytes_per_line = ch * w
            qt_image = QImage(rgb_frame.data, w, h, bytes_per_line, QImage.Format_RGB888)
            pixmap = QPixmap.fromImage(qt_image)

            # Maintain aspect ratio while scaling to QLabel's size
            label_width = self.video_display.width()
            label_height = self.video_display.height()
            aspect_ratio_frame = w / h
            aspect_ratio_label = label_width / label_height

            if aspect_ratio_frame > aspect_ratio_label:
                # Constrain by width
                scaled_width = label_width
                scaled_height = int(label_width / aspect_ratio_frame)
            else:
                # Constrain by height
                scaled_height = label_height
                scaled_width = int(label_height * aspect_ratio_frame)

            # Apply scaled pixmap to QLabel
            self.video_display.setPixmap(pixmap.scaled(
                scaled_width, scaled_height,
                Qt.KeepAspectRatio, Qt.SmoothTransformation
            ))

        except Exception as e:
            print(f"Error in display_frame: {e}")

    def update_bandwidth(self, bandwidth):
        """ Update the bandwidth display """
        self.bandwidth_display.setText(f"{bandwidth:.2f} KB/s")

    def closeEvent(self, event):
        """ Emit signal when the window is closed """
        print(f"Subsection for Camera {self.camera_index + 1} is closing.")
        self.closed.emit(self.camera_index)
        super().closeEvent(event)


class CaptureThread(QThread):
    update_frame = pyqtSignal(object)
    update_bandwidth = pyqtSignal(float)

    def __init__(self, cap, resolution):
        super().__init__()
        self.cap = cap
        self.resolution = resolution
        self.is_running = True
        self.last_time = time.time()
        self.total_data = 0

    def run(self):
        """ Capture frames continuously """
        while self.is_running:
            ret, frame = self.cap.read()
            if ret:
                # Resize frame based on resolution slider value
                frame_resized = cv2.resize(frame, (self.resolution * 100, self.resolution * 100))
                self.update_frame.emit(frame_resized)

                # Calculate bandwidth
                frame_size = frame_resized.nbytes / 1024  # KB
                self.total_data += frame_size
                current_time = time.time()
                elapsed_time = current_time - self.last_time

                if elapsed_time >= 1.0:  # Update bandwidth every second
                    bandwidth = self.total_data / elapsed_time
                    self.update_bandwidth.emit(bandwidth)
                    self.total_data = 0
                    self.last_time = current_time

    def stop(self):
        """ Stop the capture thread """
        self.is_running = False


if __name__ == '__main__':
    try:
        app = QApplication(sys.argv)
        main_window = MainWindow()
        main_window.show()
        sys.exit(app.exec_())
    except Exception as e:
        print(f"Error in launching the application: {e}")

            


 
