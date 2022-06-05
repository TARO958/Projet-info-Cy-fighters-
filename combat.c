#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "combat.h"
#include "Personnages.h"
#include "interface.h"
#include "dif.h"

Speciales special[NB_ATT_SPE]={
    {.nom = "charge",.valeur = 80 ,.description = "fonce droit sur l'ennemie en infligeant des dégats "  ,.nb_tours_actifs = 1,.nb_tours_rechargement=2},
    {.nom = "boule magique",.valeur = 150 , .description = "infligle des dégats sur un adversaire" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "boule de feu",.valeur =100,.description ="lance une boule de feu et brule l'énnemie pendart 2 tours"  ,.nb_tours_actifs =2 ,.nb_tours_rechargement=2},
    {.nom = "lancer de shurikens",.valeur = 150 ,.description = "lance un shurikens" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "soin miraculeux ",.valeur = 200,.description = "géle l'adversaire" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=10},
    {.nom = "soin magique",.valeur = 150 ,.description = "tranche" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "protection",.valeur = 100,.description ="renforce la def du personnage de 0.25 "   ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "tourbillon",.valeur = 275 ,.description = "tourne rapidement sur soi-même avec l'épée en main " ,.nb_tours_actifs =1 ,.nb_tours_rechargement=10},
    {.nom = "griffe",.valeur = 275,.description =  "griffe l'adversaire",.nb_tours_actifs =1 ,.nb_tours_rechargement=10},
    {.nom = "tempete",.valeur = 275 , .description ="lance une tempête sur l'équipe ennemie qui touche tout les personnages pendant 3 tours"  ,.nb_tours_actifs =3 ,.nb_tours_rechargement=10},
    {.nom = "",.valeur = 25,.description = "lance une grenade" ,.nb_tours_actifs = 2,.nb_tours_rechargement=2},
    {.nom = "foudre",.valeur =310 ,.description = "lance un éclair " ,.nb_tours_actifs =1 ,.nb_tours_rechargement=10},
    {.nom = "pas de côté",.valeur  = 150 ,.description = "augmente l'agilite du personnage" ,.nb_tours_actifs = 1 ,.nb_tours_rechargement =2 },
    {.nom = "soin miraculeux ",.valeur = 200,.description = "géle l'adversaire" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=10},
    {.nom = "soin magique",.valeur = 150 ,.description = "tranche" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "poing ardent",.valeur = 275 , .description = "brule l'quipe adversaire pendant 2 tours" ,.nb_tours_actifs =2 ,.nb_tours_rechargement=10},
    {.nom = "crocs",.valeur = 110,.description ="mord l'adversaire"  ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "voile protecteur",.valeur = 100,.description ="augemente la def de toute l'quipe de 20% du personnage qui l'utilise"  ,.nb_tours_actifs =1,.nb_tours_rechargement=2},
    {.nom = "fumigene",.valeur = 100,.description = "le personnage devient impossible a ciblé pendant 3 tours mais il ne peut pas attaquer au tour suivant "  ,.nb_tours_actifs =1,.nb_tours_rechargement=2},
    {.nom = "mur de terre ",.valeur =150,.description = ""  ,.nb_tours_actifs =1,.nb_tours_rechargement=2},
    {.nom = "smash",.valeur =250,.description = "infligle des dégats  sur trois adversaires" ,.nb_tours_actifs =1,.nb_tours_rechargement=2},
    {.nom = "dash in",.valeur = 200, .description ="dash sur l'ennemi"  ,.nb_tours_actifs =1 ,.nb_tours_rechargement=10},
    {.nom = "lance grenade",.valeur = 150,.description = "lili" ,.nb_tours_actifs = 2,.nb_tours_rechargement=2},
    {.nom = "profonde entaille",.valeur =325 ,.description ="fais saigner l'adversaire pendant 2 tours" ,.nb_tours_actifs =2,.nb_tours_rechargement=10},
};


void trifusion(Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3],Personnages *ordre[6]){            //tri les vit des perso pour savoir qui commence(le systeme de vitesse n'est pas de meme que dans raid shadow legend)
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
    }
    fight(perso_select_joueur1,perso_select_joueur2,ordre);
}

