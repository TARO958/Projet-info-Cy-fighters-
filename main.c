#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 88
#define ELLIAT 22
#include "interface.h"
#include "perso.h"
#include "dif.h"

// Fonction pour choisir le nombre de joueurs
void choisirnmbjoueur(){
    int nmb;
    do{
        nombrejoueur();
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
    startgame();
    scanf("%d",&start);
    viderclavier();
    if(start!=1){
        exit(0);
    }
    choisirnmbjoueur();
}

int main(){
    debut();

return 0;
}