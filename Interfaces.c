#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "DiceThrow.c"
#include "FileManipulator.c"
#include "InterfaceMethod.c"

typedef struct{
    int life;
    int money;
    int items;
    int CompletedMissions;
}player;

void game(int CheatMode, player player01);

void clear(void)
{
    while ( getchar() != '\n' );
}

void menu(int CheatMode){
    int choice = 0;
    int i = 0;
    char* konamiChar;
    bool CheatActivated;

    if(CheatMode == 1){
        CheatActivated = false;
    }
    else{
        CheatActivated = true;
    }

    Text(CheatMode);
    
    do{//ciclo del menu
        Text(CheatMode + 2);
        int buf_size = 2;

        char *endptr;
        char buff[buf_size];
        fgets(buff, sizeof(buff), stdin);
        choice = strtol(buff, &endptr, 10);

        konamiChar = buff;
        char konamicode[] = "wwssadadba ";
        
        if(konamicode[i] == *konamiChar){ 
            i++;
            if(i == 11){
                CheatMode = 2;
                i = 0;
                if(!CheatActivated){
                    clear();
                    menu(CheatMode);
                }
            }
        }
        else{
            i = 0;
        }

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
                player NewPlayer = {20, 0, 0, 0};
                game(CheatMode, NewPlayer);
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
                        menu(CheatMode);
                        //here ask for additional enter, to fix ( maybe ?)
                        break;
                    case 2:
                        //delete selected save from save file
                        int Confirmation;
                        printf("\nSei sicuro di voler eliminare definitivamente il salvataggio?");
                        printf("\n  1. Si\n  2. No\n");
                        printf("\nSeleziona opzione [1-2]: ");
                        Confirmation = InputHandlerInt(buf_size);
                        if(Confirmation == 1){
                            deleteSave(SaveIndex);
                            printf("\nYou've successfully deleted the selected save!\n");
                            menu(CheatMode);
                        }
                        //here ask for additional enter, to fix ( maybe ?)
                        menu(CheatMode);
                }
                break;
            case 3:
                //trucchi
                //accessibile con Konami's code
                //Use cheats
                if (CheatMode == 2){
                    printf("You're welcome, dirty cheater!\n");
                    clear();
                    menu(CheatMode);
                }
                break;

            default:
                //TESTING PURPOSE
                clear();
                break;
        }
    }while(true);
}

void game(int CheatMode, player player01){

    bool PaludePutrescenteIsCompleted = false;
    bool MagioneInfestataIsCompleted = false;
    bool GrottaDiCristalloIsCompleted = false;

    printf("TEST: You've started a new game now!\n");
    int buf = 16;
    int test;
    test = InputHandlerInt(buf);
    printf("\n%d is a number;\nPress Enter to escape from this place!!! ");
    menu(CheatMode);
}