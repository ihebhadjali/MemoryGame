#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int singlePlyrGame(int,int);
int multiPlyrGame(int*,int*,int);
void gameDef(int,int*,int*,int*);
void initialGrid(char**,int,int);
void fillGrid(char**,int,int);
void showGrid(char**,int,int);
void delay(int);
void plyrRound(char**,char**,int,int,int*,int);
void multiPlyrRound(char**,char**,int,int,int*,int*,int*,int*,int);
int stillPlay(char**,char**,int,int,int);
void adminPnael();

//_____________________________________________________

int singlePlyrGame(int lvl,int score){
    int l,c,i,jet,res;
    char **gameGrid, **PlayerGrid;
    delay(1);
    system("cls");
    gameDef(lvl,&l,&c,&jet);
    
    PlayerGrid=(char **) malloc(l*sizeof(char*));
    for (i=0;i<l;i++)
        PlayerGrid[i]=(char *) malloc(c*sizeof(char));

    gameGrid=(char **) malloc(l*sizeof(char*));
    for (i=0;i<l;i++)
        gameGrid[i]=(char *) malloc(c*sizeof(char));

    initialGrid(PlayerGrid,l,c);
    fillGrid(gameGrid,l,c);

    while(stillPlay(PlayerGrid,gameGrid,l,c,jet)==1){
        plyrRound(PlayerGrid,gameGrid,l,c,&jet,lvl);
    }
    if(jet==0){
        printf("\n*********       Game Over -_-!       *********\n******** You have lost all your coins ********\n");
        delay(5);
        system("cls");
        res=0;
    }
    else {
        printf("\n*********     You Win^_^      *********\n********   Level %d Complited   ********\n",lvl);
        delay(5);
        system("cls");
        res=1;
    }
    for (i=0;i<l;i++)
        free(PlayerGrid[i]);
    free(PlayerGrid);

    for (i=0;i<l;i++)
        free(gameGrid[i]);
    free(gameGrid);
    return res;
}

//_____________________________________________________

void initialGrid(char **Grid,int l,int c){
    int i,j,k=0;
    for(i=0;i<l;i++)
        for(j=0;j<c;j++){
            *(*(Grid+i)+j)=49+k;
            k++;
        }
}

//_____________________________________________________

void fillGrid(char **Grid,int l,int c){
    char *charGrid;
    int i,j,k=0,e=65,rep=0,ind1,ind2;
    srand(time(NULL));
    charGrid=(char *) malloc(l*c*sizeof(char));
    for(i=0;i<l*c;i++){
        *(charGrid+i)='-';
    }
    do{
        do{
            ind1=(rand() % (l*c));
            ind2=(rand() % (l*c));
        }while((ind1==ind2) || (*(charGrid+ind1)!='-') || (*(charGrid+ind2)!='-'));
        *(charGrid+ind1)=e;
        *(charGrid+ind2)=e;
        e++;
        rep++;
    }while(rep<((l*c)/2));
    for(i=0;i<l;i++)
        for(j=0;j<c;j++){
            *(*(Grid+i)+j)=*(charGrid+k);
            k++;
        }
}

//_____________________________________________________

void showGrid(char **Grid,int l,int c){
    int i,j;
    printf("\n************* Grid *************\n");
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

//_____________________________________________________

void delay(int number_of_seconds){
    int milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}

//_____________________________________________________

void plyrRound(char **PlayerGrid,char **gameGrid,int l,int c, int *jet,int lvl){
    int i,j,x1,y1,x2,y2;
    char c1,c2,testc1,testc2;
    printf("\n************** Level %d **************\n********* You have  %d Coins *********\n\nYou have 5 seconds to see the grid\n",lvl,*jet);
    showGrid(gameGrid,l,c);
    delay(5);
    system("cls");
    printf("\n************** Level %d **************\n********* You have  %d Coins *********\n\n\n",lvl,*jet);
    delay(1);
    showGrid(PlayerGrid,l,c);
    do{
        printf("\nEnter the first index : ");
        scanf(" %c",&c1);
        printf("Enter the second index : ");
        scanf(" %c",&c2);
        if(c1==c2) printf("Error -_- ! You must choose different boxes\n");
        if((48>c1) && (c1>(49+(l*c))))  printf("Error -_-! , %c doesn't exist\n",c1);
        if((48>c2) && (c2>(49+(l*c))))  printf("Error -_-! , %c doesn't exist\n",c2);
    }while((c1==c2) && ((48<c1) || (c1<(49+(l*c)))) && ((48<c2)||(c2<(49+(l*c)))));
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
        printf("\nGood Game ^_^\n");
        delay(3);

    }
    else{
        printf("\nWrong choice -_-!\n");
        *jet=(*jet)-1;
        delay(3);
    }
    system("cls");
}

