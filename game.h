#ifndef GAME_H
#define GAME_H
#include "fileio.h"
#include "linkedlist.h"
#include "logs.h"

void gameBoard(char* fileName, LinkedList* list, Logs* logs, int gameCount);
char** initialiseBoard(Settings* settings);
void drawBoard(Settings* settings, char** board);
void ticTacToe(Settings* settings, LinkedList* list, Logs* logs, char** board, int gameCount);
Logs* playerTurn(char** board, int* outX, int* outY, Logs* logs);
#endif