void fight(Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3],Personnages *ordre[6]){
    do{
        for(int i=0;i<6;i++){
            for (int j=0;j<6;j++){
                if(ordre[i]==perso_select_joueur1[i]){
                    ordre[i]->point_de_vie_courante=perso_select_joueur1[i]->point_de_vie_courante;
                }
                else if (ordre[i]==perso_select_joueur2[i]){
                    ordre[i]->point_de_vie_courante=perso_select_joueur2[i]->point_de_vie_courante;
                }
            }
            if(ordre[i]->point_de_vie_courante>0){
                select_actions_perso(ordre[i],perso_select_joueur1,perso_select_joueur2);
            }
        }
    }while((perso_select_joueur1[0]->point_de_vie_courante+perso_select_joueur1[1]->point_de_vie_courante+perso_select_joueur1[2]->point_de_vie_courante!=0) && (perso_select_joueur2[0]->point_de_vie_courante+perso_select_joueur2[1]->point_de_vie_courante+perso_select_joueur2[2]->point_de_vie_courante!=0));
    fin_combat(perso_select_joueur1,perso_select_joueur2);
}

void select_actions_perso(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int choix_action;
    do {
        effectuer_action(attaquant,perso_select_joueur1,perso_select_joueur2);
        scanf("%d",&choix_action);
        viderclavier();
        switch(choix_action){
            case 1:
                select_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2);
                break;
            case 2:
                select_adversaire_spe1(attaquant,perso_select_joueur1,perso_select_joueur2);
                break;
            case 3:
                select_adversaire_spe2(attaquant,perso_select_joueur1,perso_select_joueur2);
            default :
                break;
        }
    }while (choix_action!=1 && choix_action!=2 && choix_action!=3);
}

void select_adversaire(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int x,y;
    if (attaquant==perso_select_joueur1[0] || attaquant==perso_select_joueur1[1] || attaquant==perso_select_joueur1[2]){
        do{
            choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur2);
            scanf("%d",&x);
            viderclavier();
            switch (x){
            case 1:
                if(perso_select_joueur2[0]->point_de_vie_courante>=0){
                    action_att(attaquant,perso_select_joueur2[0]);
                }
                break;
            case 2:
                if(perso_select_joueur2[1]->point_de_vie_courante>=0){
                    action_att(attaquant,perso_select_joueur2[1]);
                }
                break;
            case 3:
                if(perso_select_joueur2[3]->point_de_vie_courante>=0){
                    action_att(attaquant,perso_select_joueur2[2]);
                }
                break;
            default:
                break;
            }
        }while(x!=1 && x!=2 && x!=3);
    }
    else if (attaquant==perso_select_joueur2[0] || attaquant==perso_select_joueur2[1] || attaquant==perso_select_joueur2[2]){
        do{
            choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
            scanf("%d",&y);
            viderclavier();
            switch (y){
            case 1:
                if(perso_select_joueur1[0]->point_de_vie_courante>=0){
                    action_att(attaquant,perso_select_joueur1[0]);
                }
                break;
            case 2:
                if(perso_select_joueur1[1]->point_de_vie_courante>=0){
                    action_att(attaquant,perso_select_joueur1[1]);
                }
                break;
            case 3:
                if(perso_select_joueur1[2]->point_de_vie_courante>=0){
                    action_att(attaquant,perso_select_joueur1[2]);
                }
                break;
            default:
                break;
            }
        }while(y!=1 && y!=2 && y!=3);
    }
}

