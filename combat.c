#include <stdio.h>
#include <stdlib.h>
#include "combat.h"
#include "Personnages.h"

#define NMB_perso 6 


void select_engagement(Personnages perso_select_joueur1[],Personnages perso_select_joueur2[]){
    float vit1[2][3]={0};
    float vit2[2][3]={0};
    vit1[0][0]=perso_select_joueur1[0].vit;
    vit1[0][1]=perso_select_joueur1[1].vit;
    vit1[0][2]=perso_select_joueur1[2].vit;
    vit1[1][0]=0;
    vit1[1][1]=1;
    vit1[1][2]=2;
    int i,j,c;
    for(i=0;i<3;i++){
        for(j=i;j<3;j++){
            if ( vit1[0][i] > vit1[0][j] ) {
                c = vit1[0][i];
                vit1[0][i] = vit1[0][j];
                vit1[0][j] = c;
                
                c = vit1[1][i];
                vit1[1][i] = vit1[1][j];
                vit1[1][j] = c;
    
            }
        }
    }   
    vit2[0][0]=perso_select_joueur2[0].vit;
    vit2[0][1]=perso_select_joueur2[1].vit;
    vit2[0][2]=perso_select_joueur2[2].vit;
    vit2[1][0]=0;
    vit2[1][1]=1;
    vit2[1][2]=2;
    int a,b,d;
    for(a=0;a<3;a++){
        for(b=a;b<3;b++){
            if ( vit2[0][a] > vit2[0][b] ) {
                d = vit2[0][a];
                vit2[0][a] = vit2[0][b];
                vit2[0][b] = d;
                
                d = vit2[1][a];
                vit2[1][a] = vit2[1][b];
                vit2[1][b] = d;
    
            }
        }
    }   
printf("%c  %d",perso_select_joueur1[(int)vit1[1][0]],(int)vit1[0][0]);

}








