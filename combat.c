#include <stdio.h>
#include <stdlib.h>
#include "combat.h"
#include "Personnages.h"
#include "interface.h"

void trifusion(Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[6],Personnages *ordre[6]){
    int a=0;
    int b=0;
    int i,j;
    Personnages *c;
    Personnages *c2;
    for(i=0;i<3;i++){
       for(j=i;j<3;j++){
           if ( perso_select_joueur1[i]->vit < perso_select_joueur1[j]->vit ){
                c = perso_select_joueur1[i];
                perso_select_joueur1[i] = perso_select_joueur1[j];
                perso_select_joueur1[j] = c;
           }
       }
    }
    for(i=0;i<3;i++){
       for(j=i;j<3;j++){
           if ( perso_select_joueur2[i]->vit < perso_select_joueur2[j]->vit ){
                c2 = perso_select_joueur2[i];
                perso_select_joueur2[i] = perso_select_joueur2[j];
                perso_select_joueur2[j] = c2;
           }
       }
    }
    for(i=0;i<6;i++){
        if(a>2){
            ordre[i]=perso_select_joueur2[b];
            b+=1;
        }
        else if(b>2){
            ordre[i]=perso_select_joueur1[a];
            a+=1;
        }
        else if( perso_select_joueur1[a]->vit < perso_select_joueur2[b]->vit){

            ordre[i]=perso_select_joueur2[b];
            b+=1;
        }
        else{
            ordre[i]=perso_select_joueur1[a];
            a+=1;
        }
    printf("%s;%f\n",ordre[i]->nom,ordre[i]->vit);
    }
}

void tri_vit(Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int i,j;
    Personnages *ordre[6];
    Personnages *ordre2[6];
    for(i=0;i<6;i++){
        if(i<3){
            ordre[i]=perso_select_joueur1[i];
        }
        else{
            ordre[i]=perso_select_joueur2[i-3];
        }
    }
    trifusion(perso_select_joueur1,perso_select_joueur2,ordre2);
}