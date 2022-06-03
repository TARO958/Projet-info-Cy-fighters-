#include <string.h>
#include <stdlib.h>
#include "Personnages.h"
#include "interface.h"
#include "pseudo.h"
#include "dif.h"
#include "combat.h"
#define ELLIAT 22

Personnages tab[NB_Personnages]={
    {.nom = "Adrien",.type = "Tank",.point_de_vie_courante = 700 ,.point_de_vie_maximum =1000 ,.agi=0.3,.att =40,.vit = 20,.def = 0.6},
    {.nom = "Celine",.type = "Soigneuse",.point_de_vie_courante = 250 ,.point_de_vie_maximum =1000 ,.agi=0.8,.att =70,.vit = 90,.def = 0.2},
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

void select_engagement(Personnages perso_select_joueur1[],Personnages perso_select_joueur2[]){
    int vit1[2][3]={0};
    int vit2[2][3]={0};
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
        for(b=i;b<3;b++){
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
printf("%f  %f",perso_select_joueur1[vit1[1][0]],vit1[0][0]);

}

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
    Personnages *perso_select_joueur1[3]={0};
    Personnages *perso_select_joueur2[3]={0};
    for(int i=0;i<3;i++){
        do{
        printf("Joueur 1 : Choix du personnage %d: ",(i+1));
        scanf("%s",recherche);
        perso_select_joueur1[i]=cherche_personnages(recherche);
        if(perso_select_joueur1[i]==NULL){
            printf("Ce nom n'existe pas.");


        }
        }while(perso_select_joueur1[i]==NULL);
    }
    printf("\n");
    for(int j=0;j<3;j++){
        do{
        printf("Joueur 2 : Choix du personnage %d: ",(j+1));
        scanf("%s",recherche);
        perso_select_joueur2[j]=cherche_personnages(recherche);
        if(perso_select_joueur2[j]==NULL){
            printf("Ce nom n'existe pas.");


        }
        }while(perso_select_joueur2[j]==NULL);
    }
    select_engagement(*perso_select_joueur1,*perso_select_joueur2);
}