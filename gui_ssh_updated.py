
import sys
import subprocess
import threading
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QHBoxLayout, QLabel, QPushButton, QComboBox, QLineEdit
from PyQt5.QtGui import QIntValidator 
import paramiko

# Function to send bash commands to the rover
def send_bash_command_via_ssh(command, ip_address):
    ssh = paramiko.SSHClient()
    ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
    try:
        ssh.connect(ip_address, username='your_username', password='your_password')
        stdin, stdout, stderr = ssh.exec_command(command)
        print(stdout.read().decode())
    except Exception as e:
        print(f"SSH Connection Failed: {e}")
    finally:
        ssh.close()

# Function to start and display video stream using ffplay
def display_video(stream_url, stream_id):
    ffplay_command = f"ffplay -fflags nobuffer -flags low_delay -i {stream_url} -window_title 'Stream {stream_id}'"
    process = subprocess.Popen(ffplay_command, shell=True)
    return process

# Function to update video stream settings (e.g., resolution, bitrate)
def update_video_settings(resolution, bitrate, stream_id, stream_url, ip_address):
    bash_command = f"ffmpeg -f v4l2 -framerate 15 -video_size {resolution} -pixel_format mjpeg -i /dev/video{stream_id//2} -c:v libx264 -b:v {bitrate}k -preset ultrafast -tune zerolatency -f mpegts {stream_url}"
    threading.Thread(target=send_bash_command_via_ssh, args=(bash_command, ip_address)).start()

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
        self.setGeometry(100, 100, 1200, 600)

        # Main Layout (Vertical stack for the whole window)
        self.main_layout = QVBoxLayout(self)

        # IP Address Input Field
        self.ip_label = QLabel("Base Station IP Address:")
        self.ip_input = QLineEdit(self)
        self.ip_input.setPlaceholderText("Enter IP Address")
        self.ip_input.setText("192.168.18.5")  # Default IP

        # Layout for IP Address
        ip_layout = QHBoxLayout()
        ip_layout.addWidget(self.ip_label)
        ip_layout.addWidget(self.ip_input)

        self.main_layout.addLayout(ip_layout)

        # Stream controls (Vertical stack)
        self.stream_controls = []

        # Create labels and settings for each stream
        self.stream_processes = {}

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = MarsRoverGUI()
    window.show()
    sys.exit(app.exec_())
