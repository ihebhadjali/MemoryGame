#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//#include"memory.h"
void delay(int);
int fillchoice();
void fillGrid(char**,int,int);
void initialGrid(char**,int,int);
void showGrid(char**,int,int);
void singleplayer( int GameDiff ){
    int i,l=3,nbcolGrid=2,j,FillChoice;
    char **Grid, **PlayerGrid;
    system("cls");
    printf("== Single Player ==\n");
    Grid=(char **) malloc(l*sizeof(char*));
    for (i=0;i<l;i++)
        Grid[i]=(char *) malloc(nbcolGrid*sizeof(char));
    FillChoice=fillchoice();
    if(FillChoice==1){
        fillGrid(Grid,l,nbcolGrid);
    }
    showGrid(Grid,l,nbcolGrid);
    delay(5);
    system("cls");
    PlayerGrid=(char **) malloc(l*sizeof(char*));
    for (i=0;i<l;i++)
        PlayerGrid[i]=(char *) malloc(nbcolGrid*sizeof(char));
    initialGrid(PlayerGrid,l,nbcolGrid);
    printf("==> Game Started <==\nYou have 5 seconds to see the grid:\n");
    printf("Ready?!\n");
    delay(1);
    printf("Go\n");
    showGrid(Grid,l,nbcolGrid);
    showGrid(PlayerGrid,l,nbcolGrid);
    delay(3);
    system("cls");
    free(Grid);
}
int fillchoice(){
    int c;
    do{
        printf("\nchoose how you want to fill the game cases :\nPress 1 for manual refilling\nPress 2 for automatic refilling #_SOON_#\n");
        scanf("%d",&c);
        if(c!=1 && c!=2) printf("Sorry, Wrong choice! Try Again -_-\"");
    }while (c!=1 && c!=2);
    return c;
}
void fillGrid(char **Grid,int l,int nbcolGrid){
    int i,j;
    printf("===> Fill in the grid <===\n");
    for(i=0;i<l;i++)
        for(j=0;j<nbcolGrid;j++){
            printf("Grid[%d][%d] ",i,j);
            scanf(" %c",&Grid[i][j]);
            printf("\n");
        }
}
void initialGrid(char **Grid,int l,int nbcolGrid){
    int i,j,k=49;
    printf("===> Fill in the grid <===\n");
    for(i=0;i<l;i++)
        for(j=0;j<nbcolGrid;j++){
            Grid[i][j]=(char)k;
            k++;
        }
}
void showGrid(char **Grid,int l,int nbcolGrid){
    int i,j;
    printf("\n===> Grid <===\n");
    for(j=0;j<nbcolGrid;j++) printf("________________");
    printf("\n");
    for (i=0;i<l;i++){
        for(j=0;j<nbcolGrid;j++)
        printf("\t%c\t|", Grid[i][j]);
        printf("\n");
        for(j=0;j<nbcolGrid;j++) printf("________________");
        printf("\n");
    }
}
void delay(int number_of_seconds){
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
