#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "fileio.h"
#include "linkedlist.h"
#include "logs.h"
#include "winchecks.h"

/* this function calls all the win condition functions
 * if any of these functions is equal to 1 (true), it returns win as 1.
 * this function is used instead of having to call all the win condition
 * functions individually */
int win(Settings* settings, Logs* logs, char** board, int x, int y)
{
    int winRow; 
    int winColumn;
    int winDiagonal;
    int winAntiDiagonal;
    int win;

    winRow = checkRow(settings, logs, board, x, y);
    winColumn = checkColumn(settings, logs, board, x, y);
    winDiagonal = checkDiagonal(settings, logs, board, x, y);
    winAntiDiagonal = checkAntiDiagonal(settings, logs, board, x, y);
    win = 0;

    if ((winRow == 1) || (winColumn == 1) || (winDiagonal == 1) || (winAntiDiagonal == 1))
    {
        win = 1;
    }
    return win;
} 

/* checks rows from left to right for a win on the board */
int checkRow(Settings* settings, Logs* logs, char** board, int x, int y)
{
    int streak;
    int count = 0;
    int win = 0;
    streak = settings->K;
    
    /* traverses to left of board until end of the chain */
    while (traverse(&x, &y, -1, 0, logs, settings, board))
    {
    }
    count = 1;

    /* traverses backwards to right of the board until end of the chain */
    while (traverse(&x, &y, 1, 0, logs, settings, board))
    {
        count++;
    }

    /* if the count is same as K value, player wins */
    if (count == streak)
    {
        printf("\nPlayer %c has won!\n", logs->player);
        win = 1;
    }
    count = 1;
    return win;
}

/* checks columns from top to bottom for a win on the board */
int checkColumn(Settings* settings, Logs* logs, char** board, int x, int y)
{
    int streak;
    int count = 0;
    int win = 0;
    streak = settings->K;
    
    /* traverses to top of board until end of the chain */
    while (traverse(&x, &y, 0, -1, logs, settings, board))
    {
    }
    count = 1;

    /* traverse backwards to bottom of the board until end of the chain */
    while (traverse(&x, &y, 0, 1, logs, settings, board))
    {
        count++;
    }

    /* if the count is same as K value, player wins */
    if (count == streak)
    {
        printf("\nPlayer %c has won!\n", logs->player);
        win = 1;
    }
    count = 1;
    return win;
}

/* checks diagonal top right to bottom left for a win on the board */
int checkDiagonal(Settings* settings, Logs* logs, char** board, int x, int y)
{
    int streak;
    int count = 0;
    int win = 0;
    streak = settings->K;

    /* traverses to top right of board until end of streak */
    while (traverse(&x, &y, 1, -1, logs, settings, board))
    {
    }
    /* traverse backwards to the bottom left until the end of the streak */
    count = 1; /* counts the spot currently on */

    while (traverse(&x, &y, -1, 1, logs, settings, board))
    {
        /* counts the number of steps it traversed while on the chain */
        count++;
    }
    /* if the count is same as K value, player wins */  
    if (count == streak)
    {
        printf("\nPlayer %c won!\n", logs->player);
        win = 1;
    }
    count = 1;
    return win;
}

/* checks diagonal top left to bottom right for a win on the board */
int checkAntiDiagonal(Settings* settings, Logs* logs, char** board, int x, int y)
{
    int streak;
    int count = 0;
    int win = 0;
    streak = settings->K;

    /* traverses to top left of board until the end of the chain */
    while (traverse(&x, &y, -1, -1, logs, settings, board))
    {
        /* changes int* x and int* y values */
    }
    /* traverse backwards to the bottom right until the end of the chain */
    count = 1;

    while (traverse(&x, &y, 1, 1, logs, settings, board))
    {
        /* counts the number of steps it traversed while on the chain */
        count++;
    }
    /* if the count is same as K value, player wins */  
    if (count == streak)
    {
        printf("\nPlayer %c won!\n", logs->player);
        win = 1;
    }
    count = 1;
    return win;
}

/* traverses the Tic Tac Toe board
 * x and y are integer pointers which show where the last user currently is
 * xChange and yChange are numbers used to traverse in certain directions of the board
 * calls withinBounds function to check if the traversal is out of the board */
int traverse(int* x, int* y, int xChange, int yChange, Logs* logs, Settings* settings, char** board)
{
    int moved;
    moved = 0;
    *x = *x + xChange;
    *y = *y + yChange;

    /* checks if the board is even within the boundaries */
    if (withinBounds(settings, *x, *y))
    {
        if(board[*x][*y] == logs->player)
        {
            moved = 1;
        }
    }

    if (moved == 0)
    {
        *x = *x - xChange;
        *y = *y - yChange;
    }
    return moved;
}

/* function to check if the board is out of bounds
 * used to allow traversal without going past the boundary of the Tic Tac Toe board */
int withinBounds(Settings* settings, int x, int y)
{
    int valid;
    int width;
    int height;

    width = settings->M;
    height = settings->N;
    valid = 0;

    /* x greater or equal to 0 AND
       x less than width of board AND
       y greater or equal to 0 AND
       y less than height of board */ 
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        valid = 1;
    }
    return valid;
}
