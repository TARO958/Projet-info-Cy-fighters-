#include <string.h>
#include <stdlib.h>
#include "Personnages.h"
#include "interface.h"
#include "pseudo.h"
#include "dif.h"
#include "combat.h"
#define ELLIAT 22
Speciales spe[NB_ATT_SPE]={
    {.nom = "charge",.valeur = 40 ,.description = "fonce droit sur l'ennemie en infligeant des dégats "  ,.nb_tours_actifs = 1,.nb_tours_rechargement=2},
    {.nom = "boule magique",.valeur = 70 , .description = "infligle des dégats sur un adversaire" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "boule de feu",.valeur =75,.description ="lance une boule de feu et brule l'énnemie pendart 2 tours"  ,.nb_tours_actifs =2 ,.nb_tours_rechargement=2},
    {.nom = "lancer de shurikens",.valeur = 125 ,.description = "lance un shurikens" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "soin miraculeux ",.valeur = 35,.description = "géle l'adversaire" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=10},
    {.nom = "soin magique",.valeur = 999 ,.description = "tranche" ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "protection",.valeur = 0.25,.description ="renforce la def du personnage de 0.25 "   ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "tourbillon",.valeur = 150 ,.description = "tourne rapidement sur soi-même avec l'épée en main " ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "griffe",.valeur = 90,.description =  "griffe l'adversaire",.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "tempete",.valeur = 25 , .description ="lance une tempête sur l'équipe ennemie qui touche tout les personnages pendant 3 tours"  ,.nb_tours_actifs =3 ,.nb_tours_rechargement=2},
    {.nom = "",.valeur = 25,.description = "lance une grenade" ,.nb_tours_actifs = 2,.nb_tours_rechargement=2},
    {.nom = "foudre",.valeur =25 ,.description = "lance un éclair " ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "pas de côté",.valeur  = 15 ,.description = "augmente l'agilite du personnage" ,.nb_tours_actifs = 1 ,.nb_tours_rechargement =2 },
    {.nom = "soin magique",.valeur =25,.description =  "",.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "soin miraculeux ",.valeur =25,.description =""  ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "poing ardent",.valeur = 25 , .description = "brule l'quipe adversaire pendant 2 tours" ,.nb_tours_actifs =2 ,.nb_tours_rechargement=2},
    {.nom = "crocs",.valeur = 25,.description ="mord l'adversaire"  ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "voile protecteur",.valeur = 25,.description ="augemente la def de toute l'quipe de 20% du personnage qui l'utilise"  ,.nb_tours_actifs =1,.nb_tours_rechargement=2},
    {.nom = "fumigene",.valeur = 25,.description = "le personnage devient impossible a ciblé pendant 3 tours mais il ne peut pas attaquer au tour suivant "  ,.nb_tours_actifs =1,.nb_tours_rechargement=2},
    {.nom = "mur de terre ",.valeur =25,.description = ""  ,.nb_tours_actifs =1,.nb_tours_rechargement=2},
    {.nom = "smash",.valeur =25,.description = "infligle des dégats  sur trois adversaires" ,.nb_tours_actifs =1,.nb_tours_rechargement=2},
    {.nom = "",.valeur = 25, .description =""  ,.nb_tours_actifs =1 ,.nb_tours_rechargement=2},
    {.nom = "lance grenade",.valeur = 25,.description = "lili" ,.nb_tours_actifs = 2,.nb_tours_rechargement=2},
    {.nom = "profonde entaille",.valeur =25 ,.description ="fais saigner l'adversaire pendant 2 tours" ,.nb_tours_actifs =2,.nb_tours_rechargement=2},
};
Personnages tab[NB_Personnages]={
    {.nom = "Anton",.type = "Tank",.point_de_vie_courante = 700 ,.point_de_vie_maximum =1000 ,.agi=0.3,.att =40,.vit = 50,.def = 0.6,.att_spe1=&spe[0]},
    {.nom = "Celine",.type = "Soigneuse",.point_de_vie_courante = 250 ,.point_de_vie_maximum =1000 ,.agi=0.8,.att =70,.vit = 20,.def = 0.2},
    {.nom = "Peter",.type = "Mage",.point_de_vie_courante = 500 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =50,.vit = 30,.def = 0.5},
    {.nom = "Lucas",.type = "Tank",.point_de_vie_courante = 750 ,.point_de_vie_maximum =1000 ,.agi=0.2,.att =30,.vit = 45,.def = 0.65},
    {.nom = "Samuel",.type = "Assassin",.point_de_vie_courante = 250 ,.point_de_vie_maximum =1000 ,.agi=0.4,.att =90,.vit = 99,.def = 0.1},
    {.nom = "Thibaut",.type = "Tank",.point_de_vie_courante = 800 ,.point_de_vie_maximum =1000 ,.agi=0.15,.att =20,.vit = 40,.def = 0.8},
    {.nom = "Sabrina",.type = "Assassin",.point_de_vie_courante = 500 ,.point_de_vie_maximum =1000 ,.agi=0.1,.att =80,.vit = 90,.def = 0.6},
    {.nom = "Lea",.type = "Mage",.point_de_vie_courante = 150 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 35,.def = 0.4},
    {.nom = "Laurie",.type = "Soigneuse",.point_de_vie_courante = 550 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 10,.def = 0.2},
    {.nom = "Theo",.type = "Guerrier",.point_de_vie_courante = 350 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 80,.def = 0.9},
    {.nom = "Evan",.type = "Guerrier",.point_de_vie_courante = 450 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 85,.def = 0.1},
    {.nom = "Enzo",.type = "Assassin",.point_de_vie_courante = 250 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 95,.def = 0.5},
};
void list_perso2(){
    int x;
    do{
    haut();
    ecrire_ligne("CHARACTER LIST",14);
    ecrire_ligne("Type '1' to go to the character selection",41);
    bas();
    for (int i=0;i<ELLIAT;i++){
        switch (i){
            case 1:
                ecrire_ligne_mdg("SAMUEL",6,"THIBAUT",7);
                break;
            
            case 3:
                ecrire_ligne_mdg("type : Assassin",15,"type : Tank",11);
            
            case 4:
                ecrire_ligne_mdg("Pv : 250",8,"pv : 800",8);
                break;
            case 5:
                ecrire_ligne_mdg("att : 90",8,"att : 20",8);
                break;
            case 6:
                ecrire_ligne_mdg("def : 0.10",10,"def : 0.80",10);
                break;
            case 7:
                ecrire_ligne_mdg("vit : 99",8,"vit : 40",8);
                break;
            case 8:
                ecrire_ligne_mdg("agi : 0.40",10,"agi : 0.15",10);
                break;
            case 9:
                ecrire_ligne_mdg("ult : ",6,"ult : ",6);
                break;
            case 11:
                bas2();
                break;
            case 13:
                ecrire_ligne_mdg("SABRINA",7,"LEA",3);
                break;
            case 15:
                ecrire_ligne_mdg("type : Assassin",15,"type : Mage",11);
                break;
            case 16:
                ecrire_ligne_mdg("Pv : 500",8,"pv : 150",8);
                break;
            case 17:
                ecrire_ligne_mdg("att : 80",8,"att : 60",8);
                break;
            case 18:
                ecrire_ligne_mdg("def : 0.60",10,"def : 0.40",10);
                break;
            case 19:
                ecrire_ligne_mdg("vit : 90",8,"vit : 35",8);
                break;
            case 20:
                ecrire_ligne_mdg("agi : 0.10",10,"agi : 0.50",10);
                break;
            case 21:
                ecrire_ligne_mdg("ult : ",6,"ult : ",6);
                break;
            default:
                barre_m();
                break;
        }
    }
    bas2();
    ecrire_ligne("page 2",6);
    ecrire_ligne_droite_gauche("'0'Previous page",16,"'2'Next page");
    bas();
    scanf("%d",&x);
    viderclavier();
    switch(x){
        case 0:
            list_perso1();
            break;
        case 1:
            select_perso();
            break;
        case 2:
            list_perso3();
        default:
            break;
        }
    }while(x!=0);
}

 Personnages *cherche_personnages(char *nom_personnages){
    for(int i=0;i<NB_Personnages;i++){
        if(strcmpi(tab[i].nom,nom_personnages)==0){
            

            return &tab[i];
        }
    }
    return NULL;
}

