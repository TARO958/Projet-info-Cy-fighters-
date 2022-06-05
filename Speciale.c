
#include <stdlib.h>
#include <stdio.h>
#include "Personnages.h"



Speciales spe[NB_ATT_SPE]={
    {.nom = "charge",.valeur = 40 ,.description = "fonce droit sur l'ennemie en infligeant des dégats "  ,.nb_tours_actifs = 1,.nb_tours_rechargement=2},
    {.nom = "boule magique",.valeur = 70 , .description = "infligle des dégats sur un adversaire" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "boule de feu",.valeur =75,.description ="lance une boule de feu et brule l'énnemie pendart 2 tours"  ,.nb_tours_actifs =2 ,.nb_tours_rechargement=2},
    {.nom = "lancer de shurikens",.valeur = 125 ,.description = "lance un shurikens" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "soin miraculeux ",.valeur = 35,.description = "géle l'adversaire" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=10},
    {.nom = "soin magique",.valeur = 999 ,.description = "tranche" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "protection",.valeur = 0.25,.description ="renforce la def du personnage de 0.25 "   ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "tourbillon",.valeur = 150 ,.description = "tourne rapidement sur soi-même avec l'épée en main " ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "griffe",.valeur = 90,.description =  "griffe l'adversaire",.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "tempete",.valeur = 25 , .description ="lance une tempête sur l'équipe ennemie qui touche tout les personnages pendant 3 tours"  ,.nb_tours_actifs =3 ,.nb_tours_rechargement=2},
    {.nom = "",.valeur = 25,.description = "lance une grenade" ,.nb_tours_actifs = 2,.nb_tours_rechargement=2},
    {.nom = "foudre",.valeur =25 ,.description = "lance un éclair " ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "pas de côté",.valeur  = 15 ,.description = "augmente l'agilite du personnage" ,.nb_tours_actifs = 1 ,.nb_tours_rechargement =2 },
    {.nom = "soin magique",.valeur =25,.description =  "",.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "soin miraculeux ",.valeur =25,.description =""  ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "poing ardent",.valeur = 25 , .description = "brule l'quipe adversaire pendant 2 tours" ,.nb_tours_actifs =2 ,.nb_tours_rechargement=2},
    {.nom = "crocs",.valeur = 25,.description ="mord l'adversaire"  ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "voile protecteur",.valeur = 25,.description ="augemente la def de toute l'quipe de 20% du personnage qui l'utilise"  ,.nb_tours_actifs =1,.nb_tours_rechargement=2},
    {.nom = "fumigene",.valeur = 25,.description = "le personnage devient impossible a ciblé pendant 3 tours mais il ne peut pas attaquer au tour suivant "  ,.nb_tours_actifs =1,.nb_tours_rechargement=2},
    {.nom = "mur de terre ",.valeur =25,.description = ""  ,.nb_tours_actifs =1,.nb_tours_rechargement=2},
    {.nom = "smash",.valeur =25,.description = "infligle des dégats  sur trois adversaires" ,.nb_tours_actifs =1,.nb_tours_rechargement=2},
    {.nom = "",.valeur = 25, .description =""  ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "lance grenade",.valeur = 25,.description = "lili" ,.nb_tours_actifs = 2,.nb_tours_rechargement=2},
    {.nom = "profonde entaille",.valeur =25 ,.description ="fais saigner l'adversaire pendant 2 tours" ,.nb_tours_actifs =2,.nb_tours_rechargement=2},
};


void action_att_spe(Personnages *attaquant,Personnages *receveur){
    

}