## Tapis roulant à tri optique

Ce projet à été créé par Thomas Lamy, Leynaïck Duthieuw ainsi que Charlilou Maes dans le cadre du parcours innovation en Spé. Son objectif est de détecter les objetsindésirable et de les ejecter du tapis 

## Composants requis

- Arduino Uno (ou une carte compatible)
- 1 servomoteurs
- 1 écran LCD
- 1 Potentiometres
- 2 Nema 14
- 1 driver moteur pas à pas
- 4 roulement d'axe
- Câbles de connexion

## Schéma de câblage

![Schéma de câblage]("URL_image")

Connectez les servomoteurs aux broches 9 et 10 de l'Arduino. Connectez l'interrupteur à la broche 2 de l'Arduino. Assurez-vous d'utiliser une résistance de pull-up pour maintenir une lecture stable lorsque l'interrupteur est ouvert.

## Utilisation

Selectionner dans le code l'objet à ejecter,Allumer l'allimentation externes 12V 1A et l'allimentation de la carte Arduino. Regler la vitesse du moteur voulue et placer les objets sur le tapis

## Remarques

- Ne pas mettre d'objets trop lourds pour ne pas faire forcer le moteur et le driver 
- graisser les roulement de temps en temps


---




Utilisation du code IA : 

Le code IA est tiré de l'IA de détection d'objet d'opencv YOLO (You Only Look Once), on utilise ici la v4. Yolov4.cgf et .weights sont donc les fichiers utile au fonctionnement de l'IA. "coco.names" sert à définir les objets reconnaisable. Le code sert à faire fonctionner la pale a éjecter. Pour toute les info pour utiliser les servo moteur sur une rasberry : https://raspberry-pi.fr/servomoteur-raspberry-pi/
et il sert à utiliser un capteur infrarouge








Utilisation du code
