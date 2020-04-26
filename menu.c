#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"
#include "game.h"
#include "menu.h"
#include "linkedlist.h"
#include "logs.h"

int main(int argc, char* argv[])
{  
    int gameCount;
    int choice;
    char* theFile;

    Settings* settings = readFile(argv[1]);
    Logs* logs;
    LinkedList* list;
    list = createLinkedList();
    logs = createLogs(); 

    logs->game = gameCount = 1;
    
    theFile = (argv[1]);

    if (argc != 2)
    {
        printf("Error. Run the game by typing ./TicTacToe followed by the "
        "name of the settings file\n");
    }
    else
    {
        do
        {
            printf("\nWelcome to Ben's Tic Tac Toe Program!\n");
            printf("Select from one of the following options\n\n");
            printf("1) Start a new game\n");
            printf("2) View the settings of the game\n");
            printf("3) View the current logs\n");
            #ifndef SECRET
            printf("4) Save the logs to the file\n");
            #endif
            printf("5) Exit the application\n");
            #ifdef EDITOR
            printf("6) Edit settings\n");
            #endif

            scanf("%d", &choice);

            switch (choice)
            {
                case 1:
                    gameBoard(argv[1], list, logs, gameCount);
                    gameCount++;

                    /* printf("gamecount: %d\n", gameCount); */
                    break;
        
                case 2:
                    viewSettings(theFile); /* displays the settings */ 
                    break;

                case 3:
                    viewSettings(theFile);
                    printLinkedList(list, &displayLogs);

                    /*displayLogs(data); */
                    break;

                #ifndef SECRET
                case 4:
                    saveLogs(theFile, list);
                    break;
                #endif
        
                case 5:
                    if (gameCount > 0) /*if user quits before a game is played, nothing is malloc'd, so game count must be at least 1 */
                    {
                        freeLinkedList(list, freeLogs);
                    }
                    free(settings);

                    printf("Thank you for playing!\n");
                    break;

                #ifdef EDITOR
                case 6:
                    editSettings(theFile);
                    break;
                #endif
        
                default:
                    printf("\nInvalid number. Pick between 1-5\n");
            }            
        } while (choice != 5);
    }
    return 0;
}

/* int intInput(char prompt[50], int min, int max)
{
    int num;

    printf(prompt);
    scanf("%d", &num);  
    return num;   
} */


