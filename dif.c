#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 88
#define ELLIAT 22
#include "interface.h"
#include "perso.h"
#include "dif.h"

void viderclavier(){
    for (int c = 0; c!='\n' && c!=EOF; c = getchar());
}

void choisir_dif(){
    int bot;
    do{
        choisir_bot();
        scanf("%d",&bot);
        viderclavier();
        switch (bot){
        case 0:
            choisirnmbjoueur();
            break;
        case 1:
            choisirperso(bot);
            break;
        case 2:
            choisirperso(bot);
            break;
        case 3:
            choisirperso(bot);
            break;
        case 4:
            choisirperso(bot);
            break;
        default:
            printf("entez la difficulté de votre choix.");
            break;
        }
    } while (bot!=0);
}
