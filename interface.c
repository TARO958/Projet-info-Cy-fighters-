#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "pseudo.h"
#include "dif.h"
#include "Personnages.h"
#define TAILLE 88
#define ELLIAT 22

void haut(){
    int i;
    printf(" ");
    for(i=0;i<86;i++){
        printf("_");
    }
    printf(" ");
    printf("\n");
}

void bas(){
    printf("|");
    for(int i=0;i<86;i++){
        printf("_");
    }
    printf("|");
    printf("\n");
}

void bas2(){
    printf("|");
    for(int i=0;i<86;i++){
        if (i==43){
            printf("|");
        }
        else
        printf("_");
    }
    printf("|");
    printf("\n");
}

void cadre(){
    printf("|%87s", "|");
    printf("\n");
}

void ecrire_ligne(char chaine[], int len_chaine) {
    int decalage = (TAILLE - len_chaine) / 2;
    printf("%-*s", decalage, "|");
    if (len_chaine % 2 == 0) 
    {
        printf("%s", chaine);
    } else {
        printf("%s ", chaine);
    }
    printf("%*s", decalage, "|");
    printf("\n");
}

void barre_m(){
    int i=TAILLE/2;
    printf("%-*s",i,"|");
    printf("%-*s",i-1,"|");
    printf("%s","|");
    printf("\n");
}

void ecrire_ligne_mdg(char chaine[], int len_chaine,char chaine2[], int dec2){
    int decalage = (44 - len_chaine)/2;
    int decalage2 =(44 - dec2)/2;
    printf("%-*s", decalage, "|");
    if(len_chaine%2==1){
        printf("%-*s", decalage+len_chaine+1, chaine);
    }
    else{
    printf("%-*s", decalage+len_chaine, chaine);
    }
    printf("%-*s", decalage2, "|");
    if(dec2%2==1){
        printf("%s%*s", chaine2, decalage2+1, "|");
    }
    else{
    printf("%s%*s", chaine2, decalage2, "|");
    }
    printf("\n");
}

void ecrire_ligne_gauche(char chaine[], int len_chaine) {  
    printf("|%s", chaine);
    printf("%*s", TAILLE-len_chaine-1, "|");
    printf("\n");
}

void ecrire_ligne_droite(char chaine[]) {
    printf("|%*s|", TAILLE-2, chaine);
    printf("\n");
}

void ecrire_ligne_droite_gauche(char chaine[], int len_chaine, char chaine2[]) {
    printf("|%s%*s|", chaine, TAILLE-2-len_chaine, chaine2);
    printf("\n");
}



void list_perso1(){
    int x;
    do{
        haut();
        ecrire_ligne("enter '1' if u want to select the character",43);
        bas();
        for (int i=0;i<ELLIAT;i++){
            if(i==1){
                ecrire_ligne_mdg("ADRIEN",6,"CELINE",6);
            }
            else if(i==3){
                ecrire_ligne_mdg("type : Tank",11,"type : Support",14);
            }
            else if(i==4){
                ecrire_ligne_mdg("Pv : 700",8,"pv : 250",8);
            }
            else if(i==5){
                ecrire_ligne_mdg("att : 40",8,"att : 70",8);
            }
            else if(i==6){
                ecrire_ligne_mdg("def : 0.60",10,"def : 0.20",10);
            }
            else if(i==7){
                ecrire_ligne_mdg("vit : 20",8,"vit : 90",8);
            }
            else if(i==8){
                ecrire_ligne_mdg("agi : 0.30",10,"agi : 0.80",10);
            }
            else if(i==9){
                ecrire_ligne_mdg("ult : ",6,"ult : ",6);
            }
            else if(i==11){
                bas2();
            }
            else if(i==13){
                ecrire_ligne_mdg("PETER",5,"LUCAS",5);
            }
            else if(i==15){
                ecrire_ligne_mdg("type : Mage",11,"type : Tank",11);
            }
            else if(i==16){
                ecrire_ligne_mdg("Pv : 500",8,"pv : 750",8);
            }
            else if(i==17){
                ecrire_ligne_mdg("att : 50",8,"att : 30",8);
            }
            else if(i==18){
                ecrire_ligne_mdg("def : 0.50",10,"def : 0.65",10);
            }
            else if(i==19){
                ecrire_ligne_mdg("vit : 50",8,"vit : 15",8);
            }
            else if(i==20){
                ecrire_ligne_mdg("agi : 0.50",10,"agi : 0.20",10);
            }
            else if(i==21){
                ecrire_ligne_mdg("ult : ",6,"ult : ",6);
            }
            else{
                barre_m();
            }
        }
        bas2();
        ecrire_ligne("page 1",6);
        ecrire_ligne_droite_gauche("'0'Previous page",16,"'2'Next page");
        bas();
        scanf("%d",&x);
        viderclavier();
        switch(x){
            case 0:
                list_perso3();
                break;
            case 1:
                select_perso();
                break;
            case 2:
                list_perso2();
            default:
                break;
        }
    } while (x != 0);  
}

