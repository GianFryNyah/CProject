#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool palude_putrescente(player* player01, int* dungeon_rooms, int* RoomPointer) {
    // template Menu' di Missione
    bool exitDoWhile = false;

    // variabili di supporto per funzionalita' MENU'
    int choice_palude = 0; 
    int room = 0;
    int MenuNegozio = 22;
    int choiceMenuNegozio = 26;
    int buf_size = 2;
    int objective = 0;

    srand(time(NULL));
    printf("\nObiettivo : Eliminare 3 Generale Orco");
    printf("\nStato di avanzamento : Eliminati %d su 3 Generale Orco", objective);
    Text(20);
    
    rooms_generator(dungeon_rooms);
    RoomPointer = dungeon_rooms;
    
    // do-while nel quale si svolgera' la missione, termina solo quando la missione deve finire ( Superamento Missione, ritorno al Menu' del Villaggio, Game Over )
    do{
        // scope interno DO-WHILE
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
            case 1:
                room = *RoomPointer;

                switch(room){
                    case 1:
                        combattimento(player01, cane_selvaggio);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        break;
                    case 2:
                        combattimento(player01, goblin);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        break;
                    case 3:
                        combattimento(player01, scheletro);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        break;
                    case 4:
                        combattimento(player01, orco);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        break;
                    case 5:
                        // stanza trappola
                        // il danno e' compreso tra 1 e 6 ed e' stabilito dal tiro del dado
                        AcquitrinoVelenosoEvent(player01);
                        // in questo if controllo se il player ha vita maggiore o minore-uguale a zero
                        if(player01->life <= 0){
                            // game over
                            return false;
                        }
                        break;
                    case 6:
                        // requisito per superare la missione: sconfiggerne tre

                        if(player01->sword){
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

        if(objective >= 1){
            clear();
            printf("\nL'Eroe ha sconfitto l'ultimo dei tre Generali Orco, la Missione e' stata portata a termine!"); sleep(1);
            exitDoWhile = true;
        }
    
        if(!exitDoWhile){
            printf("\nObiettivo : Eliminare 3 Generale Orco");
            printf("\nStato di avanzamento : Eliminati %d su 3 Generale Orco", objective);
            Text(20);
        }

        //clear();

    } while(!exitDoWhile);

    //printf("\nL'Eroe ha sconfitto l'ultimo dei tre Generali Orco, la Missione e' stata portata a termine!");
    //printf("Premi Enter per continuare: ");

    return true;
}