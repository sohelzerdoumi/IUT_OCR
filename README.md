#Projet OCR#

##Présentation##

Cette application a été réalisée dans le cadre d'un projet d'imagerie à l'IUT informatique de Bordeaux.

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




