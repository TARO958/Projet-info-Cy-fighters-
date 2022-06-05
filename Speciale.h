#include <stdio.h>
#include <stdlib.h>
typedef struct Speciales Speciales; 
#define NB_ATT_SPE 24



  struct Speciales{
    char nom[25];
    float valeur;
    char description[200];
    int nb_tours_actifs;
    int nb_tours_rechargement;
    
};

void action_att_spe();
