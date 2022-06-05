#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 88
#define ELLIAT 22
#include "pseudo.h"
#include "interface.h"
#include "dif.h"

void pseudoj(){     
    char nom1[25];
    char nom2[25];
    int x;
    int y,z;
    do{
        choix_nom();
        do{
            scanf("%s",nom1);
            y=strlen(nom1);
            if(y%2==1){
                y++;
            }
            viderclavier();
            scanf("%s",nom2);
            z=strlen(nom2);
            viderclavier();
            if(y>25 || z>25){
                printf("error your nickname can't be that long, try with another one shorter\n");
            }
        } while (y>25 || z>25);
        fin_choix(nom1,nom2,y,z);
        scanf("%d",&x);
        switch(x){
        case 0:
            choisirnmbjoueur();
            break;
        case 1:
            list_perso1();
            break;
        default:
            break;
        }
    } while (x != 0);
}