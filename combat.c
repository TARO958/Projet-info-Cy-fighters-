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


void action_att(Personnages attaquant,Personnages receveur){
    float degat,chance_esquive;
    srand(time(NULL));
    chance_esquive=rand()%11/10.0;
    if (chance_esquive < receveur->agi){
        printf("%s esquive !!",attaquant->nom);
        degat =0;
    }
    else{
          degat = attaquant->att-(attaquant->att*receveur->def);
          if(degat > 0 ){
        receveur->point_de_vie_courante-=degat;
        printf("%s a pris %f point de dégat ! Il lui reste %d point de vie ! \n",receveur->nom,degat,receveur->point_de_vie_courante);
        }
    }
}