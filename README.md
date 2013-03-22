#Projet OCR#

##Présentation##

Cette application a été réalisée dans le cadre d'un projet d'imagerie à l'IUT informatique de Bordeaux.

L'objectif est de reconnaitre une forme contenu dans une image.

##Téléchargement##

> git clone https://github.com/sohelzerdoumi/IUT_OCR.git iutocr

##Compilation##

> cmake . &&  make

##Utilisation##

###Matrice de Confusion###
> ./Release -t 
>
> ./Release --test

###Analyser une image###
> ./Release -f base/0/0_5.png
>
> ./Release --file base/0/0_5.png

###Définir un fichier de configuration###
>./Release -t --config configs/94.txt

###Interface graphique###
>./Release -X

######Commandes:######
*  touche C : lance l'analyse de l'image ( voir le terminal )
*  touche S : sauvegarde l'image analysée dans la classe reconnu
*  clique gauche : dessiner 
*  clique droit  : tout effacer



