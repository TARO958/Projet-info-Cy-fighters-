#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"
#include "perso.h"
#include "dif.h"
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
    printf("%-*s", decalage+len_chaine, chaine);
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
            ecrire_ligne_mdg("J1 :",4,"J2 :",4);
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