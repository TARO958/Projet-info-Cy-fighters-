#include <stdio.h>
#include <stdlib.h>
#include "combat.h"
#include "Personnages.h"

#define NMB_perso 6 





void tri_vit(Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int i,j;
    Personnages *c;
    for(i=0;i<3;i++){
       for(j=i;j<3;j++){
           if ( perso_select_joueur1[i]->vit < perso_select_joueur1[j]->vit ) {
                c = perso_select_joueur1[i];
                perso_select_joueur1[i] = perso_select_joueur1[j];
               perso_select_joueur1[j] = c;
               
           }
       }
    }
    printf("%s  %f\n",perso_select_joueur1[0]->nom,perso_select_joueur1[0]->vit);   
    printf("%s  %f\n",perso_select_joueur1[1]->nom,perso_select_joueur1[1]->vit); 
    printf("%s  %f\n",perso_select_joueur1[2]->nom,perso_select_joueur1[2]->vit); 
}