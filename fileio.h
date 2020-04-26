#ifndef FILEIO_H
#define FILEIO_H
#include "linkedlist.h"
#include "logs.h"

typedef struct
{
    int M; /* width */
    int N; /* height */
    int K; /* number of matching in row */
} Settings;

Settings* readFile(char* fileName);
void viewSettings(char* fileName); 
void editSettings(char* fileName);
#endif
