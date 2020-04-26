#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logs.h"
#include "fileio.h"

Logs* createLogs(void)
{
    Logs* logs;
    logs = (Logs*)malloc(sizeof(Logs));
    return logs;
}

void freeLogs(void* data)
{
    Logs* logs = (Logs*)data;
    free(logs);
    logs = NULL;
}

void displayLogs(void* data)
{
    Logs* logs;
    logs = (Logs*)data;
    
    printf("\nGAME: %d\n", logs->game);
    printf("    Turn: %d\n", logs->turn);
    printf("    Player: %c\n", logs->player);
    printf("    Location: %d,%d\n", logs->x, logs->y);
    printf("\n");
}

void writeToLogs(void* data, FILE* outFile)
{
    Logs* logs;
    logs = (Logs*)data;
    printf("\nGAME: %d\n", logs->game);
    printf("    Turn: %d\n", logs->turn);
    printf("    Player: %c\n", logs->player);
    printf("    Location: %d,%d\n", logs->x, logs->y);
    fprintf(outFile, "\n");
}
    
/* function used to save lo);gs into a file
 * this function implements ideas from the following websites
 * https://www.techiedelight.com/print-current-date-and-time-in-c/
 * https://www.tutorialspoint.com/c_standard_library/c_function_localtime.htm */
void saveLogs(char* fileName, LinkedList* list)
{
    Settings* settings = NULL;
    FILE* outFile;
    int hour;
    int min;
    int day;
    int month;
    char text[50];
    time_t currTime;
    struct tm *now;
    time(&currTime);

    now = localtime(&currTime);
    hour = now->tm_hour;
    min = now->tm_min;
    day = now->tm_mday;
    month = now->tm_mon + 1;

    settings = readFile(fileName);
    sprintf(text, "MNK_%d-%d-%d_%d-%d_%02d-%02d.log", settings->M, settings->N, settings->K, hour, min, day, month);

    outFile = fopen(text, "w");
    
    if (outFile == NULL)
    {
        printf("Error. Unable to open file\n");
        fclose(outFile);
    }
    else
    {  
        Logs* logs; 
        LinkedListNode* node;
        node = list->head;

        while (node != NULL)
        {
            logs = (Logs*)node->data;
            fprintf(outFile,"\nGAME: %d\n", logs->game);
            fprintf(outFile,"    Turn: %d\n", logs->turn);
            fprintf(outFile,"    Player: %c\n", logs->player);
            fprintf(outFile,"    Location: %d,%d\n", logs->x, logs->y);
            node = node->next;
        }
    }
}
