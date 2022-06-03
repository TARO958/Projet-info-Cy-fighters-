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

void ecrire_ligne_dg(char chaine[], int len_chaine,char chaine2[], int dec2){
    int decalage = (44 - len_chaine)/2;
    int decalage2 =(44 - dec2)/2;
    printf("%-*s", decalage, "|");
    if(len_chaine%2==1){
        printf("%-*s", decalage+len_chaine+1, chaine);
    }
    else{
    printf("%-*s", decalage+len_chaine, chaine);
    }
    printf("%-*s", decalage2, " ");
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






void selection(){
    haut();
    for (int i=0;i<ELLIAT;i++){
        switch (i){
        case 2:
            ecrire_ligne("CHARACTER SELECTION",19);
            break;
        case 4:
            ecrire_ligne("Type the name of the character you want to play",47);
            break;
        case 5:
            ecrire_ligne("You can choose 3 characters in each team",40);
            break;
        case 7:
            bas();
            break;
        case 10:
            ecrire_ligne_dg("Anton",5,"Celine",6);
            break;
        case 12:
            ecrire_ligne_dg("Peter",5,"Lucas",5);
            break;
        case 14:
            ecrire_ligne_dg("Samuel",6,"Thibaut",7);
            break;
        case 16:
            ecrire_ligne_dg("Sabrina",7,"Lea",3);
            break;
        case 18:
            ecrire_ligne_dg("Laurie",6,"Theo",4);
            break;
        case 20:
            ecrire_ligne_dg("Evan",4,"Enzo",4);
            break;
        default:

            cadre();
            break;
        }
    }
    bas();
}

void list_perso1(){
    int x;
    do{
        haut();
        ecrire_ligne("CHARACTER LIST",14);
        ecrire_ligne("Type '1' to go to the character selection",41);
        bas();
        for (int i=0;i<ELLIAT;i++){
            switch (i){
            case 1:
                ecrire_ligne_mdg("ANTON",5,"CELINE",6);
                break;
            case 3:
                ecrire_ligne_mdg("type : Tank",11,"type : Support",14);
                break;
            case 4:
                ecrire_ligne_mdg("Pv : 700",8,"pv : 250",8);
                break;
            case 5:
                ecrire_ligne_mdg("att : 40",8,"att : 70",8);
                break;
            case 6:
                ecrire_ligne_mdg("def : 0.60",10,"def : 0.20",10);
                break;
            case 7:
                ecrire_ligne_mdg("vit : 20",8,"vit : 90",8);
                break;
            case 8:
                ecrire_ligne_mdg("agi : 0.30",10,"agi : 0.80",10);
                break;
            case 9:
                ecrire_ligne_mdg("ult : ",6,"ult : ",6);
                break;
            case 11:
                bas2();
                break;
            case 13:
                ecrire_ligne_mdg("PETER",5,"LUCAS",5);
                break;
            case 15:
                ecrire_ligne_mdg("type : Mage",11,"type : Tank",11);
                break;
            case 16:
                ecrire_ligne_mdg("Pv : 500",8,"pv : 750",8);
                break;
            case 17:
                ecrire_ligne_mdg("att : 50",8,"att : 30",8);
                break;
            case 18:
                ecrire_ligne_mdg("def : 0.50",10,"def : 0.65",10);
                break;
            case 19:
                ecrire_ligne_mdg("vit : 50",8,"vit : 15",8);
                break;
            case 20:
                ecrire_ligne_mdg("agi : 0.50",10,"agi : 0.20",10);
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
    }while(x!=0);  
}

void list_perso3(){
    int x;
    do{
        haut();
        ecrire_ligne("CHARACTER LIST",14);
        ecrire_ligne("Type '1' to go to the character selection",41);
        bas();
        for (int i=0;i<ELLIAT;i++){
            switch (i){
            case 1:
                ecrire_ligne_mdg("LAURIE",6,"THEO",4);
                break;
            case 3:
                ecrire_ligne_mdg("type : Support",14,"type : Warrior",14);
                break;
            case 4:
                ecrire_ligne_mdg("Pv : 550",8,"pv : 350",8);
                break;
            case 5:
                ecrire_ligne_mdg("att : 60",8,"att : 60",8);
                break;
            case 6:
                ecrire_ligne_mdg("def : 0.40",10,"def : 0.90",10);
                break;
            case 7:
                ecrire_ligne_mdg("vit : 30",8,"vit : 60",8);
                break;
            case 8:
                ecrire_ligne_mdg("agi : 0.50",10,"agi : 0.50",10);
                break;
            case 9:
                ecrire_ligne_mdg("ult : ",6,"ult : ",6);
                break;
            case 11:
                bas2();
                break;
            case 13:
                ecrire_ligne_mdg("EVAN",4,"ENZO",4);
                break;
            case 15:
                ecrire_ligne_mdg("type : Warrior",14,"type : Assassin",15);
                break;
            case 16:
                ecrire_ligne_mdg("Pv : 450",8,"pv : 250",8);
                break;
            case 17:
                ecrire_ligne_mdg("att : 60",8,"att : 60",8);
                break;
            case 18:
                ecrire_ligne_mdg("def : 0.10",10,"def : 0.50",10);
                break;
            case 19:
                ecrire_ligne_mdg("vit : 20",8,"vit : 10",8);
                break;
            case 20:
                ecrire_ligne_mdg("agi : 0.50",10,"agi : 0.50",10);
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
    }while(x!=0);
}

void choix_nom(){
    haut();
    for (int i=0;i<ELLIAT;i++){
        switch (i){
        case 2:
            ecrire_ligne("Choose your nickname",20);
            break;
        case 4:
            bas();
            break;
        case 12:
            ecrire_ligne("You will type your",18);
            break;
        case 14:
            ecrire_ligne("nickname each in turn",21);
            break;
        default:
            cadre();
            break;
        }
    }
    bas();
}

void fin_choix(char nom1[25],char nom2[25],int y,int z){
    haut();
    for (int i=0;i<ELLIAT;i++){
        if(i==2){
            ecrire_ligne("Type '1' to continue",20);
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
            ecrire_ligne("Type '0' to go back to player selection",39);
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
        switch (i){
        case 0:
            ecrire_ligne("Choose the difficulty of the bot",32);
            break;
        case 1:
            bas();
            break;
        case 5:
            ecrire_ligne_mdg("Type '1'",8,"Type '2'",8);
            break;
        case 6:
            ecrire_ligne_mdg("for",3,"for",3);
            break;
        case 7:
            ecrire_ligne_mdg("a noob bot",10,"an easy bot",11);
            break;
        case 10:
            bas2();
            break;
        case 14:
            ecrire_ligne_mdg("Type '3'",8,"Type '4'",8);
            break;
        case 15:
            ecrire_ligne_mdg("for",3,"for",3);
            break;
        case 16:
            ecrire_ligne_mdg("a normal bot",12,"a hard bot",10);
            break;
        case 20:
            bas2();
            break;
        case 21:
            ecrire_ligne("Type '0' to go back",19);
            break;
        default:
            barre_m();
            break;
        }
    }
    bas();
}

void nombrejoueur(){
    haut();
    for (int i=0;i<ELLIAT;i++){
        if(i==5){
            ecrire_ligne("Type '2' if you are 2 players and '1' if you are alone",54);
        }
        else if(i==10){
            bas();
        }
        else if(i==14){
            ecrire_ligne_mdg("Play with ",10,"Play against",12);
        }
        else if(i==16){
            ecrire_ligne_mdg("your friend!",12,"a bot!",6);
        }
        else if(i==18){
            ecrire_ligne_mdg("for a lot of fun",16,"with many difficulties",22);
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
        switch (i){
        case 0:
            ecrire_ligne_droite_gauche("CY-Tech",7,"Multiplayer/Solo");
            break;
        case 8:
            ecrire_ligne("CY  FIGHTERS",12);
            break;
        case 11:
            ecrire_ligne("Type '1' to start",17);
            break;
        case 20:
            ecrire_ligne_gauche("Evan Gobe-Truong",16);
            break;
        case 21:
            ecrire_ligne_gauche("Samuel Zerrouk",14);
            break;
        default:
            cadre();
            break;
        }
    }
    bas();
}