import numpy as np
from PIL import Image
import matplotlib.pyplot as plt

import os
os.environ['TF_ENABLE_ONEDNN_OPTS'] = '0'

import tensorflow as tf

# Charger le modèle InceptionV3 pré-entraîné
model = tf.keras.applications.InceptionV3(include_top=True, weights='imagenet')

# Prétraitement de l'image
def preprocess_image(image_path):
    img = Image.open(image_path)
    img = img.resize((299, 299))  # La taille d'entrée attendue pour InceptionV3
    img_array = np.array(img)
    img_array = tf.keras.applications.inception_v3.preprocess_input(img_array)
    return img_array[np.newaxis]  # Ajouter une dimension pour correspondre à la forme d'entrée du modèle

# Post-traitement des prédictions pour obtenir la couleur principale
def get_main(predictions, top_k=5):
    # Obtenir les n premières prédictions (les n premières classes d'objets)
    top_predictions = tf.keras.applications.imagenet_utils.decode_predictions(predictions, top=top_k)[0]
    # Extraire les noms des classes prédites
    class_names = [class_name for _, class_name, _ in top_predictions]
    # Afficher les noms des classes
    print("Prédictions (classes d'objets) :", class_names)
    # Dans cet exemple, on suppose que la couleur est la première prédiction (indice 0)
    main_color = class_names[0]
    return main

# Charger l'image et effectuer la prédiction
def predict_main(image_path):
    img_array = preprocess_image(image_path)
    predictions = model.predict(img_array)
    main_color = get_main(predictions)
    return main

# Chemin de l'image à tester
image_path = 'rouge.jpg'

# Effectuer la prédiction
main = predict_main(image_path)
print("Couleur principale prédite :", main)

# Affichage de l'image
img = Image.open(image_path)
plt.imshow(img)
plt.axis('off')
plt.title(f"Main Color: {main}")
plt.show()
