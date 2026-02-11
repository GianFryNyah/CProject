#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "DiceThrow.h"
#include "FileManipulator.h"
#include "InterfaceMethod.h"
#include "struct.h"
#include "PaludePutrescente.h"
#include "MagioneInfestata.h"
//#include "palude_putrescente.h"
#define BUF 128

/*typedef struct{
    int life;
    int money;
    int items;
    int CompletedMissions;
    int mission_selector;
    int mission_selector_range;
}player;*/

void game(player player01, int CheatMode);

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
                player NewPlayer = {20, 0, 0, 0, 6, 7, 0, false, false, false, false, false, false, false};
                game(NewPlayer, CheatMode);
            case 2:
                //mostra i salvataggi da poter caricare
                getchar();
                int Confirmation = 2;
                int SaveIndex = 0;
                int Option = 0;
                Text(51);
                //ShowSaves();
                newShowSaves();
                printf("\nSeleziona un salvataggio: ");
                //clear();
                int buf_size = 8;
                SaveIndex = InputHandlerInt(buf_size);
                player player01 = loadSave(SaveIndex);

                Text(60);
                printf("\nSeleziona un'opzione per il salvataggio %d: ", SaveIndex);
                Text(31);
                //printf("\n  1. Carica\n  2. Elimina\n");
                //printf("\nSeleziona opzione [1-2]: ");

                //clear();
                Option = InputHandlerInt(buf_size);
                switch (Option){
                    case 1:
                        //load save stats
                        //printf("\nLoading...");
                        //player player01 = loadSave(SaveIndex);

                        // DEBUG // DEBUG // DEBUG
                        // DEBUG // DEBUG // DEBUG
                        printf("\n%d Punti Vita, ", player01.life);
                        printf("%d Monete, ", player01.money);
                        printf("%d Oggetti, ", player01.items);
                        printf("%d Missioni completate, ", player01.CompletedMissions);
                        printf("Missione Palude: %s , ", (player01.palude) ? "Completata" : "Non completata");
                        printf("Missione Magione: %s , ", (player01.magione) ? "Completata" : "Non completata");
                        printf("Missione Grotta: %s", (player01.grotta) ? "Completata\n" : "Non completata\n");
                        printf("Ha l'armatura?: %s , ", (player01.armor) ? "Si'" : "No");
                        printf("Ha la Spada?: %s , ", (player01.sword) ? "Si'" : "No");
                        printf("Ha la Spada dell'Eroe?: %s , ", (player01.heroSword) ? "Si'" : "No");
                        printf("Numero Pozioni: %d\n", player01.potions);
                        // DEBUG // DEBUG // DEBUG
                        // DEBUG // DEBUG // DEBUG

                        game(player01, CheatMode);
                        //here ask for additional enter, to fix ( maybe ?)
                        break;
                    case 2:
                        //delete selected save from save file
                        Text(52);
                        Confirmation = InputHandlerInt(buf_size);
                        if(Confirmation == 1){
                            deleteSave(SaveIndex);
                            Text(60);
                            printf("\nEliminazione del salvataggio numero %d avvenuta con successo!\n", SaveIndex);
                            printf("\n");
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
                clear();
                if (CheatMode == 2){
                    int Num = 0;
                    newShowSaves();
                    printf("\nSeleziona un salvataggio: ");
                    Num = InputHandlerInt(8);
                    int life = 0; int money = 0;
                    printf("Nuovi Punti Vita: ");
                    life = InputHandlerInt(8);
                    printf("Nuovo saldo Monete: ");
                    money = InputHandlerInt(8);
                    Cheats(Num, life, money);
                    printf("\nSalvataggio modificato con successo!\n");
                    printf("\n");
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

void game(player player01, int CheatMode){
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
        Text(32); // prompt selezione opzione menu del villaggio
        int choice_villaggio = 0;
        int choice_missione = 0;
        int buf_size = 2;
        char SaveStats[BUF];

        choice_villaggio = InputHandlerInt(buf_size);

        // Implementazione logica del menu di selezione missione
        switch (choice_villaggio) {
            case 1: //intraprendi una missione, si apre il menu di scelta missione
                clear();
                Text(mission_selector);
                // do-while responsabile per l'interfaccia di selezione missione
                // include logiche di gestione del menu' di selezione visualizzato in output
                do{
                    Text(mission_selector + mission_selector_range);
                    choice_missione = InputHandlerInt(buf_size);
                    switch(choice_missione) {
                        // logiche delle possibili missioni da visualizzare come scelta numero 1
                        case 1:
                            if(mission_selector == 6 || mission_selector == 9 || mission_selector == 10 || mission_selector == 11){
                                clear();
                                //printf("\nBenvenuto nella palude putrescente!\n");

                                //INIZIO MISSIONE
                                int Pdungeon_rooms[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                                int* RoomPointer;
                                PaludePutrescenteIsCompleted = palude_putrescente(&player01, Pdungeon_rooms, RoomPointer);
                                // logica di rilevazione Missione Superata con Successo o Game Over ( player.life <= 0 )
                                if(!PaludePutrescenteIsCompleted){
                                    // La funzione palude_putrescente() torna false, il player e' incorso in un Game Over
                                    // Richiamo direttamente la funzione menu(), ricomincio da capo e torno al Menu Principale
                                    menu(CheatMode);
                                }

                                player01.palude = true;
                                player01.CompletedMissions += 1;

                                if(mission_selector == 6 || mission_selector == 11){
                                    player01.mission_selector += 1;
                                }
                                else if(mission_selector == 9){
                                    player01.mission_selector -= 1;
                                }

                                game(player01, CheatMode); 
                                //palude_putrescente();
                            }
                            else if(mission_selector == 7 || mission_selector == 12){
                                clear();
                                //INIZIO MISSIONE
                                int Mdungeon_rooms[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                                int* RoomPointer;
                                MagioneInfestataIsCompleted = magione_infestata(&player01, Mdungeon_rooms, RoomPointer);
                                // logica di rilevazione Missione Superata con Successo o Game Over ( player.life <= 0 )
                                if(!MagioneInfestataIsCompleted){
                                    // La funzione magione_infestata() torna false, il player e' incorso in un Game Over
                                    // Richiamo direttamente la funzione menu(), ricomincio da capo e torno al Menu Principale
                                    menu(CheatMode);
                                }

                                player01.magione = true;
                                player01.CompletedMissions += 1;

                                if(mission_selector == 7){
                                    player01.mission_selector += 1;
                                }

                                game(player01, CheatMode);
                                //magione_infestata();
                            }
                            else if(mission_selector == 8){
                                clear();
                                printf("\nBenvenuto nella grotta di cristallo!\n");
                                game(player01, CheatMode);
                                //grotta_di_cristallo();
                            }                          
                            break;
                        case 2:
                            if(mission_selector == 6 || mission_selector == 11){
                                clear();
                                //INIZIO MISSIONE
                                int Mdungeon_rooms[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                                int* RoomPointer;
                                MagioneInfestataIsCompleted = magione_infestata(&player01, Mdungeon_rooms, RoomPointer);
                                // logica di rilevazione Missione Superata con Successo o Game Over ( player.life <= 0 )
                                if(!MagioneInfestataIsCompleted){
                                    // La funzione palude_putrescente() torna false, il player e' incorso in un Game Over
                                    // Richiamo direttamente la funzione menu(), ricomincio da capo e torno al Menu Principale
                                    menu(CheatMode);
                                }

                                player01.magione = true;
                                player01.CompletedMissions += 1;

                                if(mission_selector == 6){
                                    player01.mission_selector += 3;
                                }
                                else if(mission_selector == 11){
                                    player01.mission_selector -= 1;
                                }

                                game(player01, CheatMode);
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

                                game(player01, CheatMode);
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

                                game(player01, CheatMode);
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
                player01.life = 20;
                Text(33);
                break;
            case 3: //implementa inventario
                clear();
                inventario(&player01, buf_size);
                game(player01, CheatMode);
            case 4: //implementa salvataggio
                //DEBUG
                //player01.life = 17;
                //player01.money = 72;
                //player01.items = 9;
                //player01.CompletedMissions = 2;
                //DEBUG
                snprintf(SaveStats, BUF, ", %02d P . VITA , %03d MONETE , %02d OGGETTI , %01d MISSIONI COMPLETATE %d%d%d%d%d%d%d%d%d \n", player01.life, player01.money, player01.items, player01.CompletedMissions, player01.palude, player01.magione, player01.grotta, player01.CastleKey, player01.armor, player01.sword, player01.heroSword, player01.mission_selector, player01.potions);
                addSave(SaveStats);
                Text(53);
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
                    game(player01, CheatMode);

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