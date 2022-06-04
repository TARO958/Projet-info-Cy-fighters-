#include "Speciale.h"
#include <stdlib.h>
#include <stdio.h>
#include "Personnages.h"
#define NB_ATT_SPE 24


Speciales tab[NB_ATT_SPE]={
    {.nom = "charge",.valeur = 15 ,.description = "fonce droit sur l'ennemie en infligeant des dégats "  ,.nb_tours_actifs = ,.nb_tours_rechargement},
    {.nom = "boule magique",.valeur = 1 , .description = "infligle des dégats sur un adversaire" ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "boule de feu",.valeur =25,.description ="lance une boule de feu et brule l'énnemie pendart 2 tours"  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "lancer de shurikens",.valeur =25 ,.description = "lance un shurikens" ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "",.valeur = 25,.description = "géle l'adversaire" ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "decoupe",.valeur = 25 ,.description = "tranche" ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "protection",.valeur = 25,.description ="renforce la def du personnage de 35 % "   ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "tournis",.valeur =25,.description = "tourne rapidement sur soi-même avec l'épée en main " ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "griffe",.valeur =25,.description =  "griffe l'adversaire",.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "tempete",.valeur = 25 , .description ="lance une tempête sur l'équipe ennemie qui touche tout les personnages pendant 3 tours"  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "lance grenade",.valeur = 25,.description = "lance une grenade" ,.nb_tours_actifs = ,.nb_tours_rechargement},
    {.nom = "foudre",.valeur =25 ,.description = "lance un éclair qui etourdie l'ennemie pendant 2 tours" ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "pas de côté",.valeur  = 15 ,.description = "augmente l'agilité du personnage" ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "soin magique",.valeur =25,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "soin miraculeux ",.valeur =25,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "poing ardent",.valeur = 25 , .description = "brule l'quipe adversaire pendant 2 tours" ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "crocs",.valeur = 25,.description ="mord l'adversaire"  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "voile protecteur",.valeur = 25,.description ="augemente la def de toute l'quipe de 20% du personnage qui l'utilise"  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "fumigene",.valeur = 25,.description = "le personnage devient impossible a ciblé pendant 3 tours mais il ne peut pas attaquer au tour suivant "  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "mur de terre ",.valeur =25,.description = ""  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "coup de coup percutant",.valeur =25,.description = "infligle des dégats colossaux sur un adversaire" ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "",.valeur = 25, .description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "lance grenade",.valeur = 25,.description =  ,.nb_tours_actifs = ,.nb_tours_rechargement},
    {.nom = "foudre",.valeur =25 ,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
};


void action_att_spe(Personnages *attaquant,Personnages *receveur){
    Speciales  speciale_1;
    Speciales  speciale_2;

}