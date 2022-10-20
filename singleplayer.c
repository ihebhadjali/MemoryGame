#include<stdio.h>
#include<stdlib.h>
#include <time.h>
//#include"memory.h"
void delay(int);
int fillchoice();
void fillGrid(char**,int,int);
void initialGrid(char**,int,int);
void playerRound(char**,char**,int,int,int);
void showGrid(char**,int,int);
void singleplayer( int GameDiff ){
    int i,l=4,c=3,j,x,y,result;
    char **gameGrid, **PlayerGrid,c1,c2,testc1,testc2;
    system("cls");
    printf("== Single Player ==\n");
    gameGrid=(char **) malloc(l*sizeof(char*));
    for (i=0;i<l;i++)
        gameGrid[i]=(char *) malloc(c*sizeof(char));
    initialGrid(gameGrid,l,c);
    fillGrid(gameGrid,l,c);

    PlayerGrid=(char **) malloc(l*sizeof(char*));
    for (i=0;i<l;i++)
        PlayerGrid[i]=(char *) malloc(c*sizeof(char));
    initialGrid(PlayerGrid,l,c);
    printf("==> Game Started <==\nYou have 5 seconds to see the grid:\n");
    printf("Ready?!\n");
    delay(1);
    printf("Go\n");
    for(i=1;i<10;i++){
        playerRound(PlayerGrid,gameGrid,l,c,i);
    }
    free(gameGrid);
}
void fillGrid(char **Grid,int l,int c){
    /*char *charGrid,*indGrid,valInd1,valInd2;
    int h,i,j,k,indChar,m,n,occ,indC,IndL;
    srand(time(NULL));
    h=l*c;
    IndL=h;
    k=h/2;
    //initialisation tableau contient les caracteres
    charGrid=(char *) malloc(k*sizeof(char));
    for(i=0;i<((l*c)/2);i++){
        //*(charGrid+i)=(rand() % (90 - 65 + 1) + 65);
        *(charGrid+i)=49+i;
    }
    //initialisation tableau contient les indices
    indGrid=(char *) malloc(h*sizeof(char));
    for(i=0;i<h;i++){
        *(indGrid+i)=65+i;
    }
    //remplissage automatique (probleme)
    for(i=0;i<((l*c)/2);i++){
        indChar=(rand() % (k + 1));
        occ=0;
        do{
            indC=(rand() % (IndL + 1));
            valInd1=*(indGrid+indC);
            for(m=indC;m<IndL;m++){
                *(indGrid+m)=*(indGrid+m+1);
                printf("%c\n",indC);
            }
            IndL--;
            indC=(rand() % (IndL + 1));
            valInd2=*(indGrid+indC);
            for(m=indC;m<IndL;m++){
                *(indGrid+m)=*(indGrid+m+1);
            }
            IndL--;
            for(m=0;m<l;m++)
                for(n=0;n<c;n++)
                    if(*(*(Grid+m)+n)==valInd1){
                        *(*(Grid+m)+n)=*(charGrid+indChar);
                        occ++;
                    }
                    else if(*(*(Grid+m)+n)==valInd2){
                        *(*(Grid+m)+n)=*(charGrid+indChar);
                        occ++;
                    }
        } while (occ!=2);
        if(indChar!=(k-1))
            for(j=indChar;j<k;j++)
                *(charGrid+j)=*(charGrid+j+1);
        k--;
    }*/
    //_________________________________________
    
    int i,j,k=49;
    for(i=0;i<l;i++)
        for(j=0;j<c;j++){
            *(*(Grid+i)+j)=k;
            k++;
            if(k==(49+((l*c)/2))) k=49;
        }
    //_________________________________________
    /*for(i=0;i<l;i++)
        for(j=0;j<c;j++)


    Grid=(char *) malloc(h*sizeof(char));
    for(i=0;i<h;i++){
        *(Grid+i)=49+i;
    }
    for(i=0;i<k;i++){
        indChar=(rand() % (k + 1))
        valChar=*(indGrid+indChar)
        
    }

    
    printf("===> Fill in the grid <===\n");
    for(i=0;i<l;i++)
        for(j=0;j<c;j++){
            printf("Grid[%d][%d] ",i,j);
            scanf(" %c",&Grid[i][j]);
            printf("\n");
        }*/
}
void initialGrid(char **Grid,int l,int c){
    int i,j,k=0;
    for(i=0;i<l;i++)
        for(j=0;j<c;j++){
            *(*(Grid+i)+j)=65+k;
            k++;
        }
}
void showGrid(char **Grid,int l,int c){
    int i,j;
    printf("\n===> Grid <===\n");
    for(j=0;j<c;j++) printf("________________");
    printf("\n");
    for (i=0;i<l;i++){
        for(j=0;j<c;j++)
        printf("\t%c\t|", *(*(Grid+i)+j));
        printf("\n");
        for(j=0;j<c;j++) printf("________________");
        printf("\n");
    }
}
void delay(int number_of_seconds){
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
void playerRound(char **PlayerGrid,char **gameGrid,int l,int c, int round){
    int i,j,x1,y1,x2,y2;
    char c1,c2,testc1,testc2;
    system("cls");
    printf("===> Round %d <===",round);
    showGrid(gameGrid,l,c);
    delay(3);
    system("cls");
    printf("===> Round %d <===",round);
    showGrid(PlayerGrid,l,c);
    //do{
        printf("Donner 1er indice\n");
        scanf(" %c",&c1);
        printf("Donner 2eme indice\n");
        scanf(" %c",&c2);
    //}while(c1!=c2 && 64<c1<65+(l*c) && 64<c2<65+(l*c));
    for(i=0;i<l;i++)
        for(j=0;j<c;j++){
            if(c1==*(*(PlayerGrid+i)+j)){
                testc1=*(*(gameGrid+i)+j);
                x1=i;
                y1=j;
            }
    }
    for(i=0;i<l;i++)
        for(j=0;j<c;j++){
            if(c2==*(*(PlayerGrid+i)+j)){
                testc2=*(*(gameGrid+i)+j);
                x2=i;
                y2=j;
            }           
    }
    if(testc1==testc2){
        *(*(PlayerGrid+x1)+y1)=*(*(gameGrid+x1)+y1);
        *(*(PlayerGrid+x2)+y2)=*(*(gameGrid+x2)+y2);
    }
    showGrid(PlayerGrid,l,c);
}
