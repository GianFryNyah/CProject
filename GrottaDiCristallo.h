#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Questo header contiene la funzione responsabile dell'esecuzione della missione Grotta di Cristallo
// Prende come parametro un puntatore al tipo player, un puntatore ad un array gia' inizializzato ed un puntatore ad un intero
// l'array dungeon_rooms contiene dieci interi che rappresentano il nemico
// RoomPointer viene fatto puntare al primo elemento di dungeon_rooms
// Per ogni stanza esplorata con successo RoomPointer puntera' alla prossima stanza
// La funzione della missione si appoggia ad appositi metodi per la gestione di eventi, trappole e combattimento
// essi sono presenti presso l'header InterfaceMethod.h che e' incluso presso Interfaces.h
// questo header e' incluso presso Interfaces.h e la funzione missione e sempre li' invocata
bool grotta_di_cristallo(player* player01, int* dungeon_rooms, int* RoomPointer) {
    bool exitDoWhile = false;

    // variabili di supporto per funzionalita' MENU'
    int choice_grotta = 0; 
    int room = 0;
    int MenuNegozio = 22;
    int choiceMenuNegozio = 26;
    int buf_size = 2;

    Text(41);
    Text(44);
    printf("\nStato di avanzamento : Nessun progresso");
    Text(20);
    
    rooms_generator_grotta(dungeon_rooms);
    RoomPointer = dungeon_rooms;
    
    // do-while nel quale si svolgera' la missione, termina solo quando la missione deve finire ( Superamento Missione, ritorno al Menu' del Villaggio, Game Over )
    do{
        // scope interno DO-WHILE

        // inizializzo il tipo foe ( Il Drago Antico )
        // sara' passato insieme al tipo player alla funzione combattimento_drago(player* x, foe drago_antico)
        // quest'ultima e' una variazione di combattimento(player* x, foe y) che fa uso di metodi speciali
        foe drago_antico = {"Drago Antico", 5, 10, 12};

        // prompt scelta da selezionare, da ripetersi fino ad input valido
        Text(21); // scelta tra 1 e 4 compresi
        choice_grotta = InputHandlerInt(buf_size);

        // Implementazione logica del Menu' di Missione
        switch(choice_grotta){
            case 1:
            // ESPLORAZIONE STANZA DEL DUNGEON

                room = *RoomPointer;

                switch(room){
                    case 1:
                        // stanza trappola
                        StanzaVuotaEvent(player01);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 2:
                        // stanza trappola
                        CristalliCadentiEvent(player01);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 3:
                        // stanza trappola
                        PontePericolanteEvent(player01);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 4:
                        // stanza trappola
                        ForziereMisteriosoEvent(player01);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 5:
                        // stanza trappola
                        RupeScoscesaEvent(player01);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 6:
                        // si incontra un nemico, chiamo la funzione combattimento che gestisce le dinamiche di combattimento
                        combattimento_drago(player01, drago_antico);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        else{
                            // sconfiggendo il drago ottieni la Spada dell'Eroe
                            player01->heroSword = true;
                        }
                        printf("");
                        break;
                }
                Text(60);
                RoomPointer++; // Passo alla prossima stanza incrementando il puntatore, puntera' cosi' al secondo elemento dell'array
                printf("");
                break;
            case 2:
                // NEGOZIO
                clear();
                negozio(player01, MenuNegozio, choiceMenuNegozio, buf_size);
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

        if(player01->heroSword){
            Text(46); sleep(1);
            exitDoWhile = true;
        }
    
        if(!exitDoWhile){
            Text(41);
            Text(44);
            printf("\nStato di avanzamento : Nessun progresso");
            Text(20);
        }

    } while(!exitDoWhile);
    return true;
}