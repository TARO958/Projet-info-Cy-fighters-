#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#include "combat.h"
#include "Personnages.h"
#include "interface.h"


void trifusion(Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3],Personnages *ordre[6]){
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
    fight(perso_select_joueur1,perso_select_joueur2,ordre);
}



void fight(Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3],Personnages *ordre[6]){
    do{
        for(int i=0;i<6;i++){
            select_actions_perso(ordre[i],perso_select_joueur1,perso_select_joueur2);
        }
    }while((perso_select_joueur1[0]->point_de_vie_courante==0 && perso_select_joueur1[1]->point_de_vie_courante==0 && perso_select_joueur1[2]->point_de_vie_courante==0) || (perso_select_joueur2[0]->point_de_vie_courante==0 && perso_select_joueur2[1]->point_de_vie_courante==0 && perso_select_joueur2[2]->point_de_vie_courante==0));
}

void select_actions_perso(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int choix_action;
    do {
        effectuer_action(attaquant,perso_select_joueur1,perso_select_joueur2);
        scanf("%d",&choix_action);
        switch(choix_action){
            case 1:
                select_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2);
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

void select_adversaire(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int i,x,y;
    for(i=0;i<3;i++){
            if (attaquant==perso_select_joueur1[i]){
                do{
                    printf("choix ennemi test");
                    //interface choix ennemi
                    scanf("%d",&x);
                    switch (x){
                    case 1:
                        action_att(attaquant,perso_select_joueur2[0]);
                        break;
                    case 2:
                        action_att(attaquant,perso_select_joueur2[1]);
                        break;
                    case 3:
                        action_att(attaquant,perso_select_joueur2[2]);
                        break;
                    default:
                        break;
                    }
                }while(x!=0);
            }
            else if (attaquant==perso_select_joueur2[i]){
                do{
                    //interface choix ennemi
                    scanf("%d",&y);
                    switch (y){
                    case 1:
                        action_att(attaquant,perso_select_joueur1[0]);
                        break;
                    case 2:
                        action_att(attaquant,perso_select_joueur1[1]);
                        break;
                    case 3:
                        action_att(attaquant,perso_select_joueur1[2]);
                        break;
                    default:
                        break;
                    }
                }while(x!=0);
            }
    }
}

void action_att(Personnages *attaquant,Personnages *receveur){
    float degat,chance_esquive;
    srand(time(NULL));
    chance_esquive=rand()%11/10.0;
    if (chance_esquive < receveur->agi){
        printf("%s esquive !!",receveur->nom);
        degat =0;
    }
    else{
          degat = attaquant->att-(attaquant->att*receveur->def);
          if(degat > 0 ){
        receveur->point_de_vie_courante-=degat;
        printf("%s a pris %f point de degat ! Il lui reste %d point de vie ! \n",receveur->nom,degat,receveur->point_de_vie_courante);
        }
    }
}