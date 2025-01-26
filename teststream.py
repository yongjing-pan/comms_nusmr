import subprocess
import time
# Run ffmpeg to capture the video from /dev/video2 and pipe it to ffplay
ffmpeg_command = [
    'ffmpeg', '-re','-f', 'v4l2', '-framerate', '15', '-video_size', '640x480', '-pixel_format', 'mjpeg', 
    '-i', '/dev/video1','-c:v', 'libx264', '-b:v', '1M', '-preset', 'ultrafast', 
    '-tune', 'zerolatency','-loglevel','debug', '-f', 'mpegts','-bufsize','32M', '-t','60','-'
]
# can remove -re, loglevel debug, 
process_ffmpeg = subprocess.Popen(ffmpeg_command, stdout=subprocess.PIPE)

ffplay_command = [
    'ffplay', '-fflags', 'nobuffer', '-flags', 'low_delay', '-i', '-'
]

process_ffplay = subprocess.Popen(ffplay_command, stdin=process_ffmpeg.stdout, stderr=subprocess.PIPE)

process_ffplay.wait()

process_ffmpeg.wait()
