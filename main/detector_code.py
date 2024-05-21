import gpiod
import time

DETECTOR_PIN = 27

def detection():
    chip = gpiod.Chip('gpiochip4')
    detek_line = chip.get_line(DETECTOR_PIN)
    detek_line.request(consumer="Detector",type=gpiod.LINE_REQ_DIR_IN)
    detek_state = detek_line.get_value()
    return detek_state
