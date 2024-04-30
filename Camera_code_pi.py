from picamera2 import PiCamera
from time import sleep

# Initialisation de la caméra
camera = PiCamera()

# Prévisualisation de la caméra pendant 5 secondes
camera.start_preview()
sleep(5)

# Capture de la photo et sauvegarde dans un fichier
camera.capture('screenshot.jpg')

# Arrêt de la prévisualisation et libération des ressources
camera.stop_preview()
camera.close()