void select_adversaire_spe1(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int x,y;
    if (strcmpi(attaquant->nom,"Laurie")==0 || strcmpi(attaquant->nom,"Celine")==0){
        if (attaquant==perso_select_joueur1[0] || attaquant==perso_select_joueur1[1] || attaquant==perso_select_joueur1[2]){
            do{
                choix_heal(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                scanf("%d",&x);
                viderclavier();
                switch (x){
                case 1:
                    if(perso_select_joueur1[0]->point_de_vie_courante>=0){
                        action_heal_spe1(attaquant,perso_select_joueur1[0]);
                    }
                    break;
                case 2:
                    if(perso_select_joueur1[1]->point_de_vie_courante>=0){
                        action_heal_spe1(attaquant,perso_select_joueur1[1]);
                    }
                    break;
                case 3:
                    if(perso_select_joueur1[2]->point_de_vie_courante>=0){
                        action_heal_spe1(attaquant,perso_select_joueur1[2]);
                    }
                    break;
                default:
                    break;
                }
            }while(x!=1 && x!=2 && x!=3);
        }
        else if (attaquant==perso_select_joueur2[0] || attaquant==perso_select_joueur2[1] || attaquant==perso_select_joueur2[2]){
            do{
                choix_heal(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur2);
                scanf("%d",&y);
                viderclavier();
                switch (y){
                case 1:
                    if(perso_select_joueur2[0]->point_de_vie_courante>=0){
                        action_heal_spe1(attaquant,perso_select_joueur2[0]);
                    }
                    break;
                case 2:
                    if(perso_select_joueur2[1]->point_de_vie_courante>=0){
                        action_heal_spe1(attaquant,perso_select_joueur2[1]);
                    }
                    break;
                case 3:
                    if(perso_select_joueur2[2]->point_de_vie_courante>=0){
                        action_heal_spe1(attaquant,perso_select_joueur2[2]);
                    }
                    break;
                default:
                    break;
                }
            }while(y!=1 && y!=2 && y!=3);
        }
    }
    else{
        if (attaquant==perso_select_joueur1[0] || attaquant==perso_select_joueur1[1] || attaquant==perso_select_joueur1[2]){
            do{
                choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur2);
                scanf("%d",&x);
                viderclavier();
                switch (x){
                case 1:
                    if(perso_select_joueur2[0]->point_de_vie_courante>=0){
                        action_att_spe1(attaquant,perso_select_joueur2[0]);
                    }
                    break;
                case 2:
                    if(perso_select_joueur2[1]->point_de_vie_courante>=0){
                        action_att_spe1(attaquant,perso_select_joueur2[1]);
                    }
                    break;
                case 3:
                    if(perso_select_joueur2[2]->point_de_vie_courante>=0){
                        action_att_spe1(attaquant,perso_select_joueur2[2]);
                    }
                    break;
                default:
                    break;
                }
            }while(x!=1 && x!=2 && x!=3);
        }
        else if (attaquant==perso_select_joueur2[0] || attaquant==perso_select_joueur2[1] || attaquant==perso_select_joueur2[2]){
            do{
                choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                scanf("%d",&y);
                viderclavier();
                switch (y){
                case 1:
                    if(perso_select_joueur1[0]->point_de_vie_courante>=0){
                        action_att_spe1(attaquant,perso_select_joueur1[0]);
                    }
                    break;
                case 2:
                    if(perso_select_joueur1[1]->point_de_vie_courante>=0){
                        action_att_spe1(attaquant,perso_select_joueur1[1]);
                    }
                    break;
                case 3:
                    if(perso_select_joueur1[2]->point_de_vie_courante>=0){
                        action_att_spe1(attaquant,perso_select_joueur1[2]);
                    }
                    break;
                default:
                    break;
                }
            }while(y!=1 && y!=2 && y!=3);
        }
    }
}

void select_adversaire_spe2(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int x,y;
    if (strcmpi(attaquant->nom,"Laurie")==0 || strcmpi(attaquant->nom,"Celine")==0){
        if (attaquant==perso_select_joueur1[0] || attaquant==perso_select_joueur1[1] || attaquant==perso_select_joueur1[2]){
            do{
                choix_heal(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                scanf("%d",&x);
                viderclavier();
                switch (x){
                case 1:
                    if(perso_select_joueur1[0]->point_de_vie_courante>=0){
                        action_heal_spe2(attaquant,perso_select_joueur1[0]);
                    }
                    break;
                case 2:
                    if(perso_select_joueur1[1]->point_de_vie_courante>=0){
                        action_heal_spe2(attaquant,perso_select_joueur1[1]);
                    }
                    break;
                case 3:
                    if(perso_select_joueur1[2]->point_de_vie_courante>=0){
                        action_heal_spe2(attaquant,perso_select_joueur1[2]);
                    }
                    break;
                default:
                    break;
                }
            }while(x!=1 && x!=2 && x!=3);
        }
        else if (attaquant==perso_select_joueur2[0] || attaquant==perso_select_joueur2[1] || attaquant==perso_select_joueur2[2]){
            do{
                choix_heal(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur2);
                scanf("%d",&y);
                viderclavier();
                switch (y){
                case 1:
                    if(perso_select_joueur2[0]->point_de_vie_courante>=0){
                        action_heal_spe2(attaquant,perso_select_joueur2[0]);
                    }
                    break;
                case 2:
                    if(perso_select_joueur2[1]->point_de_vie_courante>=0){
                        action_heal_spe2(attaquant,perso_select_joueur2[1]);
                    }
                    break;
                case 3:
                    if(perso_select_joueur2[2]->point_de_vie_courante>=0){
                        action_heal_spe2(attaquant,perso_select_joueur2[2]);
                    }
                    break;
                default:
                    break;
                }
            }while(y!=1 && y!=2 && y!=3);
        }
    }
    else{
        if (attaquant==perso_select_joueur1[0] || attaquant==perso_select_joueur1[1] || attaquant==perso_select_joueur1[2]){
            do{
                choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur2);
                scanf("%d",&x);
                viderclavier();
                switch (x){
                case 1:
                    if(perso_select_joueur2[0]->point_de_vie_courante>=0){
                        action_att_spe2(attaquant,perso_select_joueur2[0]);
                    }
                    break;
                case 2:
                    if(perso_select_joueur2[1]->point_de_vie_courante>=0){
                        action_att_spe2(attaquant,perso_select_joueur2[1]);
                    }
                    break;
                case 3:
                    if(perso_select_joueur2[2]->point_de_vie_courante>=0){
                        action_att_spe2(attaquant,perso_select_joueur2[2]);
                    }
                    break;
                default:
                    break;
                }
            }while(x!=1 && x!=2 && x!=3);
        }
        else if (attaquant==perso_select_joueur2[0] || attaquant==perso_select_joueur2[1] || attaquant==perso_select_joueur2[2]){
            do{
                choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                scanf("%d",&y);
                viderclavier();
                switch (y){
                case 1:
                    if(perso_select_joueur1[0]->point_de_vie_courante>=0){
                    action_att_spe2(attaquant,perso_select_joueur1[0]);
                    }
                    break;
                case 2:
                    if(perso_select_joueur1[1]->point_de_vie_courante>=0){
                    action_att_spe2(attaquant,perso_select_joueur1[1]);
                    }
                    break;
                case 3:
                    if(perso_select_joueur1[2]->point_de_vie_courante>=0){
                    action_att_spe2(attaquant,perso_select_joueur1[2]);
                    }
                    break;
                default:
                    break;
                }
            }while(y!=1 && y!=2 && y!=3);
        }
    }
}

