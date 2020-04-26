#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"
#include "linkedlist.h"
#include "logs.h"

Settings* readFile(char* fileName)
{
    Settings* settings = (Settings*)malloc(sizeof(Settings)); 
    FILE* theFile;
    char tempLetter;
    int tempNum;
    int numM;
    int numN;
    int numK; 

    theFile = fopen(fileName, "r");
 
    if (theFile == NULL)
    {
        printf("Error. Unable to find file\n");
        fclose(theFile);
    }
    else
    {
        while (!feof(theFile))
        {
            fscanf(theFile, "%c=%d\n", &tempLetter, &tempNum);

            if (tempLetter == 'M' || tempLetter == 'm')
            {
                settings->M = tempNum;
                numM = 1;
            }
            else if (tempLetter == 'N' || tempLetter == 'n')
            {
                settings->N = tempNum; 
                numN = 1;
            }
            else if (tempLetter == 'K' || tempLetter == 'k')       
            {
                settings->K = tempNum;
                numK = 1;
            }
        }
    }   
    fclose(theFile);
    return settings;
}

void viewSettings(char* fileName)
{
    FILE* theFile;

    theFile = fopen(fileName, "r");

    if (theFile == NULL)
    {
        printf("Error. Unable to find file\n");
        fclose(theFile);
    } 
    else
    {
        char tempLetter;
        int tempNum;

        printf("\nSETTINGS:\n");
        do
        {
            fscanf(theFile,"%c=%d\n", &tempLetter, &tempNum);
            printf("    %c=%d\n", tempLetter, tempNum);
        }
        while(!feof(theFile));
        fclose(theFile);
    }
}

#ifdef EDITOR
void editSettings(char* fileName)
{
    FILE* theFile;
    int newM;
    int newN;
    int newK;
    
    theFile = fopen(fileName, "r+");

    if (theFile == NULL)
    {
        printf("Error. Unable to find file\n");
        fclose(theFile);
    }
    else
    {
        printf("\nEnter the M value (rows of board)\n");
        scanf("%d", &newM);

        printf("Enter the N value (columns of board)\n");
        scanf("%d", &newN);

        printf("Enter the K value (amount to win)\n");
        scanf("%d", &newK);

        /* fprintf used to rewrite settings file */
        fprintf(theFile, "M=%d\n", newM);
        fprintf(theFile, "N=%d\n", newN);
        fprintf(theFile, "K=%d\n", newK);
    }
    fclose(theFile);
}
#endif
