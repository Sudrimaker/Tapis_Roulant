import camera_code as camera
import ia_code
import send_information
import detector_code


def main():
    if detector_code.detection() == 0:
        image = camera.capture_image(False)
        analysis_result = ia_code.analyze_image(image)
        print(analysis_result)
        for objet in analysis_result:
            if 'pencil'== objet[1] or 'ballpoint'==objet[1]:
                send_information.five_volt()
   
if __name__ == "__main__":
    while True:
        main()

