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

# Function to start and display the combined video stream using ffmpeg
def display_combined_video(stream_urls, resolution):
    # Constructing the FFmpeg command to stack the videos
    filter_complex = ''.join([f"[{i}:v] scale={resolution} [v{i}];" for i in range(len(stream_urls))])
    stack_filter = f"[v0][v1][v2][v3]xstack=inputs={len(stream_urls)}:layout=0_0|w0_0|0_h0|w0_h0[out]"

    ffmpeg_command = f"ffmpeg -i {stream_urls[0]} -i {stream_urls[1]} -i {stream_urls[2]} -i {stream_urls[3]} " \
                     f"-filter_complex \"{filter_complex}{stack_filter}\" -map \"[out]\" -f mpegts -c:v libx264 -preset ultrafast -tune zerolatency -"

    # Using subprocess to execute the ffmpeg command
    process = subprocess.Popen(ffmpeg_command, shell=True)
    return process

# Function to update video stream settings (e.g., resolution, bitrate)
def update_video_settings(resolution, bitrate, stream_urls): 
    bash_command = f"ffmpeg -f v4l2 -framerate 15 -video_size {resolution} -pixel_format mjpeg -i /dev/video0 -c:v libx264 -b:v {bitrate}k -preset ultrafast -tune zerolatency -f mpegts {stream_urls[0]}"
    for i in range(1, len(stream_urls)):
        bash_command += f" {stream_urls[i]}"
    
    # Send the bash command to the rover
    host = 'orin'
    threading.Thread(target=send_bash_command_via_ssh, args=(bash_command, host)).start()

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
        self.setGeometry(1200, 0, 1200, 600)  # Adjusted window size
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

        # Layout for GPS Data
        gps_layout = QHBoxLayout()
        gps_layout.addWidget(self.gps_label) 
        self.main_layout.addLayout(gps_layout)

        # Stream controls (Vertical stack)
        self.stream_controls = []
        self.stream_processes = {}

        for i in range(1, 5):
            stream_widget = self.create_stream_widget(i, self.ip_input)
            self.stream_controls.append(stream_widget)
            self.main_layout.addWidget(stream_widget)

        self.current_processes = {}

        # Layout for combined video stream display
        self.stream_display_layout = QVBoxLayout()  # Add to hold combined video
        self.main_layout.addLayout(self.stream_display_layout)

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
        bitrate_input.setText("1300")  # Default bitrate
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

    def start_stream(self, stream_id, resolution_combo, bitrate_input, ip_input):
        # Get the selected resolution and bitrate for the given stream
        resolution = resolution_combo.currentText()
        bitrate = bitrate_input.text()
        ip_addr = ip_input.text()
        
        # Validate the bitrate input
        if not bitrate.isdigit() or int(bitrate) <= 0:
            print("Invalid bitrate. Please enter a valid integer value.")
            return

        # First, stop the existing stream if running
        self.exit_stream(stream_id)

        # Update the video settings on the rover 
        stream_urls = [self.get_stream_url(i+1, ip_addr) for i in range(4)]
        update_video_settings(resolution, bitrate, stream_urls)

        # Start displaying the combined stream in a single layout
        self.current_processes[stream_id] = threading.Thread(target=self.run_stream, args=(stream_urls, resolution), daemon=True)
        self.current_processes[stream_id].start()

    def run_stream(self, stream_urls, resolution):
        process = display_combined_video(stream_urls, resolution)
        self.current_processes['combined'] = process

    def get_stream_url(self, stream_id, ip_addr):
        # Return the appropriate stream URL for each stream_id
        return f"udp://{ip_addr}:200{stream_id:02}"

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
            rover_ip_addr = '192.168.1
