#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Personnages.h"
#include "interface.h"
#include "dif.h"
#include "bot.h"


void bot_fight(Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3],Personnages *ordre[6],int bot){       //meme chose que le combat mais simplifier + bot.
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
                if(ordre[i]==perso_select_joueur1[0] || ordre[i]==perso_select_joueur1[1] || ordre[i]==perso_select_joueur1[2]){
                    bot_select_actions_perso(ordre[i],perso_select_joueur1,perso_select_joueur2);
                }
                else{
                    bot_select_actions_bot(ordre[i],perso_select_joueur1,perso_select_joueur2,bot);
                }
            }
        }
    }while((perso_select_joueur1[0]->point_de_vie_courante+perso_select_joueur1[1]->point_de_vie_courante+perso_select_joueur1[2]->point_de_vie_courante!=0) && (perso_select_joueur2[0]->point_de_vie_courante+perso_select_joueur2[1]->point_de_vie_courante+perso_select_joueur2[2]->point_de_vie_courante!=0));
    bot_fin_combat(perso_select_joueur1,perso_select_joueur2);
}

void bot_select_actions_perso(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int choix_action;
    do {
        effectuer_action(attaquant,perso_select_joueur1,perso_select_joueur2);
        scanf("%d",&choix_action);
        viderclavier();
        switch(choix_action){
            case 1:
                bot_select_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2);
                break;
            case 2:
                bot_select_adversaire_spe1(attaquant,perso_select_joueur1,perso_select_joueur2);
                break;
            case 3:
                bot_select_adversaire_spe2(attaquant,perso_select_joueur1,perso_select_joueur2);
            default :
                break;
        }
    }while (choix_action!=1 && choix_action!=2 && choix_action!=3);
}

void bot_select_adversaire(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int x,y;
    do{
        choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur2);
        scanf("%d",&x);
        viderclavier();
        switch (x){
        case 1:
            if(perso_select_joueur2[0]->point_de_vie_courante>=0){
                bot_action_att(attaquant,perso_select_joueur2[0]);
            }
            break;
        case 2:
            if(perso_select_joueur2[1]->point_de_vie_courante>=0){
                bot_action_att(attaquant,perso_select_joueur2[1]);
            }
            break;
        case 3:
            if(perso_select_joueur2[3]->point_de_vie_courante>=0){
                bot_action_att(attaquant,perso_select_joueur2[2]);
            }
            break;
        default:
            break;
        }
    }while(x!=1 && x!=2 && x!=3);
}

void bot_select_adversaire_spe1(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int x,y;
    if (strcmpi(attaquant->nom,"Laurie")==0 || strcmpi(attaquant->nom,"Celine")==0){
        do{
            choix_heal(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
            scanf("%d",&x);
            viderclavier();
            switch (x){
            case 1:
                if(perso_select_joueur1[0]->point_de_vie_courante>=0){
                    bot_action_heal_spe1(attaquant,perso_select_joueur1[0]);
                }
                break;
            case 2:
                if(perso_select_joueur1[1]->point_de_vie_courante>=0){
                    bot_action_heal_spe1(attaquant,perso_select_joueur1[1]);
                }
                break;
            case 3:
                if(perso_select_joueur1[2]->point_de_vie_courante>=0){
                    bot_action_heal_spe1(attaquant,perso_select_joueur1[2]);
                }
                break;
            default:
                break;
            }
        }while(x!=1 && x!=2 && x!=3);
    }
    else{
        do{
            choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur2);
            scanf("%d",&x);
            viderclavier();
            switch (x){
            case 1:
                if(perso_select_joueur2[0]->point_de_vie_courante>=0){
                    bot_action_att_spe1(attaquant,perso_select_joueur2[0]);
                }
                break;
            case 2:
                if(perso_select_joueur2[1]->point_de_vie_courante>=0){
                    bot_action_att_spe1(attaquant,perso_select_joueur2[1]);
                }
                break;
            case 3:
                if(perso_select_joueur2[2]->point_de_vie_courante>=0){
                    bot_action_att_spe1(attaquant,perso_select_joueur2[2]);
                }
                break;
            default:
                break;
            }
        }while(x!=1 && x!=2 && x!=3);
    }
}

