#include <stdio.h>
#include "Speciale.h"
typedef struct Personnages Personnages;


#define NB_Personnages 12


 struct Personnages{
    char nom[25];
    char type[25];
    Speciales *att_spe1;
    Speciales *att_spe2;
    float point_de_vie_courante ;
    float point_de_vie_maximum;
    float att;
    float def;
    float agi;
    float vit;

};


Personnages *cherche_personnages(char*nom_personnages);
void list_perso2();
void select_perso();

void perso_bot();
void bot_trifusion_();