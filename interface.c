#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

void barre_m(){
    int i=TAILLE/2;
    printf("%-*s",i,"|");
    printf("%-*s",i-1,"|");
    printf("%s","|");
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

void ecrire_ligneint(int att, int len_chaine) {
    if(att<100){
        len_chaine=11;
    }
    else if(att<10){
        len_chaine=12;
    }
    int decalage = (TAILLE - len_chaine) / 2;
    printf("%-*s", decalage, "|");
    if (len_chaine % 2 == 0) 
    {
        printf("Damage : %d", att);
    } else {
        printf("Damage : %d ", att);
    }
    printf("%*s", decalage, "|");
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

void ecrire_ligne_mdgint(float hp, int len_chaine,float hp2, int dec2){
    if(hp<100){
        len_chaine=2;
    }
    else if(hp<10){
        len_chaine=1;
    }
    if(hp2<100){
        dec2=2;
    }
    if(hp2<10){
        dec2=1;
    }
    int decalage = (44 - len_chaine)/2;
    int decalage2 =(44 - dec2)/2;
    printf("%-*s", decalage, "|");
    if(len_chaine%2==1){
        printf("%-*d", decalage+len_chaine+1,(int)hp);
    }
    else{
    printf("%-*d", decalage+len_chaine, (int)hp);
    }
    printf("%-*s", decalage2, "|");
    if(dec2%2==1){
        printf("%d%*s ", (int)hp2, decalage2+1, "|");
    }
    else{
    printf("%d%*s", (int)hp2, decalage2, "|");
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




void gagnant(Personnages *gagnant[3]){
    int a,b,c;
    a=strlen(gagnant[0]->nom);
    b=strlen(gagnant[1]->nom);
    c=strlen(gagnant[2]->nom);
    haut();
    for (int i=0;i<ELLIAT;i++){
        switch (i){
        case 3:
            ecrire_ligne("CY Fighters",11);
            break;
        case 7:
            ecrire_ligne("The winners are :",17);
            break;
        case 9:
            ecrire_ligne(gagnant[0]->nom,a);
            break;
        case 10:
            ecrire_ligne(gagnant[1]->nom,b);
            break;
        case 11:
            ecrire_ligne(gagnant[2]->nom,c);
            break;
        case 16:
            ecrire_ligne("Thank you for playing",21);
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

void gagnant_draw(Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int a,b,c,x,y,z;
    x=strlen(perso_select_joueur1[0]->nom);
    y=strlen(perso_select_joueur1[1]->nom);
    z=strlen(perso_select_joueur1[2]->nom);
    a=strlen(perso_select_joueur2[0]->nom);
    b=strlen(perso_select_joueur2[1]->nom);
    c=strlen(perso_select_joueur2[2]->nom);
    haut();
    for (int i=0;i<ELLIAT;i++){
        switch (i){
        case 3:
            ecrire_ligne("CY Fighters",11);
            break;
        case 7:
            ecrire_ligne("The winners are :",17);
            break;
        case 8:
            bas();
            break;
        case 9:
            barre_m();
            break;
        case 10:
            ecrire_ligne_mdg(perso_select_joueur1[0]->nom,x,perso_select_joueur2[0]->nom,a);
            break;
        case 11:
            ecrire_ligne_mdg(perso_select_joueur1[1]->nom, y, perso_select_joueur2[1]->nom, b);
            break;
        case 12:
            ecrire_ligne_mdg(perso_select_joueur1[2]->nom,z,perso_select_joueur2[2]->nom,c);
            break;
        case 13:
            bas2();
            break;
        case 16:
            ecrire_ligne("Thank you for playing",21);
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

void choix_adversaire(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3],Personnages *adversaire[3]){
    int x,y,z,a,b,c,att,m,n,o,p,q,r,d,e,f;
    x=strlen(perso_select_joueur1[0]->nom);
    y=strlen(perso_select_joueur1[1]->nom);
    z=strlen(perso_select_joueur1[2]->nom);
    a=strlen(perso_select_joueur2[0]->nom);
    b=strlen(perso_select_joueur2[1]->nom);
    c=strlen(perso_select_joueur2[2]->nom);
    att=strlen(attaquant->nom);
    m=strlen(perso_select_joueur1[0]->type);
    n=strlen(perso_select_joueur1[1]->type);
    o=strlen(perso_select_joueur1[2]->type);
    p=strlen(perso_select_joueur2[0]->type);
    q=strlen(perso_select_joueur2[1]->type);
    r=strlen(perso_select_joueur2[2]->type);
    d=strlen(adversaire[0]->nom);
    e=strlen(adversaire[1]->nom);
    f=strlen(adversaire[2]->nom);
    haut();
    for (int i=0;i<ELLIAT;i++){
        switch (i){
        case 0:
            ecrire_ligne_mdg("[Team 1]",8,"[Team 2]",8);
            break;
        case 2:
            ecrire_ligne_mdg(perso_select_joueur1[0]->nom,x,perso_select_joueur2[0]->nom,a);
            break;
        case 3:
            ecrire_ligne_mdg(perso_select_joueur1[0]->type,m,perso_select_joueur2[0]->type,p);
            break;
        case 4:
            ecrire_ligne_mdgint(perso_select_joueur1[0]->point_de_vie_courante,3,perso_select_joueur2[0]->point_de_vie_courante,3);
            break;
        case 6:
            ecrire_ligne_mdg(perso_select_joueur1[1]->nom, y, perso_select_joueur2[1]->nom, b);
            break;
        case 7:
            ecrire_ligne_mdg(perso_select_joueur1[1]->type,n,perso_select_joueur2[1]->type,q);
            break;
        case 8:
            ecrire_ligne_mdgint(perso_select_joueur1[1]->point_de_vie_courante,3,perso_select_joueur2[1]->point_de_vie_courante,3);
            break;
        case 10:
            ecrire_ligne_mdg(perso_select_joueur1[2]->nom,z,perso_select_joueur2[2]->nom,c);
            break;
        case 11:
            ecrire_ligne_mdg(perso_select_joueur1[2]->type,o,perso_select_joueur2[2]->type,r);
            break;
        case 12:
            ecrire_ligne_mdgint(perso_select_joueur1[2]->point_de_vie_courante,3,perso_select_joueur2[2]->point_de_vie_courante,3);
            break;
        case 13:
            bas2();
            break;
        case 14:
            ecrire_ligne("Character playing now :",23);
            break;
        case 15:
            ecrire_ligne(attaquant->nom,att);
            break;
        case 16:
            ecrire_ligne("Type '1' to target :",20);
            break;
        case 17:
            ecrire_ligne(adversaire[0]->nom,d);
            break;
        case 18:
            ecrire_ligne("Type '2' to target :",20);
            break;
        case 19:
            ecrire_ligne(adversaire[1]->nom,e);
            break;
        case 20:
            ecrire_ligne("Type '3' to target :",20);
            break;
        case 21:
            ecrire_ligne(adversaire[2]->nom,f);
            break;
        default:
            barre_m();
            break;
        }
    }
    bas();
}

void choix_heal(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3],Personnages *adversaire[3]){
    int x,y,z,a,b,c,att,m,n,o,p,q,r,d,e,f;
    x=strlen(perso_select_joueur1[0]->nom);
    y=strlen(perso_select_joueur1[1]->nom);
    z=strlen(perso_select_joueur1[2]->nom);
    a=strlen(perso_select_joueur2[0]->nom);
    b=strlen(perso_select_joueur2[1]->nom);
    c=strlen(perso_select_joueur2[2]->nom);
    att=strlen(attaquant->nom);
    m=strlen(perso_select_joueur1[0]->type);
    n=strlen(perso_select_joueur1[1]->type);
    o=strlen(perso_select_joueur1[2]->type);
    p=strlen(perso_select_joueur2[0]->type);
    q=strlen(perso_select_joueur2[1]->type);
    r=strlen(perso_select_joueur2[2]->type);
    d=strlen(adversaire[0]->nom);
    e=strlen(adversaire[1]->nom);
    f=strlen(adversaire[2]->nom);
    haut();
    for (int i=0;i<ELLIAT;i++){
        switch (i){
        case 0:
            ecrire_ligne_mdg("[Team 1]",8,"[Team 2]",8);
            break;
        case 2:
            ecrire_ligne_mdg(perso_select_joueur1[0]->nom,x,perso_select_joueur2[0]->nom,a);
            break;
        case 3:
            ecrire_ligne_mdg(perso_select_joueur1[0]->type,m,perso_select_joueur2[0]->type,p);
            break;
        case 4:
            ecrire_ligne_mdgint(perso_select_joueur1[0]->point_de_vie_courante,3,perso_select_joueur2[0]->point_de_vie_courante,3);
            break;
        case 6:
            ecrire_ligne_mdg(perso_select_joueur1[1]->nom, y, perso_select_joueur2[1]->nom, b);
            break;
        case 7:
            ecrire_ligne_mdg(perso_select_joueur1[1]->type,n,perso_select_joueur2[1]->type,q);
            break;
        case 8:
            ecrire_ligne_mdgint(perso_select_joueur1[1]->point_de_vie_courante,3,perso_select_joueur2[1]->point_de_vie_courante,3);
            break;
        case 10:
            ecrire_ligne_mdg(perso_select_joueur1[2]->nom,z,perso_select_joueur2[2]->nom,c);
            break;
        case 11:
            ecrire_ligne_mdg(perso_select_joueur1[2]->type,o,perso_select_joueur2[2]->type,r);
            break;
        case 12:
            ecrire_ligne_mdgint(perso_select_joueur1[2]->point_de_vie_courante,3,perso_select_joueur2[2]->point_de_vie_courante,3);
            break;
        case 13:
            bas2();
            break;
        case 14:
            ecrire_ligne("Character playing now :",23);
            break;
        case 15:
            ecrire_ligne(attaquant->nom,att);
            break;
        case 16:
            ecrire_ligne("Type '1' to heal :",18);
            break;
        case 17:
            ecrire_ligne(adversaire[0]->nom,d);
            break;
        case 18:
            ecrire_ligne("Type '2' to heal :",18);
            break;
        case 19:
            ecrire_ligne(adversaire[1]->nom,e);
            break;
        case 20:
            ecrire_ligne("Type '3' to heal :",18);
            break;
        case 21:
            ecrire_ligne(adversaire[2]->nom,f);
            break;
        default:
            barre_m();
            break;
        }
    }
    bas();
}

void effectuer_action(Personnages *attaquant,Personnages *perso_select_joueur1[3],Personnages *perso_select_joueur2[3]){
    int x,y,z,a,b,c,att,m,n,o,p,q,r;
    x=strlen(perso_select_joueur1[0]->nom);
    y=strlen(perso_select_joueur1[1]->nom);
    z=strlen(perso_select_joueur1[2]->nom);
    a=strlen(perso_select_joueur2[0]->nom);
    b=strlen(perso_select_joueur2[1]->nom);
    c=strlen(perso_select_joueur2[2]->nom);
    att=strlen(attaquant->nom);
    m=strlen(perso_select_joueur1[0]->type);
    n=strlen(perso_select_joueur1[1]->type);
    o=strlen(perso_select_joueur1[2]->type);
    p=strlen(perso_select_joueur2[0]->type);
    q=strlen(perso_select_joueur2[1]->type);
    r=strlen(perso_select_joueur2[2]->type);
    haut();
    for (int i=0;i<ELLIAT;i++){
        switch (i){
        case 0:
            ecrire_ligne_mdg("[Team 1]",8,"[Team 2]",8);
            break;
        case 2:
            ecrire_ligne_mdg(perso_select_joueur1[0]->nom,x,perso_select_joueur2[0]->nom,a);
            break;
        case 3:
            ecrire_ligne_mdg(perso_select_joueur1[0]->type,m,perso_select_joueur2[0]->type,p);
            break;
        case 4:
            ecrire_ligne_mdgint(perso_select_joueur1[0]->point_de_vie_courante,3,perso_select_joueur2[0]->point_de_vie_courante,3);
            break;
        case 6:
            ecrire_ligne_mdg(perso_select_joueur1[1]->nom, y, perso_select_joueur2[1]->nom, b);
            break;
        case 7:
            ecrire_ligne_mdg(perso_select_joueur1[1]->type,n,perso_select_joueur2[1]->type,q);
            break;
        case 8:
            ecrire_ligne_mdgint(perso_select_joueur1[1]->point_de_vie_courante,3,perso_select_joueur2[1]->point_de_vie_courante,3);
            break;
        case 10:
            ecrire_ligne_mdg(perso_select_joueur1[2]->nom,z,perso_select_joueur2[2]->nom,c);
            break;
        case 11:
            ecrire_ligne_mdg(perso_select_joueur1[2]->type,o,perso_select_joueur2[2]->type,r);
            break;
        case 12:
            ecrire_ligne_mdgint(perso_select_joueur1[2]->point_de_vie_courante,3,perso_select_joueur2[2]->point_de_vie_courante,3);
            break;
        case 13:
            bas2();
            break;
        case 14:
            ecrire_ligne("Character playing now :",23);
            break;
        case 15:
            ecrire_ligne(attaquant->nom,att);
            break;
        case 16:
            ecrire_ligne("Type '1' to use a normal attack :",33);
            break;
        case 17:
            if(attaquant->att<100){
                ecrire_ligneint(attaquant->att,11);
            }
            else{
                ecrire_ligneint(attaquant->att,12);
            }
            break;
        case 18:
            ecrire_ligne("Type '2' to use your first special attack :",43);
            break;
        case 19:
                ecrire_ligneint(attaquant->att_spe1->valeur,12);
            break;
        case 20:
            ecrire_ligne("Type '3' to use your second special attack :",44);
            break;
        case 21:
                ecrire_ligneint(attaquant->att_spe2->valeur,12);
            break;
        default:
            barre_m();
            break;
        }
    }
    bas();
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
                ecrire_ligne_mdg("Pv : 600",8,"pv : 400",8);
                break;
            case 5:
                ecrire_ligne_mdg("att : 40",8,"att : 70",8);
                break;
            case 6:
                ecrire_ligne_mdg("def : 0.70",10,"def : 0.20",10);
                break;
            case 7:
                ecrire_ligne_mdg("vit : 30",8,"vit : 20",8);
                break;
            case 8:
                ecrire_ligne_mdg("agi : 0.00",10,"agi : 0.30",10);
                break;
            case 9:
                ecrire_ligne_mdg("ult : Charge, Dirt wall",19,"ult : Magic heal, Miraculous heal",33);
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
                ecrire_ligne_mdg("Pv : 450",8,"pv : 550",8);
                break;
            case 17:
                ecrire_ligne_mdg("att : 50",8,"att : 30",8);
                break;
            case 18:
                ecrire_ligne_mdg("def : 0.20",10,"def : 0.75",10);
                break;
            case 19:
                ecrire_ligne_mdg("vit : 45",8,"vit : 35",8);
                break;
            case 20:
                ecrire_ligne_mdg("agi : 0.15",10,"agi : 0.00",10);
                break;
            case 21:
                ecrire_ligne_mdg("ult : Meteor, Lightning",23,"ult : Charge, Shield",20);
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
                ecrire_ligne_mdg("Pv : 400",8,"pv : 475",8);
                break;
            case 5:
                ecrire_ligne_mdg("att : 60",8,"att : 60",8);
                break;
            case 6:
                ecrire_ligne_mdg("def : 0.20",10,"def : 0.37",10);
                break;
            case 7:
                ecrire_ligne_mdg("vit : 10",8,"vit : 80",8);
                break;
            case 8:
                ecrire_ligne_mdg("agi : 0.30",10,"agi : 0.10",10);
                break;
            case 9:
                ecrire_ligne_mdg("ult : Magic heal, Miraculous heal",33,"ult : Shuriken, Fiery fist",26);
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
                ecrire_ligne_mdg("Pv : 500",8,"pv : 375",8);
                break;
            case 17:
                ecrire_ligne_mdg("att : 60",8,"att : 60",8);
                break;
            case 18:
                ecrire_ligne_mdg("def : 0.45",10,"def : 0.35",10);
                break;
            case 19:
                ecrire_ligne_mdg("vit : 85",8,"vit : 95",8);
                break;
            case 20:
                ecrire_ligne_mdg("agi : 0.10",10,"agi : 0.20",10);
                break;
            case 21:
                ecrire_ligne_mdg("ult : Smash, Whirlwind",22,"ult : Bite, Dash in",19);
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
            ecrire_ligne_mdg("your friend",11,"a bot",5);
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