void select_perso(){
    char recherche[20];
    int trouve;
    Personnages *perso_select_joueur1[3];
    Personnages *perso_select_joueur2[3];
    selection();
    for(int i=0;i<3;i++){
        do{
            trouve=0;
            printf("Player 1 : character %d: ",(i+1));
            scanf("%s",recherche);
            perso_select_joueur1[i]=cherche_personnages(recherche);
            if(perso_select_joueur1[i]==NULL){
                printf("Error, this character doesn't exist.\n");
            }
            else{
                for(int j=0;j<i;j++){
                    if(perso_select_joueur1[j]==perso_select_joueur1[i]){
                        trouve=1;
                    }
                }
                if(trouve){
                    printf("This character is already taken.\n");
                    perso_select_joueur1[i]=NULL;
                }
                else{
                    printf("%s\n",perso_select_joueur1[i]->nom);
                }
            }
        }while(perso_select_joueur1[i]==NULL);
    }
    for(int j=0;j<3;j++){
        do{
            trouve=0;
            printf("Player 2 : character %d: ",(j+1));
            scanf("%s",recherche);
            perso_select_joueur2[j]=cherche_personnages(recherche);
            if(perso_select_joueur2[j]==NULL){
                printf("Error, this character doesn't exist.\n");
            }
            else{
                for(int i=0;i<j;i++){
                    if(perso_select_joueur2[j]==perso_select_joueur2[i]){
                        trouve=1;
                    }
                }
                for(int i=0;i<3;i++){
                    if(perso_select_joueur2[j]==perso_select_joueur1[i]){
                        trouve=1;
                    }
                }
                if(trouve){
                    printf("This character is already taken.\n");
                    perso_select_joueur2[j]=NULL;
                }
                else{
                    printf("%s\n",perso_select_joueur2[j]->nom);
                }
            }
        }while(perso_select_joueur2[j]==NULL);
    }
    Personnages *ordre[6];
    trifusion(perso_select_joueur1,perso_select_joueur2,ordre);
}