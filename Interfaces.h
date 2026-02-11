#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "DiceThrow.h"
#include "FileManipulator.h"
#include "InterfaceMethod.h"
#include "struct.h"
#include "PaludePutrescente.h"
#include "MagioneInfestata.h"
#include "GrottaDiCristallo.h"
#include "SignoreOscuro.h"
#define BUF 128

// l'header principale incluso nel main() del codice sorgente del programma
// I suoi tre metodi sono i piu' importanti ed usati del programma
// Questo header contiene tutti i metodi responsabili del corretto funzionamento delle interfacce di gioco ( menu' principale, menu' del villaggio )
// sono qui inclusi tutti gli header del progetto

// Viene invocata da menu(int x) quando si deve iniziare una partita
// questa funzione riceve la struct player inizializzata contenente le statistiche di gioco, e l'intero CheatMode che servira' per eventuali ritorni al menu' principale ( l'opzione Cheat permane )
// dentro game(player x, int CheatMode y) vengono invocate tutte le quattro funzioni missione descritte dal progetto
// quest'ultime si occuperanno del corretto funzionamento delle logiche di missione e termineranno sempre e solo dentro game(player x, int y)
void game(player player01, int CheatMode);

// Menu' Principale
// Qui e' implementata la logica di funzionamento del menu e l'attivazione dell'opzione trucchi
// Qui sono chiamate tutte le funzioni apposite alla manipolazione dei salvataggi, presenti nell'header FileManipulator.h qui incluso
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
                        game(player01, CheatMode);
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
                        menu(CheatMode);
                }
                break;
            case 3:
                //trucchi
                //accessibile con Konami's code
                clear();
                if (CheatMode == 2){
                    int Num = 0;
                    newShowSaves();
                    printf("\nSeleziona un salvataggio: ");
                    Num = InputHandlerInt(8);
                    int life = 0; int money = 0; int conad = 0;
                    printf("Nuovi Punti Vita: ");
                    life = InputHandlerInt(8);
                    printf("Nuovo saldo Monete: ");
                    money = InputHandlerInt(8);
                    bool missione_finale = false;
                    printf("Vuoi sbloccare la Missione Finale, l'incontro contro il Signore Oscuro?\n");
                    printf("\n  1. Si'\n");
                    printf("\nSeleziona opzione [1] o altro tasto per rifiutare: ");
                    conad = InputHandlerInt(8);
                    if(conad==1){missione_finale = true;}
                    Cheats(Num, life, money, missione_finale);
                    printf("\nSalvataggio modificato con successo!\n");
                    printf("\n");
                    menu(CheatMode);
                }
                break;
            case 4:
                exit(0);
            default:
                clear();
                break;
        }
    }while(true);
}

void game(player player01, int CheatMode){
    bool PaludePutrescenteIsCompleted = false;
    bool MagioneInfestataIsCompleted = false;
    bool GrottaDiCristalloIsCompleted = false;
    
    
    bool menu_villaggio = true;
    Text(5);

    int mission_selector = player01.mission_selector;               // default 6, toccare solo per debugging
    int mission_selector_range = player01.mission_selector_range;   // default 7, non toccare

    if(player01.CompletedMissions == 3){
        mission_selector = 99;
    }

    do{
        Text(32); // prompt selezione opzione menu del villaggio
        int choice_villaggio = 0;
        int choice_missione = 0;
        int buf_size = 2;
        char SaveStats[BUF];

        choice_villaggio = InputHandlerInt(buf_size);

        // Implementazione logica del menu di selezione missione
        switch (choice_villaggio) {
            case 1:
            // INTRAPRENDI UNA MISSIONE
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
                                //INIZIO MISSIONE
                                int Gdungeon_rooms[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                                int* RoomPointer;
                                GrottaDiCristalloIsCompleted = grotta_di_cristallo(&player01, Gdungeon_rooms, RoomPointer);
                                // logica di rilevazione Missione Superata con Successo o Game Over ( player.life <= 0 )
                                if(!GrottaDiCristalloIsCompleted){
                                    // La funzione grotta_di_cristallo() torna false, il player e' incorso in un Game Over
                                    // Richiamo direttamente la funzione menu(), ricomincio da capo e torno al Menu Principale
                                    menu(CheatMode);
                                }

                                player01.grotta = true;
                                player01.CompletedMissions += 1;

                                game(player01, CheatMode);
                                //grotta_di_cristallo();
                            }
                            else if(mission_selector == 99){
                                clear();
                                bool win;
                                win = missione_finale();
                                if(!win){
                                    menu(CheatMode);
                                }
                                printf("\n\t |  C O N G R A T U L A Z I O N I ! | \t\n");
                                menu(CheatMode);
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
                                //INIZIO MISSIONE
                                int Gdungeon_rooms[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                                int* RoomPointer;
                                GrottaDiCristalloIsCompleted = grotta_di_cristallo(&player01, Gdungeon_rooms, RoomPointer);
                                // logica di rilevazione Missione Superata con Successo o Game Over ( player.life <= 0 )
                                if(!GrottaDiCristalloIsCompleted){
                                    // La funzione grotta_di_cristallo() torna false, il player e' incorso in un Game Over
                                    // Richiamo direttamente la funzione menu(), ricomincio da capo e torno al Menu Principale
                                    menu(CheatMode);
                                }

                                player01.grotta = true;
                                player01.CompletedMissions += 1;

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
                                //INIZIO MISSIONE
                                int Gdungeon_rooms[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                                int* RoomPointer;
                                GrottaDiCristalloIsCompleted = grotta_di_cristallo(&player01, Gdungeon_rooms, RoomPointer);
                                // logica di rilevazione Missione Superata con Successo o Game Over ( player.life <= 0 )
                                if(!GrottaDiCristalloIsCompleted){
                                    // La funzione grotta_di_cristallo() torna false, il player e' incorso in un Game Over
                                    // Richiamo direttamente la funzione menu(), ricomincio da capo e torno al Menu Principale
                                    menu(CheatMode);
                                }

                                player01.grotta = true;
                                player01.CompletedMissions += 1;

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
            case 2:
            // RIPOSO
                player01.life = 20;
                Text(33);
                break;
            case 3: 
            // INVENTARIO
                clear();
                inventario(&player01, buf_size);
                game(player01, CheatMode);
            case 4:
            // SALVATAGGIO
                snprintf(SaveStats, BUF, ", %02d P . VITA , %03d MONETE , %02d OGGETTI , %01d MISSIONI COMPLETATE %d%d%d%d%d%d%d%d%d \n", player01.life, player01.money, player01.items, player01.CompletedMissions, player01.palude, player01.magione, player01.grotta, player01.CastleKey, player01.armor, player01.sword, player01.heroSword, player01.mission_selector, player01.potions);
                addSave(SaveStats);
                Text(53);
                break;
            case 5:
            // EXIT
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
                break;
        }
        clear();
    }while(menu_villaggio);    
    
    menu(CheatMode);
}