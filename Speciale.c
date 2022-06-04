#include "Speciale.h"
#include <stdlib.h>
#include <stdio.h>
#include "Personnages.h"
#define NB_ATT_SPE 24


Speciales tab[NB_ATT_SPE]={
    {.nom = "charge",.valeur  = 15 ,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "coupe",.valeur =,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "boule de feu",.valeur =,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "lancer de shurikens",.valeur = ,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "givre",.valeur = ,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "decoupe",.valeur = ,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "tranche",.valeur = ,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "tournis",.valeur =,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "griffe",.valeur =,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "tempete",.valeur = ,.descripti=  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "lance grenade",.valeur = ,.description =  ,.nb_tours_actifs = ,.nb_tours_rechargement},
    {.nom = "foudre",.valeur = ,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "charge",.valeur  = 15 ,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "coupe",.valeur =,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "boule de feu",.valeur =,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "lancer de shurikens",.valeur = ,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "givre",.valeur = ,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "decoupe",.valeur = ,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "tranche",.valeur = ,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "tournis",.valeur =,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "griffe",.valeur =,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "tempete",.valeur = ,.descripti=  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
    {.nom = "lance grenade",.valeur = ,.description =  ,.nb_tours_actifs = ,.nb_tours_rechargement},
    {.nom = "foudre",.valeur = ,.description =  ,.nb_tours_actifs =1000 ,.nb_tours_rechargement},
};


void action_att_spe(Personnages *attaquant,Personnages *receveur){
    Speciales  speciale_1;
    Speciales  speciale_2;

}