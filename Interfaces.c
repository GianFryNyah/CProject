#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "DiceThrow.c"
#include "FileManipulator.c"

void game();

void clear(void)
{
    while ( getchar() != '\n' );
}

int InputHandlerInt(int buf_size){
    char *endptr;
    char buff[buf_size];
    fgets(buff, sizeof(buff), stdin);
    return strtol(buff, &endptr, 10);
}

void menu(){
    int choice = 0;
    printf("\nMenu Principale:\n");
    printf("\n  1. Nuova Partita\n  2. Carica Salvataggio\n");

    do{
        printf("Seleziona una delle opzioni del menu [1-2]: ");
        int buf_size = 2;
        choice = InputHandlerInt(buf_size);
        int success;
        char konamicode[] = "wwssadadba ";
        /*int len = sizeof(konamicode) / sizeof(konamicode[0]);
        fgets(buff, 2, stdin);
        char *endptr;
        choice = strtol(buff, &endptr, 10);*/

        //MENU CHOICE TESTING PURPOSE
        //printf("\n%d\n", choice);

        //DEBUGGING FOR SAVE SYSTEM WITH TIME STAMP
        //char* SaveStats = ", -- P . VITA , -- MONETE , -- OGGETTI , - MISSIONI COMPLETATE\n";
        //addSave(SaveStats);

        //DEBUGGING FOR DELETING SAVES
        //int Num = 7;
        //deleteSave(Num);

        //DEBUGGING FOR DICE THROW
        //int result = DiceThrow();
        //printf("Dice trown's result is: %d\n", result);

        switch (choice){
            case 1:
                //Crea un nuovo salvataggio
                //Iniziera' una nuova partita dove all’avvio verra' creato l’eroe della storia, che iniziera' con
                //20 punti vita, 0 monete, 0 oggetti, 0 missioni completate.
                //Vedi la Sezione 3 per lo svolgimento e le regole del gioco.
                game();
                break;
            case 2:
                //mostra i salvataggi da poter caricare
                getchar();
                int SaveIndex = 0;
                int Option = 0;
                printf("\nCarica Salvataggio:\n");
                printf("\n");
                ShowSaves();
                printf("\nSeleziona un salvataggio: ");
                //clear();
                int buf_size = 8;
                SaveIndex = InputHandlerInt(buf_size);
                printf("\nSeleziona un'opzione per il salvataggio %d: ", SaveIndex);
                printf("\n  1. Carica\n  2. Elimina\n");
                printf("\nSeleziona opzione [1-2]: ");
                //clear();
                Option = InputHandlerInt(buf_size);
                switch (Option){
                    case 1:
                        //load save stats
                        printf("\nLoading...");
                        menu();
                        //here ask for additional enter, to fix ( maybe ?)
                        break;
                    case 2:
                        //delete selected save from save file
                        int Confirmation = 1;
                        printf("\nSei sicuro di voler eliminare definitivamente il salvataggio?");
                        printf("\n  1. Si\n  2. No\n");
                        printf("\nSeleziona opzione [1-2]: ");
                        Confirmation = InputHandlerInt(buf_size);
                        if(Confirmation == 1){
                            deleteSave(SaveIndex);
                            printf("\nYou've successfully deleted the selected save!\n");
                            menu();
                        }
                        //here ask for additional enter, to fix ( maybe ?)
                        menu();
                }
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

void game(){
    int life = 20;
    int money = 0;
    int items = 0;
    int CompletedMissions = 0;

    bool PaludePutrescenteIsCompleted = false;
    bool MagioneInfestataIsCompleted = false;
    bool GrottaDiCristalloIsCompleted = false;

    printf("TEST: You've started a new game now!\n");
    int buf = 16;
    int test;
    test = InputHandlerInt(buf);
    printf("\n%d is a number;\nPress Enter to escape from this place!!! ");
}