//_____________________________________________________

int stillPlay(char **PlayerGrid,char **gameGrid,int l,int c, int jet){
    int i,j,k=0;
    if (jet==0) k=0;
    else{
        for(i=0;i<l;i++)
            for(j=0;j<c;j++){
                if(*(*(gameGrid+i)+j)!=*(*(PlayerGrid+i)+j)){
                    k=1;
                    break;
                }
            }
    }
    return k;
}

//_____________________________________________________

int multiPlyrGame(int *scorePlyr1,int *scorePlyr2,int lvl){
    int l,c,i,jet,res,plyrTurn=0;
    char **gameGrid, **PlayersGrid;
    delay(1);
    system("cls");
    gameDef(lvl,&l,&c,&jet);

    PlayersGrid=(char **) malloc(l*sizeof(char*));
    for (i=0;i<l;i++)
        PlayersGrid[i]=(char *) malloc(c*sizeof(char));

    gameGrid=(char **) malloc(l*sizeof(char*));
    for (i=0;i<l;i++)
        gameGrid[i]=(char *) malloc(c*sizeof(char));

    initialGrid(PlayersGrid,l,c);
    fillGrid(gameGrid,l,c);

    while(stillPlay(PlayersGrid,gameGrid,l,c,jet)==1){
        multiPlyrRound(PlayersGrid,gameGrid,l,c,&jet,&plyrTurn,scorePlyr1,scorePlyr2,lvl);
    }

    if(jet==0){
        printf("\n*********       Game Over -_-!       *********\n******** You have lost all your coins ********\n");
        delay(1);
        res=0;
    }
    else {
        printf("\n********   Level %d Complited   ********\n",lvl);
        delay(1);
        res=1;
    }

    for (i=0;i<l;i++)
        free(PlayersGrid[i]);
    free(PlayersGrid);

    for (i=0;i<l;i++)
        free(gameGrid[i]);
    free(gameGrid);

    return res;
}

//_____________________________________________________

void gameDef(int lvl,int *l,int *c,int *jet){
    switch (lvl){
        case 1 :
            *l=2;
            *c=2;
            *jet=3;
            break;
        case 2 :
            *l=2;
            *c=3;
            *jet=4;
            break;
        case 3 :
            *l=2;
            *c=4;
            *jet=5;
            break;
        case 4 :
            *l=3;
            *c=4;
            *jet=6;
            break;
        default :
            printf("Error 404!");
            break;
    }
}

//_____________________________________________________

