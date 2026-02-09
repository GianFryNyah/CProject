#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "DiceThrow.h"
#include "FileManipulator.h"
#include "InterfaceMethod.h"
#include "struct.h"
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
                printf("\nCarica Salvataggio:\n");
                printf("\n");
                //ShowSaves();
                newShowSaves();
                printf("\nSeleziona un salvataggio: ");
                //clear();
                int buf_size = 8;
                SaveIndex = InputHandlerInt(buf_size);
                player player01 = loadSave(SaveIndex);

                printf("\nSeleziona un'opzione per il salvataggio %d: ", SaveIndex);
                printf("\n  1. Carica\n  2. Elimina\n");
                printf("\nSeleziona opzione [1-2]: ");
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

//bool palude_putrescente(player) {} //WORK IN PROGRESS
//void magione_infestata(void) {}
//void grotta_di_cristallo(void) {}

void palude_putrescente(player* player01, int* dungeon_rooms, int* RoomPointer, int CheatMode);

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
        printf("Seleziona una delle opzioni del menu [1-5]: ");
        int choice_villaggio = 0;
        int choice_missione = 0;
        int buf_size = 2;
        char SaveStats[BUF];

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

                                //INIZIO MISSIONE
                                int Pdungeon_rooms[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
                                int* RoomPointer;
                                palude_putrescente(&player01, Pdungeon_rooms, RoomPointer, CheatMode);
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
                                printf("\nBenvenuto nella magione infestata!\n");

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
                                printf("\nBenvenuto nella magione infestata!\n");

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
                printf("\nI tuoi punti vita sono stati ripristinati!\n");
                break;
            case 3: //implementa inventario
                break;
            case 4: //implementa salvataggio
                //DEBUG
                //player01.life = 17;
                //player01.money = 72;
                //player01.items = 9;
                //player01.CompletedMissions = 2;
                //DEBUG
                snprintf(SaveStats, BUF, ", %02d P . VITA , %03d MONETE , %02d OGGETTI , %01d MISSIONI COMPLETATE %d%d%d%d%d%d%d%d%d \n", player01.life, player01.money, player01.items, player01.CompletedMissions, player01.palude, player01.magione, player01.grotta, player01.CastleKey, player01.armor, player01.sword, player01.heroSword, player01.mission_selector, player01.potions);
                addSave(SaveStats);
                printf("\n\t Game saved successfully!\n\n");
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

void combattimento(player *player01, foe tipo_nemico, int CheatMode){

    printf("L'eroe incontra %s e inizia il combattimento.\n", tipo_nemico.nome_nemico);
                                             
    int risultato_dado = DiceThrow();
    int attacco_eroe = 0;
                        
    if (player01->sword == true && player01->armor == true){
        attacco_eroe = risultato_dado + 1; // spada
        tipo_nemico.danno_nemico--; // armatura
        while (attacco_eroe < tipo_nemico.colpo_fatale) {
            printf("Viene lanciato un dado per stabilire l'attacco dell'eroe.\n");
            printf("Il risultato e': %d\n", risultato_dado);
            printf("L'attacco dell'eroe aumenta di un punto grazie alla spada!");
            
            printf("Attacco non sufficiente per sconfiggere %s (%d < Colpo fatale = %d)\n", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale);
            player01->life -= tipo_nemico.danno_nemico;
            printf("Il danno inflitto dal nemico cala di un punto grazie all'armatura!\n");

            printf("%s infligge %d danni all'eroe! ", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico);
            printf("L'eroe rimane con %d punti vita.\n", (player01->life <= 0) ? 0 : player01->life);
            //printf("%s infligge %d danni all'eroe! L'eroe rimane con %d punti vita.", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico, player01->life);
                        
            if (player01->life <= 0) {
                printf("L'eroe e' stato sconfitto!\n");         
                clear();
                menu(CheatMode);
            }
            
            risultato_dado = DiceThrow();
            attacco_eroe = risultato_dado + 1;
        }
    } 
    else if (player01->sword == true) {
        attacco_eroe = risultato_dado + 1; // spada
        while (attacco_eroe < tipo_nemico.colpo_fatale) {
            printf("Viene lanciato un dado per stabilire l'attacco dell'eroe.\n");
            printf("Il risultato e': %d\n", risultato_dado);
            printf("L'attacco dell'eroe aumenta di un punto grazie alla spada!");
                            
            printf("Attacco non sufficiente per sconfiggere %s (%d < Colpo fatale = %d)\n", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale);
            player01->life -= tipo_nemico.danno_nemico;

            printf("%s infligge %d danni all'eroe! ", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico);
            printf("L'eroe rimane con %d punti vita.\n", (player01->life <= 0) ? 0 : player01->life);
                        
            if (player01->life <= 0) {
                printf("L'eroe e' stato sconfitto!\n");
                clear();
                menu(CheatMode);
            }
            risultato_dado = DiceThrow();
            attacco_eroe = risultato_dado + 1;
        }
    }
    else if (player01->armor == true) {
        tipo_nemico.danno_nemico--; // armatura
        attacco_eroe = risultato_dado;
        while (attacco_eroe < tipo_nemico.colpo_fatale) {
            printf("Viene lanciato un dado per stabilire l'attacco dell'eroe.\n");
            printf("Il risultato e': %d", risultato_dado);
                            
            printf("Attacco non sufficiente per sconfiggere %s (%d < Colpo fatale = %d)\n", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale);
            player01->life -= tipo_nemico.danno_nemico;
            printf("Il danno inflitto dal nemico cala di un punto grazie all'armatura!\n");

            //if (player01->life <= 0) player01->life = 0;

            printf("%s infligge %d danni all'eroe! ", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico);
            printf("L'eroe rimane con %d punti vita.\n", (player01->life <= 0) ? 0 : player01->life);
            //printf("%s infligge %d danni all'eroe! L'eroe rimane con %d punti vita.", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico, player01->life);
                        
            if (player01->life <= 0) {
                printf("L'eroe e' stato sconfitto!\n");
                clear();
                menu(CheatMode);
            }

            risultato_dado = DiceThrow();
            attacco_eroe = risultato_dado;
        }
    } 
    else {
        attacco_eroe = risultato_dado;
        while (attacco_eroe < tipo_nemico.colpo_fatale) {
            printf("Viene lanciato un dado per stabilire l'attacco dell'eroe.\n");
            printf("Il risultato e': %d", risultato_dado);
            
            printf("Attacco non sufficiente per sconfiggere %s (%d < Colpo fatale = %d)\n", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale);
            player01->life -= tipo_nemico.danno_nemico;

            printf("%s infligge %d danni all'eroe! ", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico);
            printf("L'eroe rimane con %d punti vita.\n", (player01->life <= 0) ? 0 : player01->life);
                        
            if (player01->life <= 0) {
                printf("L'eroe e' stato sconfitto!\n");
                clear();
                menu(CheatMode);
            }
            risultato_dado = DiceThrow();
            attacco_eroe = risultato_dado;
        }
    }
    
    printf("Viene lanciato un dado per stabilire l'attacco dell'eroe.\n");
    printf("Il risultato e': %d", risultato_dado);
    printf("%s viene sconfitto (%d >= Colpo fatale = %d)\n", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale);
    player01->money += tipo_nemico.monete_nemico;
    printf("%s infligge %d danni all'eroe! ", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico);
    printf("L'eroe rimane con %d punti vita.", (player01->life <= 0) ? 0 : player01->life);  
}

void rooms_generator(int* dungeon_rooms){
    //srand(time(NULL));
    int cnt = 0;
    int entropy;

    for(int i = 0; i < 10; i++){
        entropy = DiceThrow();
        if(cnt <= 3 && i <= 6){
            entropy = DiceThrow();
            dungeon_rooms[i] = DiceThrow();
            entropy = DiceThrow();
            if(dungeon_rooms[i] == 6){
                cnt++;
            }
        }
        else if(cnt == 3){
            dungeon_rooms[i] = 0;
        }
        else if(cnt >= 1 && i <= 7){
            entropy = DiceThrow();
            dungeon_rooms[i] = DiceThrow();
            entropy = DiceThrow();
            if(dungeon_rooms[i] == 6){
                cnt++;
            }
        }
        else if(cnt >= 2 && i <= 8){
            entropy = DiceThrow();
            dungeon_rooms[i] = DiceThrow();
            entropy = DiceThrow();
            if(dungeon_rooms[i] == 6){
                cnt++;
            }
        }
        else{
            dungeon_rooms[i] = 6;
        }
    }
    
    return;
}

void palude_putrescente(player* player01, int* dungeon_rooms, int* RoomPointer, int CheatMode) {
    // template Menu' di Missione
    srand(time(NULL));
    Text(20);

    int objective = 0;

    rooms_generator(dungeon_rooms);
    RoomPointer = dungeon_rooms;
    
    // do-while nel quale si svolgera' la missione, uscire solo quando la missione deve finire
    do{
        // scope interno DO-WHILE

        // variabili di supporto per funzionalita' MENU'
        int choice_palude = 0;
        int choice_negozio = 0;
        int beneficio_pozione = 0;
        int buf_size = 2;
        int room = 0;

        foe cane_selvaggio = {"Cane Selvaggio", 2, 1, 0};
        foe goblin = {"Goblin", 3, 2, 2};
        foe scheletro = {"Scheletro", 4, 2, 4};
        foe orco = {"Orco", 3, 4, 6};
        foe accquitrino = {"Acquitrino Velenoso", 0, 0, 0};
        foe generale_orco = {"Generale Orco", 6, 3, 12};

        // prompt scelta da selezionare, da ripetersi fino ad input valido
        Text(21); // scelta tra 1 e 4 compresi
        choice_palude = InputHandlerInt(buf_size);

        switch(choice_palude){
            case 1:
                room = *RoomPointer;

                switch(room){
                    case 1:
                        combattimento(player01, cane_selvaggio, CheatMode);
                        break;
                    case 2:
                        combattimento(player01, goblin, CheatMode);
                        break;
                    case 3:
                        combattimento(player01, scheletro, CheatMode);
                        break;
                    case 4:
                        combattimento(player01, orco, CheatMode);
                        break;
                    case 5:
                        // stanza trappola
                        // il danno e' compreso tra 1 e 6 ed e' stabilito dal tiro del dado
                        combattimento(player01, accquitrino, CheatMode);
                        break;
                    case 6:
                        // requisito per superare la missione: sconfiggerne tre

                        if(player01->sword){
                            generale_orco.colpo_fatale = 5;
                            combattimento(player01, generale_orco, CheatMode);
                            objective++;
                        }
                        else{
                            combattimento(player01, generale_orco, CheatMode);
                            objective++;
                        }
                        break;
                }
                
                printf("\n\nNumero di generali aaaa: %d\n\n", objective);
                RoomPointer++;
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                // DEBUG DEBUG DEBUG DEBUG
                player01->money = 50;
                // DEBUG DEBUG DEBUG DEBUG
                if(player01->money >= 50){
                    player01->money -= 50;
                    clear();
                    game(*player01, CheatMode);
                }
                else{
                    Text(50);
                }
                break;
            default:
                break;
            // FINE SWITCH
        }

        if(objective >= 1){
            clear();
            return;
        }

        clear();
    
    } while(true);

    // scope palude_putrescente(), si esegue il codice seguente solo a fine missione
    printf("!!!!!!!!!!!!!!!");

    return;
}