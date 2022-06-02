#include <stdio.h>
#include "Speciale.h"
typedef struct Personnages Personnages;


#define NB_Personnages 12


 struct Personnages{
    char nom[25];
    char type[25];
    Speciales *att_spe;
    float point_de_vie_courante ;
    float point_de_vie_maximum;
    float att;
    float def;
    float agi;
    float vit;

};


Personnages *cherche_personnages(char*nom_personnages);
void liste_personnages();




