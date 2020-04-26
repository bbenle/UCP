#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "fileio.h"
#include "linkedlist.h"
#include "logs.h"
#include "winchecks.h"

/* M is X coordinate
 * N is Y coordinate */

/* gameBoard calls all the other functions within game.c */
void gameBoard(char* fileName, LinkedList* list, Logs* logs, int gameCount)
{
    Settings* settings = NULL;
    char** board;
    /*int ii;*/
    /*int height;*/
    
    settings = readFile(fileName); /* initialise settings with the values read from the file */
    board = initialiseBoard(settings);
    drawBoard(settings, board);
    ticTacToe(settings, list, logs, board, gameCount);
    
    /* for (ii = 0; ii < height; ii++)
    {
        free(board[ii]);
        board[ii] = NULL;
    }
    free(board); 
    board = NULL; */

}

/* creates and mallocs the board
 * loops through entire board and initalises board to be empty ' ' */
char** initialiseBoard(Settings* settings)
{
    int ii;
    int jj;
    int width;
    int height;
    char** board;
    width = settings->M;
    height = settings->N;

    board = (char**)malloc(height * sizeof(char*)); /* malloc y here */

    for (ii = 0; ii < height; ii++)
    {
        board[ii] = (char*)malloc(width * sizeof(char)); /* malloc x here */
    }
    /* board starts off empty */
    for (ii = 0; ii < height; ii++)
    {
        for (jj = 0; jj < width; jj++)
        {
            board[ii][jj] = ' ';
        }
    }
    return board;
}

/* prints out the structure of the Tic Tac Toe board */
void drawBoard(Settings* settings, char** board)
{
    int width;
    int height;
    int ii;
    int jj;
    int kk;
    int ll;
    width = settings->M;
    height = settings->N;
    /* board = initialiseBoard(settings); */ 
 
    /* prints the top border of board */
    printf("\n==="); 
    for (ii = 0; ii < height; ii++)
    {
        printf("====");   
    }
    
    printf("\n"); /* new line */

    for (ii = 0; ii < width; ii++)
    {
        jj = 0; 
        printf("|| %c ", board[jj][ii]);

        for (jj = 1; jj < height; jj++)
        {
            printf("| %c ", board[jj][ii]);
        }
        printf("||\n");
        
        printf("||"); 

        for(kk = 0; kk < height; kk++)
        {
            printf("---");
        }
        
        for(ll = 0; ll < height - 1; ll++)
        {
            printf("-");
        }
        printf("||");
        printf("\n");
    }
}

/* plays the game Tic Tac Toe */
void ticTacToe(Settings* settings, LinkedList* list, Logs* logs, char** board, int gameCount)
{
    /*char player;*/
    int x;
    int y; 
    int draw;
    int width;
    int height;
    int ii;
    int winner;
    int count;
    width = settings->M;
    height = settings->N;
    draw = width * height; /* draw is the max amount of turns required to fill board AKA a draw */  
    /*player = logs->player;*/
    ii = 0;
    count = 0;

    do 
    {
        logs = createLogs(); /* creates the logs */ 
        logs = playerTurn(board, &x, &y, logs); 
        drawBoard(settings, board);
        winner = win(settings, logs, board, x, y);
        
        /* if statement for logging the turn and inserting it if it's valid */
        if (logs != NULL)
        {
            logs->turn = count;
            logs->game = gameCount;
            insertLast(list, logs);
            count++;
        }
        ii++;


        /* this if statement is so that it stops looping
           when a draw occurs */
       /* if (player == 'X' || player == 'O')
        {
            ii++;
        } */
    } while (winner == 0 && ii <= draw);
} 

/* asks user to input X and Y coordinates
 * if the board is empty, it mods the count
 * sets player O, prints O to board and increment count if mod 2 is 0*/
Logs* playerTurn(char** board, int* outX, int* outY, Logs* logs)
{
    /* static int retains count value instead of resetting back to 1 */
    static int count = 1;
    int x;
    int y;

    printf("\nEnter the X and Y coordinates in format 'X,Y'\n");
    scanf("%d,%d", &x, &y);

    if (board[x][y] == ' ')
    {
        if (count % 2 == 0)
        {
            logs->player = 'O'; /* stores the info for Logs */
            board[x][y] = 'O';
            logs->x = x; 
            logs->y = y; 
        }
        else
        {
            logs->player = 'X';
            board[x][y] = 'X';
            logs->x = x;
            logs->y = y;
        }
        count++;
        /* outX and outY used for win condition checks */
        *outX = x; 
        *outY = y; 
    }
    else
    {
        printf("\nThis coordinate is occupied. Try a different one\n");
    }
    return logs;
}
