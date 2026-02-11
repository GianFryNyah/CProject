#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool magione_infestata(player* player01, int* dungeon_rooms, int* RoomPointer) {
    // template Menu' di Missione
    bool exitDoWhile = false;

    // variabili di supporto per funzionalita' MENU'
    int choice_magione = 0; 
    int room = 0;
    int MenuNegozio = 22;
    int choiceMenuNegozio = 26;
    int buf_size = 2;
    bool VampiroKill = false;

    srand(time(NULL));
    printf("\nObiettivo :  Recupera la chiave del Castello del Signore Oscuro e sconfiggi un Vampiro Superiore");
    if(VampiroKill){
        printf("\nStato di avanzamento : Vampiro Superiore sconfitto!");
    }
    else if(player01->CastleKey){
        printf("\nStato di avanzamento : Chiave del Castello del Signore Oscuro ottenuta!");
    }
    else{
        printf("\nStato di avanzamento : Nessun progresso");
    }
    // if per vampiro ammazzato e/o chiave ottenuta
    Text(20);
    
    rooms_generator_magione(dungeon_rooms);
    RoomPointer = dungeon_rooms;
    
    // do-while nel quale si svolgera' la missione, termina solo quando la missione deve finire ( Superamento Missione, ritorno al Menu' del Villaggio, Game Over )
    do{
        // scope interno DO-WHILE
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
            case 1:
                room = *RoomPointer;

                switch(room){
                    case 1:
                        // stanza trappola
                        // il danno e' 3
                        BotolaBuiaEvent(player01);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        break;
                    case 2:
                        combattimento(player01, pipistrello);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        break;
                    case 3:
                        combattimento(player01, zombie);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        break;
                    case 4:
                        combattimento(player01, fantasma);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        break;
                    case 5:
                        combattimento(player01, vampiro);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        else{
                            VampiroKill = true;
                        }
                        break;
                    case 6:
                        // requisito per superare la missione: sconfiggerne tre
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
                        break;
                }
                // DEBUG
                Text(60);
                RoomPointer++;
                printf("");
                break;
            case 2:
                // Negozio
                clear();
                negozio(player01, MenuNegozio, choiceMenuNegozio, buf_size);
                //clear();
                break;
            case 3:
                // Inventario
                clear();
                inventario(player01, buf_size);
                break;
            case 4:
                // DEBUG DEBUG DEBUG DEBUG
                player01->money = 50;
                // DEBUG DEBUG DEBUG DEBUG
                // struttura che controlla che il giocatore intenzionato a tornare al menu' del villaggio abbia le monete minime necessaria
                if(player01->money >= 50){
                    player01->money -= 50;
                    clear();
                    // il giocatore viene riportato al menu' del villaggio richiamando game
                    // il gioco si comportera' correttamente come se la missione non fosse stata completata
                    return true;
                }
                else{
                    // testo che ricorda che il giocatore non ha abbastanza monete
                    Text(50);
                }
                break;
            default:
                break;
            // FINE SWITCH
        }

        if(VampiroKill && (player01->CastleKey)){
            clear();
            printf("\nL'Eroe ha sconfitto Il Vampiro Custode e ottenuto la Chiave del Castello del Signore Oscuro\nla Missione e' stata portata a termine!"); sleep(1);
            exitDoWhile = true;
        }
    
        if(!exitDoWhile){
            printf("\nObiettivo :  Recupera la chiave del Castello del Signore Oscuro e sconfiggi un Vampiro Superiore");
            if(VampiroKill){
                printf("\nStato di avanzamento : Vampiro Superiore sconfitto!");
            }
            else if(player01->CastleKey){
                printf("\nStato di avanzamento : Chiave del Castello del Signore Oscuro ottenuta!");
            }
            else{
                printf("\nStato di avanzamento : Nessun progresso");
            }
            Text(20);
        }

        //clear();

    } while(!exitDoWhile);

    return true;
}