void multiPlyrRound(char **PlayersGrid,char **gameGrid,int l,int c,int *jet,int *plyrTurn,int *scorePlyr1,int *scorePlyr2,int lvl){
    int i,j,x1,y1,x2,y2;
    char c1,c2,testc1,testc2;
    printf("\n************** Level %d **************\n********* You have  %d Coins *********\n\nPlayer %d It's your turn.\nYou have 5 seconds to see the grid\n",lvl,*jet,((*plyrTurn)%2)+1);
    showGrid(gameGrid,l,c);
    delay(5);
    system("cls");
    printf("\n************** Level %d **************\n********* You have  %d Coins *********\n\n\n\n",lvl,*jet);
    delay(1);
    showGrid(PlayersGrid,l,c);
    if(((*plyrTurn)%2)==0) printf("\nPlayer %d turn :\n",((*plyrTurn)%2)+1);
    else printf("\nPlayer %d turn :\n",((*plyrTurn)%2)+1);
    do{
        printf("Enter the first index : ");
        scanf(" %c",&c1);
        printf("Enter the second index : ");
        scanf(" %c",&c2);
        if(c1==c2) printf("Error -_- ! You must choose different boxes\n");
        if((48>c1) && (c1>(49+(l*c))))  printf("Error -_-! , %c doesn't exist\n",c1);
        if((48>c2) && (c2>(49+(l*c))))  printf("Error -_-! , %c doesn't exist\n",c2);
    }while((c1==c2) && ((48<c1) || (c1<(49+(l*c)))) && ((48<c2)||(c2<(49+(l*c)))));
    for(i=0;i<l;i++)
        for(j=0;j<c;j++){
            if(c1==*(*(PlayersGrid+i)+j)){
                testc1=*(*(gameGrid+i)+j);
                x1=i;
                y1=j;
            }
    }
    for(i=0;i<l;i++)
        for(j=0;j<c;j++){
            if(c2==*(*(PlayersGrid+i)+j)){
                testc2=*(*(gameGrid+i)+j);
                x2=i;
                y2=j;
            }           
    }
    if(testc1==testc2){
        *(*(PlayersGrid+x1)+y1)=*(*(gameGrid+x1)+y1);
        *(*(PlayersGrid+x2)+y2)=*(*(gameGrid+x2)+y2);
        printf("\nGood Game Player %d ^_^\n",((*plyrTurn)%2)+1);
        if(((*plyrTurn)%2)==0) *scorePlyr1=(*scorePlyr1)+1;
        else *scorePlyr2=*scorePlyr2+1;
        delay(3);
    }
    else{
        if(*plyrTurn%2==0) printf("\nWrong choice -_-!\n");
        else printf("\nWrong choice -_-!\n");
        *plyrTurn=(*plyrTurn)+1;
        *jet=(*jet)-1;
        delay(3);
    }
    system("cls");
}

//_____________________________________________________

void adminPnael(){
    int choice,l,c,jet,i,indl1,indc1,indl2,indc2;
    char **gameGrid, **PlayerGrid,crct;

    do{
        printf("*************    Memory Game Started    *************\n Mode Admin\n choose 2 load the last matrice enregistrer par ladministrateur \n choose 1 to reset la matrice ");
        scanf("%d",&choice);
    }while( choice!=1 && choice!=2 );
    
    FILE* fp = NULL;
    
    if (choice==1){
        fp = fopen("gamefiles/adminpanel.txt", "w+");
        if (fp != NULL){
            printf("Grid Size");
            scanf("%d",&l);
            scanf("%d",&c);
            fprintf(fp,"%d %d\n",l,c);
            for(i=0;i<((l*c)/2);i++){
                printf("put %c in",65+i);
                scanf("%d %d %d %d",&indl1,&indc1,&indl2,&indc2);
                fprintf(fp,"%c %d %d %d %d\n",65+i,indl1,indc1,indl2,indc2);
            }
            fclose(fp);
        }
        else printf("Impossible d'ouvrir le fichier adminpanel.txt");
    }
    fp = fopen("gamefiles/adminpanel.txt", "r+");
    if (fp != NULL){
        fscanf(fp,"%d %d\n",&l,&c);

        PlayerGrid=(char **) malloc(l*sizeof(char*));
        for (i=0;i<l;i++)
            PlayerGrid[i]=(char *) malloc(c*sizeof(char));

        gameGrid=(char **) malloc(l*sizeof(char*));
        for (i=0;i<l;i++)
            gameGrid[i]=(char *) malloc(c*sizeof(char));
        
        initialGrid(PlayerGrid,l,c);

        for(i=0;i<((l*c)/2);i++){
                fscanf(fp,"%c %d %d %d %d\n",&crct,&indl1,&indc1,&indl2,&indc2);
                gameGrid[indl1][indc1]=crct;
                gameGrid[indl2][indc2]=crct;
                printf("%c",gameGrid[indl1][indc1]);
            }

    while(stillPlay(PlayerGrid,gameGrid,l,c,jet)==1){
        plyrRound(PlayerGrid,gameGrid,l,c,&jet,1);
    }
    if(jet==0){
        printf("\n*********       Game Over -_-!       *********\n******** You have lost all your coins ********\n");
    }
    else {
        printf("\n*********     You Win^_^      *********\n");

    }
    for (i=0;i<l;i++)
        free(PlayerGrid[i]);
    free(PlayerGrid);

    for (i=0;i<l;i++)
        free(gameGrid[i]);
    free(gameGrid);
        fclose(fp);
    }
    else printf("Impossible d'ouvrir le fichier adminpanel.txt");
}
