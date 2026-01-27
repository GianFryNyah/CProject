#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "DiceThrow.h"
#include "FileManipulator.h"
#include "InterfaceMethod.h"
#define BUF 128

typedef struct{
    int life;
    int money;
    int items;
    int CompletedMissions;
    int mission_selector;
    int mission_selector_range;
}player;

void game(int CheatMode, player player01);

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

        //DEBUG TOOLS

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
                clear();
                player NewPlayer = {20, 0, 0, 0, 6, 7};
                game(CheatMode, NewPlayer);
            case 2:
                //mostra i salvataggi da poter caricare
                getchar();
                int Confirmation = 2;
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

void palude_putrescente(void) {} //WORK IN PROGRESS
void magione_infestata(void) {}
void grotta_di_cristallo(void) {}

void game(int CheatMode, player player01){
    // I booleani qua sotto devono stare fuori da game()
    // altrimenti ritornerebbero tutti sempre a false ad ogni chiamata di game() ( che avviene alla fine di ogni missione in teoria )
    bool PaludePutrescenteIsCompleted = false;
    bool MagioneInfestataIsCompleted = false;
    bool GrottaDiCristalloIsCompleted = false;
    
    
    bool menu_villaggio = true;
    Text(5);

    int mission_selector = player01.mission_selector;               // default 6, toccare solo per debugging
    int mission_selector_range = player01.mission_selector_range;   // default 7, non toccare

    do{
        printf("Seleziona una delle opzioni del menu [1-5]: ");
        int choice_villaggio = 0;
        int choice_missione = 0;
        int buf_size = 2;
        choice_villaggio = InputHandlerInt(buf_size);
        switch (choice_villaggio) { // Implementazione logica del menu di selezione missione
            case 1: //intraprendi una missione, si apre il menu di scelta missione
                clear();
                Text(mission_selector);
                do{
                    Text(mission_selector + mission_selector_range);
                    choice_missione = InputHandlerInt(buf_size);
                    switch(choice_missione) {
                        case 1:
                            if(mission_selector == 6 || mission_selector == 9 || mission_selector == 10 || mission_selector == 11){
                                clear();
                                printf("\nBenvenuto nella palude putrescente!\n");

                                if(mission_selector == 6 || mission_selector == 11){
                                    player01.mission_selector += 1;
                                }
                                else if(mission_selector == 9){
                                    player01.mission_selector -= 1;
                                }

                                game(CheatMode, player01); 
                                //palude_putrescente();
                            }
                            else if(mission_selector == 7 || mission_selector == 12){
                                clear();
                                printf("\nBenvenuto nella magione infestata!\n");

                                if(mission_selector == 7){
                                    player01.mission_selector += 1;
                                }

                                game(CheatMode, player01);
                                //magione_infestata();
                            }
                            else if(mission_selector == 8){
                                clear();
                                printf("\nBenvenuto nella grotta di cristallo!\n");
                                game(CheatMode, player01);
                                //grotta_di_cristallo();
                            }                          
                            break;
                        case 2:
                            if(mission_selector == 6 || mission_selector == 11){
                                clear();
                                printf("\nBenvenuto nella magione infestata!\n");

                                if(mission_selector == 6){
                                    player01.mission_selector += 3;
                                }
                                else if(mission_selector == 11){
                                    player01.mission_selector -= 1;
                                }

                                game(CheatMode, player01);
                                //magione_infestata();
                            }
                            else if(mission_selector == 7 || mission_selector == 9){
                                clear();
                                printf("\nBenvenuto nella grotta di cristallo!\n");

                                if(mission_selector == 7){
                                    player01.mission_selector += 5;
                                }
                                else if(mission_selector == 9){
                                    player01.mission_selector += 1;
                                }

                                game(CheatMode, player01);
                                //grotta_di_cristallo();
                            }
                            else{
                                clear();
                                break;
                            }
                            break;
                        case 3:
                            if(mission_selector == 6){
                                clear();
                                printf("\nBenvenuto nella grotta di cristallo!\n");

                                player01.mission_selector += 5;

                                game(CheatMode, player01);
                                //grotta_di_cristallo();
                            }
                            else{
                                clear();
                                break;
                            }
                            break;

                        default:
                            clear();
                            break;
                    }
                }while(true);
                clear(); 
                break;
            case 2: // riposo ripristina 20 punti vita
                getchar();
                player01.life = 20;
                printf("\nI tuoi punti vita sono stati ripristinati!\n");
                break;
            case 3: //implementa inventario
                break;
            case 4: //implementa salvataggio
                char SaveStats[BUF];
                //DEBUG
                //player01.life = 17;
                //player01.money = 72;
                //player01.items = 9;
                //player01.CompletedMissions = 2;
                //DEBUG
                snprintf(SaveStats, BUF, ", %02d P . VITA , %03d MONETE , %02d OGGETTI , %01d MISSIONI COMPLETATE\n", player01.life, player01.money, player01.items, player01.CompletedMissions);
                addSave(SaveStats);
                break;
            case 5: //uscita 
                getchar();
                Text(30);
                int conferma_uscita = 0;
                conferma_uscita = InputHandlerInt(buf_size);
                switch (conferma_uscita) {
                    case 1: 
                    menu_villaggio = false;
                    break;

                    case 2:
                    clear();
                    game(CheatMode, player01);

                    default:
                    clear();
                    printf("Scelta non valida!\n");
                    break;                
                }
            default:
                //clear();
                break;
        }
        clear();
    }while(menu_villaggio);    
    
    menu(CheatMode);
    
}