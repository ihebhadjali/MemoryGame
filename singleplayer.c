#include<stdio.h>
#include<stdlib.h>
//#include"memory.h"
int fillchoice();
void fillGrille(char**,int,int);
void showGrille(char**,int,int);
void singleplayer( int GameDiff ){
    int i,l=2,nbcolGrille=2,j,FillChoice;
    char **Grille;
    system("cls");
    printf("== Single Player ==\n");
    Grille=(char **) malloc(l*sizeof(char*));
    for (i=0;i<l;i++)
        Grille[i]=(char *) malloc(nbcolGrille*sizeof(char));
    FillChoice=fillchoice();
    if(FillChoice==1){
        fillGrille(Grille,l,nbcolGrille);
    }
    showGrille(Grille,l,nbcolGrille);
    free(Grille);
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
void fillGrille(char **Grille,int l,int nbcolGrille){
    int i,j;
    printf("Enter les elements de la matrice A\n");
    for(i=0;i<l;i++)
        for(j=0;j<nbcolGrille;j++){
            printf("Enter la valeur de A[%d][%d] ",i,j);
            scanf(" %c",&Grille[i][j]);
            printf("\n");
        }
}
void showGrille(char **Grille,int l,int nbcolGrille){
    int i,j;
    printf("\n===> Grille <===\n");
    for(j=0;j<nbcolGrille;j++) printf("________________");
    printf("\n");
    for (i=0;i<l;i++){
        for(j=0;j<nbcolGrille;j++)
        printf("\t%c\t|", Grille[i][j]);
        printf("\n");
        for(j=0;j<nbcolGrille;j++) printf("________________");
        printf("\n");
    }
}
void hiddenGrille(char **Grille,int l,int nbcolGrille){
    int i,j;
    printf("\n===> Hidden Grille <===\n");
    for(j=0;j<nbcolGrille;j++) printf("________________");
    printf("\n");
    for (i=0;i<l;i++){
        for(j=0;j<nbcolGrille;j++)
        printf("\t%c\t|", Grille[i][j]);
        printf("\n");
        for(j=0;j<nbcolGrille;j++) printf("________________");
        printf("\n");
    }
}