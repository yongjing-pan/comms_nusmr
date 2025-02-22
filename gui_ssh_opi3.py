import sys
import subprocess
import threading
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QHBoxLayout, QLabel, QPushButton, QComboBox, QLineEdit, QMessageBox
from PyQt5.QtGui import QIntValidator 
import paramiko

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix 

# Function to send bash commands to the rover
def send_bash_command_via_ssh(command, host):
    if host == 'orin':
        rover_ip_addr = '192.168.1.16'
        rover_username = 'orinnx'
        rover_password = 'pw'
    else:
        rover_ip_addr = '192.168.153.136'
        rover_username = 'orangepi'
        rover_password = 'orangepi'
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    ssh.connect(rover_ip_addr, username=rover_username, password=rover_password)
    stdin, stdout, stderr = ssh.exec_command(command)
    print(stdout.read().decode())
    print(stderr.read().decode())
    ssh.close()

# Function to start and display video stream using ffplay
def display_video(stream_url, stream_id, resolution):
    if stream_id == 1:
        position = '-left 0 -top 0'
    elif stream_id == 2:
        position = '-left 715 -top 0' 
    elif stream_id == 3:
        position = '-left 0 -top 550'
    else:
        position = '-left 715 -top 550'
    ffplay_command = f"ffplay -fflags nobuffer -flags low_delay -i {stream_url} -window_title 'Stream {stream_id}' {position} -x 665 -y 500"
    process = subprocess.Popen(ffplay_command, shell=True)
    return process

# Function to update video stream settings (e.g., resolution, bitrate)
def update_video_settings(resolution, bitrate,stream_id,stream_url): 
    if stream_id == 1:
        video_num = 0
    elif stream_id == 2:
        video_num = 0
    elif stream_id == 3:
        video_num = 2
    else:
        video_num = 4
    bash_command = f"ffmpeg -f v4l2 -framerate 15 -video_size {resolution} -pixel_format mjpeg -i /dev/video{video_num} -c:v libx264 -b:v {bitrate}k -preset ultrafast -tune zerolatency -f mpegts {stream_url}"
    # Send the bash command to the rover
    if stream_id <= 1:
        host = 'orin'
        threading.Thread(target=send_bash_command_via_ssh, args=(bash_command,host)).start()
    else:
        host = 'opi'
        threading.Thread(target=send_bash_command_via_ssh, args=(bash_command,host)).start()

# Function to stop the video stream using the process ID
def stop_video_stream(process):
    if process:
        process.terminate()  # Terminate the process

