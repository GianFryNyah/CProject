#include <stdio.h>
#include <stdlib.h>
#include "DiceThrow.c"
#include "FileManipulator.c"

void clear(void)
{
    while ( getchar() != '\n' );
}

int InputHandlerInt(char buff[]){
    char *endptr;
    if (!fgets(buff, 64, stdin)){
        return 1;
    }
    return strtol(buff, &endptr, 10);
}

void menu(){
    int choice = 0;
    printf("\nMenu Principale:\n");
    printf("\n  1. Nuova Partita\n  2. Carica Salvataggio\n");

    do{
        printf("Seleziona una delle opzioni del menu [1-2]: ");
        char buff[2];
        //choice = InputHandlerInt(buff);
        int success;
        char konamicode[] = "wwssadadba ";
        int len = sizeof(konamicode) / sizeof(konamicode[0]);
        fgets(buff, 2, stdin);
        char *endptr;
        choice = strtol(buff, &endptr, 10);

        //MENU CHOICE TESTING PURPOSE
        //printf("\n%d\n", choice);

        //DEBUGGING FOR SAVE SYSTEM WITH TIME STAMP
        char* SaveStats = ", -- P . VITA , -- MONETE , -- OGGETTI , - MISSIONI COMPLETATE\n";
        addSave(SaveStats);

        //DEBUGGING FOR DELETING SAVES
        int Num = 7;
        deleteSave(Num);

        //DEBUGGING FOR DICE THROW
        //int result = DiceThrow();
        //printf("Dice trown's result is: %d\n", result);

        switch (choice){
            case 1:
                //Crea un nuovo salvataggio
                //Iniziera' una nuova partita dove all’avvio verra' creato l’eroe della storia, che iniziera' con
                //20 punti vita, 0 monete, 0 oggetti, 0 missioni completate.
                //Vedi la Sezione 3 per lo svolgimento e le regole del gioco.
                break;
            case 2:
                //mostra i salvataggi da poter caricare
                break;
            case 3:
                //trucchi
                //accessibile con Konami's code
                exit(1);
            default:
                //TESTING PURPOSE
                break;
        }
        clear();
    }while(choice != 3);
}