void list_perso3(){
    int x;
    do{
        haut();
        ecrire_ligne("enter '1' if u want to select the character",43);
        bas();
        for (int i=0;i<ELLIAT;i++){
            if(i==1){
                ecrire_ligne_mdg("LAURIE",6,"THEO",4);
            }
            else if(i==3){
                ecrire_ligne_mdg("type : Support",14,"type : Warrior",14);
            }
            else if(i==4){
                ecrire_ligne_mdg("Pv : 550",8,"pv : 350",8);
            }
            else if(i==5){
                ecrire_ligne_mdg("att : 60",8,"att : 60",8);
            }
            else if(i==6){
                ecrire_ligne_mdg("def : 0.40",10,"def : 0.90",10);
            }
            else if(i==7){
                ecrire_ligne_mdg("vit : 30",8,"vit : 60",8);
            }
            else if(i==8){
                ecrire_ligne_mdg("agi : 0.50",10,"agi : 0.50",10);
            }
            else if(i==9){
                ecrire_ligne_mdg("ult : ",6,"ult : ",6);
            }
            else if(i==11){
                bas2();
            }
            else if(i==13){
                ecrire_ligne_mdg("EVAN",4,"ENZO",4);
            }
            else if(i==15){
                ecrire_ligne_mdg("type : Warrior",14,"type : Assassin",15);
            }
            else if(i==16){
                ecrire_ligne_mdg("Pv : 450",8,"pv : 250",8);
            }
            else if(i==17){
                ecrire_ligne_mdg("att : 60",8,"att : 60",8);
            }
            else if(i==18){
                ecrire_ligne_mdg("def : 0.10",10,"def : 0.50",10);
            }
            else if(i==19){
                ecrire_ligne_mdg("vit : 20",8,"vit : 10",8);
            }
            else if(i==20){
                ecrire_ligne_mdg("agi : 0.50",10,"agi : 0.50",10);
            }
            else if(i==21){
                ecrire_ligne_mdg("ult : ",6,"ult : ",6);
            }
            else{
                barre_m();
            }
        }
        bas2();
        ecrire_ligne("page 3",6);
        ecrire_ligne_droite_gauche("'0'Previous page",16,"'2'Next page");
        bas();
        scanf("%d",&x);
        viderclavier();
        switch(x){
            case 0:
                list_perso2();
                break;
            case 1:
                select_perso();
                break;
            case 2:
                list_perso1();
            default:
                break;
        }
    } while (x != 0);
}

void choix_nom(){
    haut();
    for (int i=0;i<ELLIAT;i++){
        if(i==2){
            ecrire_ligne("Choose your nickname",20);
        }
        else if(i==4){
            bas();
        }
        else if(i==12){
            ecrire_ligne("You will type your",18);
        }
        else if(i==14){
            ecrire_ligne("nickname! each in turn",22);
        }
        else{
            cadre();
        }
    }
    bas();
}

void fin_choix(char nom1[25],char nom2[25],int y,int z){
    haut();
    for (int i=0;i<ELLIAT;i++){
        if(i==2){
            ecrire_ligne("Enter '1' to continue",21);
        }
        else if(i==4){
            bas();
        }
        else if(i==10){
            ecrire_ligne_mdg("Team 1 :",8,"Team 2 :",8);
        }
        else if(i==12){
            ecrire_ligne_mdg(nom1,y,nom2,z);
        }
        else if(i==17){
            bas2();
        }
        else if(i==20){
            ecrire_ligne("Enter '0' to go back to player selection",40);
        }
        else if(i>4 && i<17){
            barre_m();
        }
        else{
            cadre();
        }
    }
    bas();
}

void choisir_bot(){
    haut();
    for (int i=0;i<ELLIAT;i++){
        if(i==0){
            ecrire_ligne("Choose the difficulty of the bot",32);
        }
        else if(i==1){
            bas();
        }
        else if(i==5){
            ecrire_ligne_mdg("Type '1' to play",16,"Type '2' to play",16);
        }
        else if(i==6){
            ecrire_ligne_mdg("on",2,"on",2);
        }
        else if(i==7){
            ecrire_ligne_mdg("noob",4,"easy",4);
        }
        else if(i==10){
            bas2();
        }
        else if(i==14){
            ecrire_ligne_mdg("Type '3' to play",16,"Type '4' to play",16);
        }
        else if(i==15){
            ecrire_ligne_mdg("on",2,"on",2);
        }
        else if(i==16){
            ecrire_ligne_mdg("normal",6,"hard",4);
        }
        else if(i==20){
            bas2();
        }
        else if(i==21){
            ecrire_ligne("Enter '0' to go back",20);
        }
        else{
            barre_m();
        }
    }
    bas();
}

void nombrejoueur(){
    haut();
    for (int i=0;i<ELLIAT;i++){
        if(i==5){
            ecrire_ligne("Enter '2' if you are 2 players and '1' if you are alone",55);
        }
        else if(i==10){
            bas();
        }
        else if(i==14){
            ecrire_ligne_mdg("Play with ",10,"Play against",12);
        }
        else if(i==16){
            ecrire_ligne_mdg("ur friend!",10,"bot!",4);
        }
        else if(i==18){
            ecrire_ligne_mdg("for lot of fun",14,"with many difficulty",20);
        }
        else if(i>10){
            barre_m();
        }
        else{
            cadre();
        }
    }
    bas2();
}

void startgame(){
    haut();
    for(int i=0;i<ELLIAT;i++){
        if(i==0){
            ecrire_ligne_droite_gauche("CY-Tech",7,"Multiplayer/Solo");
        }
        else if(i==8){
            ecrire_ligne("CY  FIGHTERS",12);
        }
        else if(i==11){
            ecrire_ligne("Enter '1' to start",18);
        }
        else if(i==20){
            ecrire_ligne_gauche("Evan Gobe-Truong",16);
        }
        else if(i==21){
            ecrire_ligne_gauche("Samuel Zerrouk",14);
        }
        else{
            cadre();
        }   
    }
    bas();
}