void action_att(Personnages *attaquant,Personnages *receveur){
    float degat,chance_esquive;
    srand(time(NULL));
    chance_esquive=rand()%11/10.0;
    if (chance_esquive < receveur->agi){
        printf("%s dodges !!\n",receveur->nom);
        degat =0;
    }
    else{
          degat = attaquant->att-(attaquant->att*receveur->def);
          if(degat > 0 ){
        receveur->point_de_vie_courante-=degat;
        if (receveur->point_de_vie_courante<0){
            receveur->point_de_vie_courante=0;
        }
        printf("%s takes %f damage !\n%s has now %d HP !\n",receveur->nom,degat,receveur->nom,(int)receveur->point_de_vie_courante);
        }
    }
}

void action_att_spe1(Personnages *attaquant,Personnages *receveur){
    float degat,chance_esquive;
    srand(time(NULL));
    chance_esquive=rand()%11/10.0;
    if (chance_esquive < receveur->agi){
        printf("%s dodges !!\n",receveur->nom);
        degat =0;
    }
    else{
          degat = attaquant->att_spe1->valeur-(attaquant->att_spe1->valeur*receveur->def);
          if(degat > 0 ){
        receveur->point_de_vie_courante-=degat;
        if(receveur->point_de_vie_courante<0){
            receveur->point_de_vie_courante=0;
        }
        printf("%s takes %f damage !\n%s has now %d HP !\n",receveur->nom,degat,receveur->nom,(int)receveur->point_de_vie_courante);
        }
    }
}

void action_att_spe2(Personnages *attaquant,Personnages *receveur){
    float degat,chance_esquive;
    srand(time(NULL));
    chance_esquive=rand()%11/10.0;
    if (chance_esquive < receveur->agi){
        printf("%s dodges !!\n",receveur->nom);
        degat =0;
    }
    else{
          degat = attaquant->att_spe2->valeur-(attaquant->att_spe2->valeur*receveur->def);
          if(degat > 0 ){
        receveur->point_de_vie_courante-=degat;
        if(receveur->point_de_vie_courante<0){
            receveur->point_de_vie_courante=0;
        }
        printf("%s takes %f damage !\n%s has now %d HP !\n",receveur->nom,degat,receveur->nom,(int)receveur->point_de_vie_courante);
        }
    }
    
}

void action_heal_spe1(Personnages *attaquant,Personnages *receveur){
    float heal;
        if(heal > 0 ){
            heal=attaquant->att_spe1->valeur;
            receveur->point_de_vie_courante+=heal;
            printf("%s heals %f HP !\n%s has now %d HP !\n",receveur->nom,heal,receveur->nom,(int)receveur->point_de_vie_courante);
        }
}

void action_heal_spe2(Personnages *attaquant,Personnages *receveur){
    float heal;
    heal=attaquant->att_spe2->valeur;
    receveur->point_de_vie_courante+=heal;
    printf("%s heals %f HP !\n%s has now %d HP !\n",receveur->nom,heal,receveur->nom,(int)receveur->point_de_vie_courante);
}

void fin_combat( Personnages *perso_select_joueur1[3], Personnages *perso_select_joueur2[3]){
    if(perso_select_joueur2[0]->point_de_vie_courante==0 && perso_select_joueur2[1]->point_de_vie_courante==0 && perso_select_joueur2[2]->point_de_vie_courante==0){
        gagnant(perso_select_joueur1);
    }
    else{
        gagnant(perso_select_joueur2);
    }
    exit(0);
}