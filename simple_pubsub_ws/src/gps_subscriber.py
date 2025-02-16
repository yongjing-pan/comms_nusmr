import sys
import rclpy
from rclpy.node import Node
from sensor_msgs.msg import NavSatFix
from PyQt5.QtWidgets import QApplication, QLabel, QVBoxLayout, QWidget

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
        self.gui_callback(lat, lon, alt, accuracy)

class GPSGUI(QWidget):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("GPS Data Viewer")

        self.layout = QVBoxLayout()
        self.label = QLabel("Waiting for GPS data...")
        self.layout.addWidget(self.label)
        self.setLayout(self.layout)

        self.node = GPSSubscriber(self.update_gps_data)

    def update_gps_data(self, lat, lon, alt, accuracy):
        gps_text = f"Latitude: {lat}\nLongitude: {lon}\nAltitude: {alt}\nAccuracy: {accuracy}m"
        self.label.setText(gps_text)
        print("lat: {lat}, long: {long}, altitude: {altitude}, accuracy: {accuracy}")

def main():
    rclpy.init()
    app = QApplication(sys.argv)
    
    gui = GPSGUI()
    gui.show()

    executor = rclpy.executors.MultiThreadedExecutor()
    executor.add_node(gui.node)
    
    try:
        executor.spin()
    except KeyboardInterrupt:
        pass
    finally:
        gui.node.destroy_node()
        rclpy.shutdown()
        sys.exit(app.exec())

if __name__ == '__main__':
    main()
