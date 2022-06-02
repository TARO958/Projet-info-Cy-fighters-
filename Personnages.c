#include <string.h>
#include <stdlib.h>
#include "Personnages.h"
#include "interface.h"
#include "pseudo.h"
#include "dif.h"
#define ELLIAT 22

Personnages tab[NB_Personnages]={
    {.nom = "Adrien",.type = "Tank",.point_de_vie_courante = 700 ,.point_de_vie_maximum =1000 ,.agi=0.3,.att =40,.vit = 20,.def = 0.6},
    {.nom = "Céline",.type = "Soigneuse",.point_de_vie_courante = 250 ,.point_de_vie_maximum =1000 ,.agi=0.8,.att =70,.vit = 90,.def = 0.2},
    {.nom = "Peter",.type = "Mage",.point_de_vie_courante = 500 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =50,.vit = 50,.def = 0.5},
    {.nom = "Lucas",.type = "Tank",.point_de_vie_courante = 750 ,.point_de_vie_maximum =1000 ,.agi=0.2,.att =30,.vit = 15,.def = 0.65},
    {.nom = "Samuel",.type = "Assasins",.point_de_vie_courante = 250 ,.point_de_vie_maximum =1000 ,.agi=0.4,.att =90,.vit = 60,.def = 0.1},
    {.nom = "Thibaut",.type = "Tank",.point_de_vie_courante = 800 ,.point_de_vie_maximum =1000 ,.agi=0.15,.att =20,.vit = 40,.def = 0.8},
    {.nom = "Sabrina",.type = "Assasins",.point_de_vie_courante = 500 ,.point_de_vie_maximum =1000 ,.agi=0.1,.att =80,.vit = 50,.def = 0.6},
    {.nom = "Léa",.type = "Mage",.point_de_vie_courante = 150 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 30,.def = 0.4},
    {.nom = "Laurie",.type = "Soigneuse",.point_de_vie_courante = 550 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 80,.def = 0.2},
    {.nom = "Theo",.type = "Gueurrier",.point_de_vie_courante = 350 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 60,.def = 0.9},
    {.nom = "Evan",.type = "Gueurrier",.point_de_vie_courante = 450 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 20,.def = 0.1},
    {.nom = "Enzo",.type = "Assasins",.point_de_vie_courante = 250 ,.point_de_vie_maximum =1000 ,.agi=0.5,.att =60,.vit = 10,.def = 0.5},

};

void list_perso2(){
    int x;
    do{
    haut();
    ecrire_ligne("enter '1' if u want to select the character",43);
    bas();
    for (int i=0;i<ELLIAT;i++){
        if(i==1){
            ecrire_ligne_mdg("SAMUEL",6,"THIBAUT",7);
        }
        else if(i==3){
            ecrire_ligne_mdg("type : Assassin",15,"type : Tank",11);
        }
        else if(i==4){
            ecrire_ligne_mdg("Pv : 250",8,"pv : 800",8);
        }
        else if(i==5){
            ecrire_ligne_mdg("att : 90",8,"att : 20",8);
        }
        else if(i==6){
            ecrire_ligne_mdg("def : 0.10",10,"def : 0.80",10);
        }
        else if(i==7){
            ecrire_ligne_mdg("vit : 60",8,"vit : 40",8);
        }
        else if(i==8){
            ecrire_ligne_mdg("agi : 0.40",10,"agi : 0.15",10);
        }
        else if(i==9){
            ecrire_ligne_mdg("ult : ",6,"ult : ",6);
        }
        else if(i==11){
            bas2();
        }
        else if(i==13){
            ecrire_ligne_mdg("SABRINA",7,"LEA",3);
        }
        else if(i==15){
            ecrire_ligne_mdg("type : Assassin",15,"type : Mage",11);
        }
        else if(i==16){
            ecrire_ligne_mdg("Pv : 500",8,"pv : 150",8);
        }
        else if(i==17){
            ecrire_ligne_mdg("att : 80",8,"att : 60",8);
        }
        else if(i==18){
            ecrire_ligne_mdg("def : 0.60",10,"def : 0.40",10);
        }
        else if(i==19){
            ecrire_ligne_mdg("vit : 50",8,"vit : 30",8);
        }
        else if(i==20){
            ecrire_ligne_mdg("agi : 0.10",10,"agi : 0.50",10);
        }
        else if(i==21){
            ecrire_ligne_mdg("ult : ",6,"ult : ",6);
        }
        else{
            barre_m();
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
    } while (x != 0);
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
    char recherche[10];
    Personnages *perso_select[6];
    for(int i=0;i<6;i++){
        do{
        scanf("%s",recherche);
        perso_select[i]=cherche_personnages(recherche);
        }while(perso_select[i]==NULL);
    }

}