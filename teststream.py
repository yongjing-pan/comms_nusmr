import subprocess
import signal
import sys

#infact can just run these instead of everything else. However call() blocks anything else from running so Popen is still better for our purposes.
#Stream from your device to same device

cam_source = "/dev/video0"
cam_source2 = "/dev/video2"
cam_source3 = "/dev/video4"

"""
command = "ffmpeg -f v4l2 -framerate 15 -video_size 640x480 -pixel_format mjpeg -i /dev/video1 -c:v libx264 -b:v 1.3M -preset ultrafast -tune zerolatency -f mpegts -flush_packets 0 -bufsize 2M -probesize 32M - | ffplay -fflags nobuffer -flags low_delay -i -"
subprocess.call(command, shell=True)
"""

stream_to = "192.168.153.100:20001"
probe_size = "250k"
buffer_size = "1M"
flush_packets = "0"
command2 = "ffmpeg -f v4l2 -framerate 15 -r 50 -video_size 640x480 -pixel_format mjpeg -i "+cam_source+" -c:v libx264 -b:v 1.3M -preset ultrafast -tune zerolatency -f mpegts -flush_packets "+flush_packets+" -bufsize "+buffer_size+" -probesize "+probe_size+" udp://"+stream_to
subprocess.call(command2, shell=True)

#Use these to change settings dynamically
"""
ffmpeg_command = [
    'ffmpeg', '-re','-f', 'v4l2', '-framerate', '15', '-video_size', '640x480', '-pixel_format', 'mjpeg', 
    '-i', '/dev/video1','-c:v', 'libx264', '-b:v', '1M', '-preset', 'ultrafast', 
    '-tune', 'zerolatency','-loglevel','debug', '-f', 'mpegts','-flush_packets','0','-bufsize','64M','-'
]
#can remove -re, loglevel debug
process_ffmpeg = subprocess.Popen(ffmpeg_command, stdout=subprocess.PIPE)

ffplay_command = [
    'ffplay', '-fflags', 'nobuffer', '-flags', 'low_delay', '-i', '-'
]

process_ffplay = subprocess.Popen(ffplay_command, stdin=process_ffmpeg.stdout)

def signal_handler():
    print("Interrupt received, stopping stream.")
    process_ffmpeg.terminate()
    process_ffplay.terminate()
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)

process_ffplay.wait()

process_ffmpeg.wait()
"""