# Main window class
class MarsRoverGUI(QWidget):
    def __init__(self):
        super().__init__()

        # Set up the window
        self.setWindowTitle("Mars Rover Video Stream Viewer")
        self.setGeometry(1200, 0, 300, 1200)
        self.move(1618,0)

        # Main Layout (Vertical stack for the whole window)
        self.main_layout = QVBoxLayout(self)

        # IP Address Input Field
        self.ip_label = QLabel("Base Station IP Address:")
        self.ip_input = QLineEdit(self)     
        self.ip_input.setPlaceholderText("Enter IP Address")
        self.ip_input.setText("192.168.1.18")  # Default IP

        # Layout for IP Address
        ip_layout = QHBoxLayout()
        ip_layout.addWidget(self.ip_label)
        ip_layout.addWidget(self.ip_input)

        self.main_layout.addLayout(ip_layout)

        # GPS Data Display
        self.gps_label = QLabel("GPS Data") 

        # Layout for IP Address
        gps_layout = QHBoxLayout()
        gps_layout.addWidget(self.gps_label) 

        self.main_layout.addLayout(gps_layout)

        # Stream controls (Vertical stack)
        self.stream_controls = []

        # Create labels and settings for each stream
        self.stream_processes = {}  # Store process for each stream

        for i in range(1, 5):
            stream_widget = self.create_stream_widget(i, self.ip_input)
            self.stream_controls.append(stream_widget)
            self.main_layout.addWidget(stream_widget)

        self.current_processes = {}  # To track running processes

    def create_stream_widget(self, stream_id, ip_input):
        # Stream control widget (Vertical stack for each stream)
        stream_widget = QWidget(self)
        stream_layout = QVBoxLayout()

        # Stream label
        stream_label = QLabel(f"Stream {stream_id}")
        stream_layout.addWidget(stream_label)

        # Dropdown for resolution
        resolution_label = QLabel(f"Stream {stream_id} Resolution:")
        resolution_combo = QComboBox(self)
        resolution_combo.addItems(["640x480", "1280x720", "1920x1080"])
        stream_layout.addWidget(resolution_label)
        stream_layout.addWidget(resolution_combo)

        # Integer input for bitrate
        bitrate_label = QLabel(f"Stream {stream_id} Bitrate (kbps):")
        bitrate_input = QLineEdit(self)
        bitrate_input.setValidator(QIntValidator(1, 10000))  # Allow integer values between 1 and 10000 kbps
        bitrate_input.setPlaceholderText("Enter bitrate in kbps")
        bitrate_input.setText("1300")  #Default bitrate

        stream_layout.addWidget(bitrate_label)
        stream_layout.addWidget(bitrate_input)

        # Start button to start the stream
        start_button = QPushButton(f"Start Stream {stream_id}", self)
        start_button.clicked.connect(lambda: self.start_stream(stream_id, resolution_combo, bitrate_input, ip_input))
        stream_layout.addWidget(start_button)

        # Exit button to stop the video stream
        exit_button = QPushButton(f"Exit Stream {stream_id}", self)
        exit_button.clicked.connect(lambda: self.exit_stream(stream_id))
        stream_layout.addWidget(exit_button)

        stream_widget.setLayout(stream_layout)

        return stream_widget

    def run_stream(self, stream_url, stream_id, resolution):
        process = display_video(stream_url, stream_id, resolution)
        self.current_processes[stream_id] = process

    def start_stream(self, stream_id, resolution_combo, bitrate_input, ip_input):
        # Get the selected resolution and bitrate for the given stream
        resolution = resolution_combo.currentText()
        bitrate = bitrate_input.text()
        ip_addr = ip_input.text()
        stream_url = self.get_stream_url(stream_id, ip_addr)

        # Validate the bitrate input
        if not bitrate.isdigit() or int(bitrate) <= 0:
            print("Invalid bitrate. Please enter a valid integer value.")
            return

        # First, stop the existing stream if running
        self.exit_stream(stream_id)

        # Update the video settings on the rover 
        update_video_settings(resolution, bitrate, stream_id, stream_url)

        # Restart the stream with new settings
        self.current_processes[stream_id] = threading.Thread(target=self.run_stream, args=(stream_url, stream_id, resolution), daemon=True)
        self.current_processes[stream_id].start()

    def get_stream_url(self, stream_id, ip_addr):
        # Return the appropriate stream URL for each stream_id
        if stream_id == 1:
            return "udp://"+ip_addr+":20001"
        elif stream_id == 2:
            return "udp://"+ip_addr+":20002"
        elif stream_id == 3:
            return "udp://"+ip_addr+":20003"
        else:
            return "udp://"+ip_addr+":20004"

    def exit_stream(self, stream_id):
        # Stop the stream process for the given stream_id
        process = self.current_processes.get(stream_id)
        if process:
            stop_video_stream(process)
            print(f"Stream {stream_id} has been stopped.")
        else:
            print(f"No process found for Stream {stream_id}")

    def stop_ffmpeg_streams_via_ssh(self, host):
        if host == 'orin':
            rover_ip_addr = '192.168.1.16'
            rover_username = 'orinnx'
            rover_password = 'pw'
        else:
            rover_ip_addr = '192.168.1.17'
            rover_username = 'orangepi'
            rover_password = 'orangepi'
        ssh = paramiko.SSHClient()
        ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
        ssh.connect(rover_ip_addr, username=rover_username, password=rover_password)
        
        kill_cmd = "pkill -f ffmpeg"
        stdin, stdout, stderr = ssh.exec_command(kill_cmd)
        print(stdout.read().decode())
        print(stderr.read().decode())
        ssh.close()
        
    def closeEvent(self, event):
        #Stop all streams when window is closed
            reply = QMessageBox.question(
                self, "Exit", "Are you sure you want to close the application?",
                QMessageBox.Yes | QMessageBox.No, QMessageBox.No
            )

            if reply == QMessageBox.Yes:
                print("Closing application. Stopping all streams...")
                self.stop_ffmpeg_streams_via_ssh('orin')
                self.stop_ffmpeg_streams_via_ssh('opi')

                stop_ffplay_command = "pkill -f ffmpeg"
                process = subprocess.Popen(stop_ffplay_command, shell=True)
                event.accept()
                
            else:
                event.ignore()

    def update_gps_data(self, lat, long, alt, accu):
        self.gps_label.setText(f"GPS Data:\nLatitude: {lat}\nLongitude: {long}\nAltitude: {alt}\nAccuracy: {accu}")

class GPSSubscriber(Node):
    def __init__(self, gui_callback):
        super().__init__('gps_gui_subscriber')
        self.subscription = self.create_subscription(
            NavSatFix, 'gps/fix', self.listener_callback, 10)
        self.gui_callback = gui_callback

    def listener_callback(self, msg):
        lat = msg.latitude
        lon = msg.longitude
        alt = msg.altitude
        accuracy = msg.position_covariance[0]  # Example: extracting accuracy
        print(f"In node, my values are: {lat} {lon} {alt} {accuracy}")
        self.gui_callback(lat, lon, alt, accuracy)

def run_gps_ros_node(gui_window):
    rclpy.init()
    gps_node = GPSSubscriber(gui_window.update_gps_data)

    rclpy.spin(gps_node)
    gps_node.destroy_node()
    rclpy.shutdown()

def main(args=None):
    app = QApplication(sys.argv)
    window = MarsRoverGUI()
    window.show() 

    # Start ROS in a separate thread
    gps_ros_thread = threading.Thread(target=run_gps_ros_node, args=(window,), daemon=True)
    gps_ros_thread.start() 
    sys.exit(app.exec_())

    # Destroy the node explicitly
    # (optional - otherwise it will be done automatically
    # when the garbage collector destroys the node object) 

if __name__ == '__main__':
    main()


