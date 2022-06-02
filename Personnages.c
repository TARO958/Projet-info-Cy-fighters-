#include <string.h>
#include "Personnages.h"
#include <stdlib.h>

Personnages tab[NB_Personnages]={
    {.nom = "Adrien",.point_de_vie_courante = 700 ,.point_de_vie_maximum =1000 ,.agi=0.3,.att =40,.vit = 20,.def = 0.6},
    {.nom = "Céline",.point_de_vie_courante = 250 ,.point_de_vie_maximum =1000 ,.agi=0.8,.att =70,.vit = 90,.def = 0.2},
    {.nom = "Peter",.type = "Mage",.point_de_vie_courante = 500 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =50,.vit = 50,.def = 0.5},
    {.nom = "Lucas",.point_de_vie_courante = 750 ,.point_de_vie_maximum =1000 ,.agi=0.2,.att =30,.vit = 15,.def = 0.65},
    {.nom = "Samuel",.point_de_vie_courante = 250 ,.point_de_vie_maximum =1000 ,.agi=0.4,.att =90,.vit = 60,.def = 0.1},
    {.nom = "Thibaut",.point_de_vie_courante = 800 ,.point_de_vie_maximum =1000 ,.agi=0.15,.att =20,.vit = 40,.def = 0.8},
    {.nom = "Sabrina",.point_de_vie_courante = 500 ,.point_de_vie_maximum =1000 ,.agi=0.1,.att =80,.vit = 50,.def = 0.6},
    {.nom = "Léa",.point_de_vie_courante = 150 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 30,.def = 0.4},
    {.nom = "Laurie",.point_de_vie_courante = 550 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 80,.def = 0.2},
    {.nom = "Theo",.point_de_vie_courante = 350 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 60,.def = 0.9},
    {.nom = "Evan",.point_de_vie_courante = 450 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 20,.def = 0.1},
    {.nom = "Enzo",.point_de_vie_courante = 250 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 10,.def = 0.5},

};


Personnages *cherche_personnages(char*nom_personnages){
    for(int i=0;i<NB_Personnages;i++){
        if(strcmp(tab[i].nom,nom_personnages)==0){
            return &tab[i];
        }
    }
    return NULL; 
}

void liste_personnages(){
    for(int i=0; i<NB_Personnages;i++){
        printf("%d : %s{ Point de vie : %f , att = %f\n           agi = %f, def = %f}\n",i+1,tab[i].nom,tab[i].point_de_vie_courante,tab[i].att,tab[i].agi,tab[i].def);
    }
}

int main(){
    liste_personnages();
}

