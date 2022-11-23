#include<stdio.h>
#include<stdlib.h>
#include"myBib.c"
void main(){
    int choice,lvl,scorePlyr1,scorePlyr2;
    char plyrName1[20],plyrName2[20];
    system("cls");
    printf("**********************************\n**********************************\n**\t\t\t\t**\n**          Memory Game         **\n**   Created by  IHEB HADJ ALI  **\n**\t\t\t\t**\n**********************************\n**********************************\n");
    do{
        do{
            printf("\nChoose the game you want to launch :\n\n\t- Press 1 for Single Player\n\t- Press 2 for Multi Players\n\t- Press 3 for Admin Access\n\t- Press 4 to exit the game\n\nYour choice : ");
            scanf("%d",&choice);
            if( choice<1 || choice>4 ){
                printf("\nSorry, Wrong choice! Try Again -_-\"\n");
                delay(3);
                system("cls");
                printf("**********************************\n**********************************\n**\t\t\t\t**\n**          Memory Game         **\n**   Created by  IHEB HADJ ALI  **\n**\t\t\t\t**\n**********************************\n**********************************\n");
            }
        }while ( choice<1 || choice>4 );

        lvl=1;
        scorePlyr1=0;
        scorePlyr2=0;

        if(choice==1){
            system("cls");
            printf("********* Memory Game Started *********\n********* Single Player  Mode *********\n\nWrite your Name : ");
            scanf("%s",&plyrName1);
            while(singlePlyrGame(lvl,scorePlyr1)==1 && lvl<5){
                lvl++;
            }
            if(lvl=5) printf("\nCongratulations %s\nYou have won the game.",plyrName1);
        }

        else if (choice==2){
            system("cls");
            printf("********* Memory Game Started *********\n*********  Mode Multi Player  *********\n\nWrite the first player name : ");
            scanf("%s",&plyrName1);
            printf("Write the second player name : ");
            scanf("%s",&plyrName2);
            
            while(multiPlyrGame(&scorePlyr1,&scorePlyr2,lvl)==1 && lvl<10){
                lvl++;
                printf("\n********     Players Score     ********\n\t%s\t: %d points.\n\t%s\t: %d points",plyrName1,scorePlyr1,plyrName2,scorePlyr2);
                delay(3);
            }
            if(lvl=10){
                if(scorePlyr1>scorePlyr2) printf("\nThe winner is %s\nCongratulations.",plyrName1);
                else if(scorePlyr1<scorePlyr2) printf("\nThe winner is %s\nCongratulations.",plyrName2);
                else printf("\nCongratulations %s and %s\nYou have won the game.",plyrName1,plyrName2);
            }   
        }
        else if (choice==3) adminPnael();
    }while(choice!=4);
    system("pause");
}
