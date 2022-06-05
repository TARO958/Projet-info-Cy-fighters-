#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 88
#define ELLIAT 22
#include "interface.h"
#include "pseudo.h"
#include "dif.h"
#include "Personnages.h"
#include "combat.h"
#include "bot.h"

void choisirnmbjoueur(){
    int nmb;
    do{
        nombrejoueur();     //affichage
        scanf("%d",&nmb);
        viderclavier();
    } while (nmb != 1 && nmb != 2);
    if(nmb==1){
        choisir_dif();
    }
    else{
        pseudoj();
    }
}

void debut(){
    int start;
    startgame();            //affichage
    scanf("%d",&start);
    viderclavier();     //fonction qui regle les problemes de scanf
    if(start!=1){
        exit(0);
    }
    choisirnmbjoueur();
}

int main(){
    debut();

return 0;
}