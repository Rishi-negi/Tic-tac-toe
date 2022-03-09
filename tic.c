#include <stdio.h>
#include <conio.h>
#include<string.h>
#include<stdlib.h>
char name[20];
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

/***Functions Used***/
 int chk_win();
 void make_board();

int main()
{
    int player = 1, i, choice;
    char mark;
    char contestent1[20],contestent2[20];
    char name[20];
    
    //Entering Contestent Names 
    printf("\n\tENTER PLAYER NAME::");
    scanf("%s",contestent1);

    printf("\tENTER PLAYER NAME::");
    scanf("%s",contestent2);
    
    /*********    Verifying the 1st Player    **********/
	for(i=0;i<3;i++)  //players will be given 3 chances to enter the correct name for 1st player 
    {
      printf("\tATTEMPT:%d\n",i+1);
      printf("\tWHO IS GOING TO PLAY FIRST::");
      scanf("%s",name);
      printf("\n");
      if( strcmp(name,contestent1)==0 ){
	     printf("\t\t%s is the 1st player\n",contestent1);
	     printf("\t\t%s is the 2nd player\n",contestent2);
         break;
      }
      else if( strcmp(name,contestent2)==0 ){
      	 printf("\t\t%s is the 1st player\n",contestent2);
	     printf("\t\t%s is the 2nd player\n",contestent1);
      	 break;
	  }
	  else
      {  
          printf("\t.......ERRORRRRR.......\n");
          printf("\t...PLS ENTER A VALID NAME:----\n");
      }
      
      if(i==2){
	    printf("\t Not eligible to play game");
		exit(0);
	  }
      
    }
         
    /*********   Entering players choices     **********/ 
	do
    {
        make_board();
        player = (player % 2) ? 1 : 2;

        printf("\tPlayer %d, enter a number:  ", player);
        scanf("%d", &choice);

        mark = (player == 1) ? 'X' : 'O';


        if (choice == 1 && square[1] == '1')
            square[1] = mark;
            
        else if (choice == 2 && square[2] == '2')
            square[2] = mark;
            
        else if (choice == 3 && square[3] == '3')
            square[3] = mark;
            
        else if (choice == 4 && square[4] == '4')
            square[4] = mark;
            
        else if (choice == 5 && square[5] == '5')
            square[5] = mark;
            
        else if (choice == 6 && square[6] == '6')
            square[6] = mark;
            
        else if (choice == 7 && square[7] == '7')
            square[7] = mark;
            
        else if (choice == 8 && square[8] == '8')
            square[8] = mark;
            
        else if (choice == 9 && square[9] == '9')
            square[9] = mark;
            
        else
        {
            printf("\tInvalid move ");

            player--;
            getch();
        }
        i = chk_win();

        player++;
    }while (i ==  - 1);
    
    make_board();
    
    if (i == 1)
    {
	    printf("\t==>\aPlayer %d win ", --player);
    }
	else
        printf("\t==>\aGame draw");

    getch();

    return 0;
}

/*********************************************
FUNCTION TO RETURN GAME STATUS
 "1"  FOR GAME IS OVER WITH RESULT
"-1"  FOR GAME IS IN PROGRESS
 "O"  GAME IS OVER AND NO RESULT
 **********************************************/

int chk_win()
{

    if (square[1] == square[2] && square[2] == square[3])
        return 1;
        
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
        
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
        
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
        
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
        
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
        
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
        
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
        
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7] 
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1;
}


//FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
void make_board()
{
    printf("\n\n\tTic Tac Toe\n\n");
    
    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

