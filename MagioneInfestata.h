#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Questo header contiene la funzione responsabile dell'esecuzione della missione Magione Infestata
// Prende come parametro un puntatore al tipo player, un puntatore ad un array gia' inizializzato ed un puntatore ad un intero
// l'array dungeon_rooms contiene dieci interi che rappresentano il nemico
// RoomPointer viene fatto puntare al primo elemento di dungeon_rooms
// Per ogni stanza esplorata con successo RoomPointer puntera' alla prossima stanza
// La funzione della missione si appoggia ad appositi metodi per la gestione di eventi, trappole e combattimento
// essi sono presenti presso l'header InterfaceMethod.h che e' incluso presso Interfaces.h
// questo header e' incluso presso Interfaces.h e la funzione missione e sempre li' invocata
bool magione_infestata(player* player01, int* dungeon_rooms, int* RoomPointer) {
    bool exitDoWhile = false;

    // variabili di supporto per funzionalita' MENU'
    int choice_magione = 0; 
    int room = 0;
    int MenuNegozio = 22;
    int choiceMenuNegozio = 26;
    int buf_size = 2;
    bool VampiroKill = false;

    Text(40);
    Text(35); if(VampiroKill){printf("\nStato di avanzamento : Vampiro Superiore sconfitto!");}
    else if(player01->CastleKey){printf("\nStato di avanzamento : Chiave del Castello del Signore Oscuro ottenuta!");}
    else{printf("\nStato di avanzamento : Nessun progresso");}
    Text(20);
    
    rooms_generator_magione(dungeon_rooms);
    RoomPointer = dungeon_rooms;
    
    // do-while nel quale si svolgera' la missione, termina solo quando la missione deve finire ( Superamento Missione, ritorno al Menu' del Villaggio, Game Over )
    do{
        // scope interno DO-WHILE

        // inizializzo tutti i tipi foe ciascuno per ogni possibile nemico
        // sara' passato insieme al tipo player alla funzione combattimento(player* x, foe y)
        foe pipistrello = {"Pipistrello", 2, 2, 1};
        foe zombie = {"Zombie", 3, 2, 2};
        foe fantasma = {"Fantasma", 5, 2, 4};
        foe vampiro = {"Vampiro Superiore", 4, 4, 7};
        foe demone = {"Demone Custode", 4, 6, 10};

        // prompt scelta da selezionare, da ripetersi fino ad input valido
        Text(21); // scelta tra 1 e 4 compresi
        choice_magione = InputHandlerInt(buf_size);

        // Implementazione logica del Menu' di Missione
        switch(choice_magione){
        // ESPLORAZIONE STANZA DEL DUNGEON
            case 1:
                room = *RoomPointer;

                switch(room){
                    case 1:
                        // stanza trappola
                        BotolaBuiaEvent(player01);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 2:
                        // si incontra un nemico, chiamo la funzione combattimento che gestisce le dinamiche di combattimento
                        combattimento(player01, pipistrello);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 3:
                        // si incontra un nemico, chiamo la funzione combattimento che gestisce le dinamiche di combattimento
                        combattimento(player01, zombie);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 4:
                        // si incontra un nemico, chiamo la funzione combattimento che gestisce le dinamiche di combattimento
                        combattimento(player01, fantasma);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        clear();
                        break;
                    case 5:
                        // si incontra un nemico, chiamo la funzione combattimento che gestisce le dinamiche di combattimento
                        combattimento(player01, vampiro);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        else{
                            VampiroKill = true;
                        }
                        clear();
                        break;
                    case 6:
                        // si incontra un nemico, chiamo la funzione combattimento che gestisce le dinamiche di combattimento
                        combattimento(player01, demone);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        else{
                            // sconfiggendo il demone ottieni la chiave del Castello
                            player01->CastleKey = true;
                        }
                        clear();
                        break;
                }
                Text(60);
                RoomPointer++;
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
                    Text(50);
                }
                break;
                clear();
            default:
                clear();
                break;
            // FINE SWITCH
        }

        if(VampiroKill && (player01->CastleKey)){
            clear();
            Text(43); sleep(1);
            exitDoWhile = true;
        }
    
        if(!exitDoWhile){
            Text(40);
            Text(35); if(VampiroKill){printf("\nStato di avanzamento : Vampiro Superiore sconfitto!");}
            else if(player01->CastleKey){printf("\nStato di avanzamento : Chiave del Castello del Signore Oscuro ottenuta!");}
            else{printf("\nStato di avanzamento : Nessun progresso");}
            Text(20);
        }

    } while(!exitDoWhile);
    return true;
}