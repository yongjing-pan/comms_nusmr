import subprocess
import signal
import sys

#infact can just run these instead of everything else.

command = "ffmpeg -f v4l2 -framerate 15 -video_size 640x480 -pixel_format mjpeg -i /dev/video1 -c:v libx264 -b:v 1.3M -preset ultrafast -tune zerolatency -f mpegts -flush_packets 0 -bufsize 2M -probesize 32M - | ffplay -fflags nobuffer -flags low_delay -i -"
subprocess.call(command, shell=True)


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
