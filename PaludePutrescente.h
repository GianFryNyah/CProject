#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Questo header contiene la funzione responsabile dell'esecuzione della missione Palude Putrescente
// Prende come parametro un puntatore al tipo player, un puntatore ad un array gia' inizializzato ed un puntatore ad un intero
// l'array dungeon_rooms contiene dieci interi che rappresentano il nemico
// RoomPointer viene fatto puntare al primo elemento di dungeon_rooms
// Per ogni stanza esplorata con successo RoomPointer puntera' alla prossima stanza
// La funzione della missione si appoggia ad appositi metodi per la gestione di eventi, trappole e combattimento
// essi sono presenti presso l'header InterfaceMethod.h che e' incluso presso Interfaces.h
// questo header e' incluso presso Interfaces.h e la funzione missione e sempre li' invocata
bool palude_putrescente(player* player01, int* dungeon_rooms, int* RoomPointer) {
    bool exitDoWhile = false;

    // variabili di supporto per funzionalita' MENU'
    int choice_palude = 0; 
    int room = 0;
    int MenuNegozio = 22;
    int choiceMenuNegozio = 26;
    int buf_size = 2;
    int objective = 0;

    Text(39);
    printf("\nObiettivo : Eliminare 3 Generale Orco");
    printf("\nStato di avanzamento : Eliminati %d su 3 Generale Orco", objective);
    Text(20);
    
    rooms_generator_palude(dungeon_rooms);
    RoomPointer = dungeon_rooms;
    
    // do-while nel quale si svolgera' la missione, termina solo quando la missione deve finire ( Superamento Missione, ritorno al Menu' del Villaggio, Game Over )
    do{
        // scope interno DO-WHILE

        // inizializzo tutti i tipi foe ciascuno per ogni possibile nemico
        // sara' passato insieme al tipo player alla funzione combattimento(player* x, foe y)
        foe cane_selvaggio = {"Cane Selvaggio", 2, 1, 0};
        foe goblin = {"Goblin", 3, 2, 2};
        foe scheletro = {"Scheletro", 4, 2, 4};
        foe orco = {"Orco", 3, 4, 6};
        foe generale_orco = {"Generale Orco", 6, 3, 12};

        // prompt scelta da selezionare, da ripetersi fino ad input valido
        Text(21); // scelta tra 1 e 4 compresi
        choice_palude = InputHandlerInt(buf_size);

        // Implementazione logica del Menu' di Missione
        switch(choice_palude){
        // ESPLORAZIONE STANZA DEL DUNGEON
            case 1:
                room = *RoomPointer;

                switch(room){
                    case 1:
                        // si incontra un nemico, chiamo la funzione combattimento che gestisce le dinamiche di combattimento
                        combattimento(player01, cane_selvaggio);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 2:
                        // si incontra un nemico, chiamo la funzione combattimento che gestisce le dinamiche di combattimento
                        combattimento(player01, goblin);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 3:
                        // si incontra un nemico, chiamo la funzione combattimento che gestisce le dinamiche di combattimento
                        combattimento(player01, scheletro);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 4:
                        // si incontra un nemico, chiamo la funzione combattimento che gestisce le dinamiche di combattimento
                        combattimento(player01, orco);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 5:
                        // stanza trappola
                        AcquitrinoVelenosoEvent(player01);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 6:
                        // si incontra un nemico, chiamo la funzione combattimento che gestisce le dinamiche di combattimento
                        if(player01->heroSword){
                            generale_orco.colpo_fatale = 5;
                            combattimento(player01, generale_orco);
                            // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                            if(player01->life <= 0){
                                // game over
                                return false;
                            }
                            objective++;
                        }
                        else{
                            combattimento(player01, generale_orco);
                            if(player01->life <= 0){
                                // game over
                                return false;
                            }
                            objective++;
                        }
                        clear();
                        break;
                }
                // DEBUG
                Text(60);
                RoomPointer++;
                printf("");
                break;
            case 2:
            // NEGOZIO
                clear();
                negozio(player01, MenuNegozio, choiceMenuNegozio, buf_size);
                //clear();
                break;
            case 3:
            // INVENTARIO
                clear();
                inventario(player01, buf_size);
                break;
            case 4:
                // struttura che controlla che il giocatore intenzionato a tornare al menu' del villaggio abbia le monete minime necessaria
                if(player01->money >= 50){
                    player01->money -= 50;
                    clear();
                    return true;
                }
                else{
                    // testo che ricorda che il giocatore non ha abbastanza monete
                    clear();
                    Text(50);
                }
                break;
            default:
                clear();
                break;
            // FINE SWITCH
        }

        if(objective >= 3){
            Text(34); sleep(1);
            exitDoWhile = true;
        }
    
        if(!exitDoWhile){
            Text(39);
            printf("\nObiettivo : Eliminare 3 Generale Orco");
            printf("\nStato di avanzamento : Eliminati %d su 3 Generale Orco", objective);
            Text(20);
        }

    } while(!exitDoWhile);
    return true;
}