void bot_select_adversaire_spe2(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int x,y;
    if (strcmpi(attaquant->nom,"Laurie")==0 || strcmpi(attaquant->nom,"Celine")==0){
        do{
            choix_heal(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
            scanf("%d",&x);
            viderclavier();
            switch (x){
                case 1:
                    if(perso_select_joueur1[0]->point_de_vie_courante>=0){
                        bot_action_heal_spe2(attaquant,perso_select_joueur1[0]);
                    }
                    break;
                case 2:
                    if(perso_select_joueur1[1]->point_de_vie_courante>=0){
                        bot_action_heal_spe2(attaquant,perso_select_joueur1[1]);
                    }
                    break;
                case 3:
                    if(perso_select_joueur1[2]->point_de_vie_courante>=0){
                        bot_action_heal_spe2(attaquant,perso_select_joueur1[2]);
                    }
                    break;
                default:
                    break;
            }
        }while(x!=1 && x!=2 && x!=3);
    }
    else{
        do{
            choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur2);
            scanf("%d",&x);
            viderclavier();
            switch (x){
            case 1:
                if(perso_select_joueur2[0]->point_de_vie_courante>=0){
                    bot_action_att_spe2(attaquant,perso_select_joueur2[0]);
                }
                break;
            case 2:
                if(perso_select_joueur2[1]->point_de_vie_courante>=0){
                    bot_action_att_spe2(attaquant,perso_select_joueur2[1]);
                }
                break;
            case 3:
                if(perso_select_joueur2[2]->point_de_vie_courante>=0){
                    bot_action_att_spe2(attaquant,perso_select_joueur2[2]);
                }
                break;
            default:
                break;
            }
        }while(x!=1 && x!=2 && x!=3);
    }
}

void bot_action_att(Personnages *attaquant,Personnages *receveur){
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

void bot_action_att_spe1(Personnages *attaquant,Personnages *receveur){
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

void bot_action_att_spe2(Personnages *attaquant,Personnages *receveur){
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
        printf("%s take %f damage !\n%s have now %d HP !\n",receveur->nom,degat,receveur->nom,(int)receveur->point_de_vie_courante);
        }
    }
    
}

void bot_action_heal_spe1(Personnages *attaquant,Personnages *receveur){
    float heal;
        if(heal > 0 ){
            heal=attaquant->att_spe1->valeur;
            receveur->point_de_vie_courante+=heal;
            printf("%s heals %f HP !\n%s has now %d HP !\n",receveur->nom,heal,receveur->nom,(int)receveur->point_de_vie_courante);
        }
}

void bot_action_heal_spe2(Personnages *attaquant,Personnages *receveur){
    float heal;
    heal=attaquant->att_spe2->valeur;
    receveur->point_de_vie_courante+=heal;
    printf("%s heals %f HP !\n%s has now %d HP !\n",receveur->nom,heal,receveur->nom,(int)receveur->point_de_vie_courante);
}

void bot_fin_combat( Personnages *perso_select_joueur1[3], Personnages *perso_select_joueur2[3]){
    if(perso_select_joueur2[0]->point_de_vie_courante==0 && perso_select_joueur2[1]->point_de_vie_courante==0 && perso_select_joueur2[2]->point_de_vie_courante==0){
        gagnant(perso_select_joueur1);
    }
    else{
        gagnant(perso_select_joueur2);
    }
    exit(0);
}



//ici se trouve les action du bot






void bot_select_actions_bot(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3],int bot){
    do{
        effectuer_action(attaquant,perso_select_joueur1,perso_select_joueur2);
        switch (bot){
        case 1:
            bot_select_adversaire_bot(attaquant,perso_select_joueur1,perso_select_joueur2);
            break;
        case 2:
            bot_select_adversaire_spe1_bot(attaquant,perso_select_joueur1,perso_select_joueur2);
            break;
        case 3:
            bot_select_adversaire_spe2_bot(attaquant,perso_select_joueur1,perso_select_joueur2,bot);
            break;
        case 4:
            bot_select_adversaire_spe2_bot(attaquant,perso_select_joueur1,perso_select_joueur2,bot);
            break;
        default:
            break;
        }
    }while(bot!=1 && bot!=2 && bot!=3 && bot!=4);
}

