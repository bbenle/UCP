#ifndef LOGS_H
#define LOGS_H
#include "linkedlist.h"

typedef struct
{
    int game;
    int turn;
    char player;
    int x;
    int y;
} Logs;

Logs* createLogs(void);
void displayLogs(void* data);
void freeLogs(void* data);
void writeToLogs(void* data, FILE* outFile);
void saveLogs(char* fileName, LinkedList* list);
#endif
