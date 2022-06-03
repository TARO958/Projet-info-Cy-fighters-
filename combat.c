#include <stdio.h>
#include <stdlib.h>
#include "combat.h"
#include "Personnages.h"
#include <time.h>

#define NMB_perso 6 

void select_actions_perso(){
    int choix_action;
    do {
       printf("Quel action voulez-vous effectuer avec le perso?\n");
        scanf("%d",&choix_action);
        switch(choix_action){
            case 1:
            printf("Quel personnage voulez-vous attaquez,");
            //liste de perso a attaquer (que l'équipe enemmie)
            break;
            
            case 2:
            printf("Sur quel personnage voulez-vous lancer votre attaque spéciale ");
            break;

            default :
            break;
        }
    


    }while (choix_action != 0);
    
    

}



void action_att(Personnages *attaquant,Personnages *receveur){
    float degat,chance_esquive;
    degat = attaquant->att-(attaquant->att*receveur->def);
    srand(time(NULL));
    if(degat > 0 ){
        receveur->point_de_vie_courante-=degat;
    }
    if(receveur->agi > 0.5){
        chance_esquive=rand()%11/10.0;
    }
    else{
        chance_esquive = rand()%51/10.0;
    }
}


void tri_vit(Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int i,j;
    Personnages *c;
    for(i=0;i<3;i++){
       for(j=i;j<3;j++){
           if ( perso_select_joueur1[i]->vit < perso_select_joueur1[j]->vit ){
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