void bot_select_adversaire_bot(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
    bot_action_att(attaquant,perso_select_joueur1[0]);
}

void bot_select_adversaire_spe1_bot(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    if (strcmpi(attaquant->nom,"Laurie")==0 || strcmpi(attaquant->nom,"Celine")==0){
        choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur2);
        bot_action_heal_spe1(attaquant,perso_select_joueur1[0]);
    }
    else{
        choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
        bot_action_att_spe1(attaquant,perso_select_joueur1[0]);
    }
}

void bot_select_adversaire_spe2_bot(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3],int bot){
    if(bot==3){
        if(strcmpi(attaquant->nom,"Laurie")==0 || strcmpi(attaquant->nom,"Celine")==0){
            choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur2);
            bot_action_heal_spe2(attaquant,perso_select_joueur1[0]);
        }
        else{
            choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
            bot_action_att_spe2(attaquant,perso_select_joueur1[0]);
        }
    }
    else{
        if(strcmpi(attaquant->nom,"Laurie")==0 || strcmpi(attaquant->nom,"Celine")==0){
            choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur2);
            bot_action_heal_spe2(attaquant,perso_select_joueur1[2]);
        }
        else{
            if(perso_select_joueur1[2]->point_de_vie_courante!=0){
                if(strcmpi(perso_select_joueur1[1]->type,"Support")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[1]);
                }
                else if(strcmpi(perso_select_joueur1[2]->type,"Support")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[2]);
                }
                else if(strcmpi(perso_select_joueur1[0]->type,"Assassin")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[0]);
                }
                else if(strcmpi(perso_select_joueur1[1]->type,"Assassin")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[1]);
                }
                else if(strcmpi(perso_select_joueur1[2]->type,"Assassin")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[2]);
                }
                else if(strcmpi(perso_select_joueur1[0]->type,"Mage")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[0]);
                }
                else if(strcmpi(perso_select_joueur1[1]->type,"Mage")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[1]);
                }
                else if(strcmpi(perso_select_joueur1[2]->type,"Mage")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[2]);
                }
                else if(strcmpi(perso_select_joueur1[0]->type,"Warrior")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[0]);
                }
                else if(strcmpi(perso_select_joueur1[1]->type,"Warrior")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[1]);
                }
                else if(strcmpi(perso_select_joueur1[2]->type,"Warrior")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[2]);
                }
                else{
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[0]);
                }
            }
            else if (perso_select_joueur1[1]->point_de_vie_courante==0 && perso_select_joueur1[2]->point_de_vie_courante==0){
                if(strcmpi(perso_select_joueur1[0]->type,"Assassin")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[0]);
                }
                else if(strcmpi(perso_select_joueur1[0]->type,"Mage")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[0]);
                }
                else if(strcmpi(perso_select_joueur1[0]->type,"Warrior")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[0]);
                }
                else{
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[0]);
                }
            }
            else if (perso_select_joueur1[2]->point_de_vie_courante==0){
               if(strcmpi(perso_select_joueur1[1]->type,"Support")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[1]);
                }
                else if(strcmpi(perso_select_joueur1[0]->type,"Assassin")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[0]);
                }
                else if(strcmpi(perso_select_joueur1[1]->type,"Assassin")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[1]);
                }
                else if(strcmpi(perso_select_joueur1[0]->type,"Mage")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[0]);
                }
                else if(strcmpi(perso_select_joueur1[1]->type,"Mage")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[1]);
                }
                else if(strcmpi(perso_select_joueur1[0]->type,"Warrior")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[0]);
                }
                else if(strcmpi(perso_select_joueur1[1]->type,"Warrior")==0){
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[1]);
                }
                else{
                    choix_adversaire(attaquant,perso_select_joueur1,perso_select_joueur2,perso_select_joueur1);
                    bot_action_att_spe2(attaquant,perso_select_joueur1[0]);
                }
            }
        }
    }
}