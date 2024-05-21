import os
os.environ['TF_ENABLE_ONEDNN_OPTS'] = '0'

import tensorflow as tf
import numpy as np
import cv2
from keras.models import load_model

def analyze_image(image):

	model = tf.keras.applications.MobileNetV2(weights='imagenet')

	image = cv2.imread('test.jpg')

	resized = cv2.resize(image,(224,224))
	resized = tf.keras.preprocessing.image.img_to_array(resized)
	resized = tf.keras.applications.mobilenet_v2.preprocess_input(resized)

	predictions = model.predict(np.array([resized]))
	decoded_predictions = tf.keras.applications.mobilenet_v2.decode_predictions(predictions,top=5)

	return decoded_predictions[0]
