#include<stdio.h>
#include<stdlib.h>
#include"singleplayer.c"
#include"multiplayers.c"
void main(){
    int NumPlyr,GameDiff;
    system("cls");
    printf("Welcome to my Memory Game\n== FIRST STEP ==");
    do{
        printf("\nChoose the game you want to launch :\nPress 1 for 1 Player\nPress 2 for 2 Player #_SOON_#\n");
        scanf("%d",&NumPlyr);
        if(NumPlyr!=1 && NumPlyr!=2) printf("Sorry, Wrong choice! Try Again -_-\"");
    }while (NumPlyr!=1 && NumPlyr!=2);
    printf("\n== NEXT STEP ==\n");
    do{
        printf("\nChoose the game difficulty :\nPress 1 for Easy\nPress 2 for Medium\nPress 3 for Hard\n");
        scanf("%d",&GameDiff);
        if(GameDiff!=1 && GameDiff!=2 && GameDiff!=3) printf("Sorry, Wrong choice! Try Again -_-\"");
    }while (GameDiff!=1 && GameDiff!=2 && GameDiff!=3);
    if(NumPlyr==1) singleplayer(GameDiff);
    else if (NumPlyr==2) multiplayers(GameDiff);
    system("pause");
}