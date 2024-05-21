from picamera2 import Picamera2, Preview
import time

picam2 = Picamera2()
camera_config = picam2.create_still_configuration(main={"size": (1920, 1080)}, lores={"size": (640, 480)}, display="lores")
picam2.configure(camera_config)

def capture_image(preview=True):
    if preview: picam2.start_preview(Preview.QTGL)
    picam2.start()
    picam2.capture_file("test.jpg")
    if preview: picam2.stop_preview()
    picam2.stop()


