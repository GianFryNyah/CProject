#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void clear(void)
{
    while ( getchar() != '\n' );
}

int InputHandlerInt(int buf_size){
    char *endptr;
    char buff[buf_size];
    fgets(buff, sizeof(buff), stdin);
    return strtol(buff, &endptr, 10);
}

void Text(int code){
    switch (code){
        // OPZIONI MENU' PRINCIPALE
        case 1:
            Text(60);
            printf("\nMenu Principale:\n");
            printf("\n  1. Nuova Partita\n  2. Carica Salvataggio\n");
            break;
        case 2:
            Text(60);
            printf("\nMenu Principale:\n");
            printf("\n  1. Nuova Partita\n  2. Carica Salvataggio\n  3. Trucchi\n");
            break;
        case 3:
            printf("Seleziona una delle opzioni del Menu Principale [1-2]: ");
            break;
        case 4:
            printf("Seleziona una delle opzioni del Menu Principale [1-3]: ");
            break;
        case 5:
            Text(60);
            printf("Menu del Villaggio:\n");
            printf("\n  1. Intraprendi una missione\n  2. Riposati\n  3. Inventario\n  4. Salva la partita\n  5. Esci\n");
            break;
        // FINE OPZIONI MENU' PRINCIPALE
        
        // MENU' SCELTA MISSIONE
        case 6: // P M G
            Text(60);
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Palude Putrescente\n  2. Magione Infestata\n  3. Grotta di Cristallo\n");
            break;
        case 7: // M G
            Text(60);
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Magione Infestata\n  2. Grotta di Cristallo\n");
            break;
        case 8: // G
            Text(60);
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Grotta di Cristallo\n");
            break;
        case 9: // P G
            Text(60);
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Palude Putrescente\n  2. Grotta di Cristallo\n");
            break;
        case 10: // P
            Text(60);
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Palude Putrescente\n");
            break;
        case 11: // P M
            Text(60);
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Palude Putrescente\n  2. Magione Infestata\n");
            break;
        case 12: // M
            Text(60);
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Magione Infestata\n");
            break;
        // FINE MENU' SCELTA MISSIONE

        // OPZIONE MENU SCELTA MISSIONE
        case 13:
            printf("Seleziona una delle opzioni [1-3]: ");
            break;
        case 14:
            printf("Seleziona una delle opzioni [1-2]: ");
            break;
        case 15:
            printf("Seleziona una delle opzioni [1]: ");
            break;
        case 16:
            printf("Seleziona una delle opzioni [1-2]: ");
            break;
        case 17:
            printf("Seleziona una delle opzioni [1]: ");
            break;
        case 18:
            printf("Seleziona una delle opzioni [1-2]: ");
            break;
        case 19:
            printf("Seleziona una delle opzioni [1]: ");
            break;
        // FINE MENU' SCELTA MISSIONE

        // MENU' DI MISSIONE, NEGOZIO ED INVENTARIO
        case 20:
            Text(60);
            printf("\nMenu di missione:\n");
            printf("1. Esplora stanza del Dungeon\n");
            printf("2. Negozio\n");
            printf("3. Inventario\n");
            printf("4. Torna al Villaggio (Paga 50 monete)\n");
            break;
        case 21:
            printf("\nSeleziona una delle opzioni del Menu di Missione [1-4]: ");
            break;
        case 22:
            Text(60);
            printf("\n\t\t\t|  N E G O Z I O  |");
            printf("\nAcquista un oggetto:\n");
            printf("1. Pozione curativa\t| Prezzo per unita': 4\n");
            printf("2. Spada\t\t| Prezzo per unita': 5 ( Una sola unita' disponibile )\n");
            printf("3. Armatura\t\t| Prezzo per unita': 10 ( Una sola unita' disponibile )\n");
            printf("4. Esci dal Negozio\n");
            break;
        case 23:
            printf("\n\t\t\t|  N E G O Z I O  |");
            printf("\nAcquista un oggetto:\n");
            printf("1. Pozione curativa\t| Prezzo per unita': 4\n");
            printf("2. Armatura\t\t| Prezzo per unita': 10 ( Una sola unita' disponibile )\n");
            printf("3. Esci dal Negozio\n");
            break;
        case 24:
            printf("\n\t\t\t|  N E G O Z I O  |");
            printf("\nAcquista un oggetto:\n");
            printf("1. Pozione curativa\t| Prezzo per unita': 4\n");
            printf("2. Spada\t\t| Prezzo per unita': 5 ( Una sola unita' disponibile )\n");
            printf("3. Esci dal Negozio\n");
            break;
        case 25:
            printf("\n\t\t\t|  N E G O Z I O  |");
            printf("\nAcquista un oggetto:\n");
            printf("1. Pozione curativa\t| Prezzo per unita': 4\n");
            printf("2. Esci dal Negozio\n");
            break;
        case 26:
            printf("\nSeleziona una delle opzioni del Negozio [1-4]: ");
            break;
        case 27:
            printf("\nSeleziona una delle opzioni del Negozio [1-3]: ");
            break;
        case 28:
            printf("\nSeleziona una delle opzioni del Negozio [1-2]: ");
            break;
        // FINE MENU' DI MISSIONE, NEGOZIO ED INVENTARIO

        // OPZIONI SCELTE VARI MENU
        case 30:
            Text(60);
            printf("\nStai uscendo dal gioco, ricordati di salvare la partita per non perdere i tuoi progressi. Sei sicuro di voler procedere?\n");
            printf("\n  1. Si\n  2. No\n");
            printf("\nSeleziona un'opzione [1-2]: ");
            break;
        case 31:
            printf("\n  1. Carica\n  2. Elimina\n");
            printf("\nSeleziona opzione [1-2]: ");
            break;
        case 32:
            printf("Seleziona una delle opzioni del menu [1-5]: ");
            break;
        case 33:
            Text(60);
            printf("\nI tuoi punti vita sono stati ripristinati!\n");
            printf("\n");
            Text(5);
            break;
        // FINE OPZIONI SCELTE VARI MENU

        // PROMPT MISSIONI
        case 34:
            printf("\n\t***MISSIONE COMPLETATA***\n");
            printf("\nL'Eroe ha sconfitto l'ultimo dei tre Generali Orco, la Missione e' stata portata a termine!");
            break;
        case 35:
            printf("\nObiettivo :  Recupera la chiave del Castello del Signore Oscuro e sconfiggi un Vampiro Superiore");
            break;
        case 36:
            printf("\nL'attacco dell'eroe aumenta di un punto grazie alla spada!\n");
            break;
        case 37:
            printf("\nIl danno inflitto dal nemico cala di un punto grazie all'armatura!\n");
            break;
        case 38:
            printf("Viene lanciato un dado per stabilire l'attacco dell'eroe:\n");
            break;
        case 39:
            printf("\nDungeon PALUDE PUTRESCENTE");
            break;
        case 40:
            printf("\nDungeon MAGIONE INFESTATA");
            break;
        case 41:
            printf("\nDungeon GROTTA DI CRISTALLO");
            break;
        case 42:
            printf("\nCASTELLO DEL SIGNORE OSCURO");
            break;
        case 43:
            printf("\n\t***MISSIONE COMPLETATA***\n");
            printf("\nL'Eroe ha sconfitto Il Vampiro Custode e ottenuto la Chiave del Castello del Signore Oscuro\nla Missione e' stata portata a termine!");
            break;
        // FINE PROMPT MISSIONI

        case 50:
            printf("\nNon hai abbastanza Monete!\n");
            sleep(1);
            break;
        case 51:
            Text(60);
            printf("\nCarica Salvataggio:\n");
            printf("\n");
            break;
        case 52:
            Text(60);
            printf("\nSei sicuro di voler eliminare definitivamente il salvataggio?");
            printf("\n  1. Si\n  2. No\n");
            printf("\nSeleziona opzione [1-2]: ");
            break;
        case 53:
            Text(60);
            printf("\n\t Game saved successfully!\n\n");
            Text(60);
            break;
        case 60:
            printf("\n-------------------------------------------------------------------------------\n");
        case 61:
            break;
        case 62:
            break;
        case 63:
            break;
        case 64:
            break;
    }
}

void rooms_generator_palude(int* dungeon_rooms){
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

void rooms_generator_magione(int* dungeon_rooms){
    //srand(time(NULL));
    int vampiro = 0;
    int demone = 0;
    int entropy;

    for(int i = 0; i < 8; i++){
        dungeon_rooms[i] = DiceThrow();
        if(dungeon_rooms[i] == 5){
            vampiro++;
        }
        else if(dungeon_rooms[i] == 5){
            demone++;
        }
    }
    if(vampiro == 0){
        dungeon_rooms[8] = 5;
    }
    if(demone == 0){
        dungeon_rooms[9] = 6;
    }
    
    return;
}

void combattimento(player *player01, foe tipo_nemico){

    Text(60);
    printf("L'eroe incontra un %s e inizia il combattimento!\n", tipo_nemico.nome_nemico); sleep(1);
    
    int dice_throw = DiceThrow();
    int attacco_eroe = dice_throw;

    if(player01->sword){
        attacco_eroe++;
    }
    if(player01->armor){
        tipo_nemico.danno_nemico--;
    }

    // ATTACCO NON SUFFICIENTE PER SCONFITTA AVVERSARIO
    while(attacco_eroe < tipo_nemico.colpo_fatale){
        Text(60); Text(38); // Viene lanciato un dado
        printf("Il risultato e': %d", dice_throw); sleep(1);
        if(player01->sword){Text(36);}

        Text(60);
        printf("Attacco non sufficiente per sconfiggere %s (%d < Colpo fatale = %d)\n", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale);
        player01->life -= tipo_nemico.danno_nemico;
        if(player01->armor){Text(37);}

        Text(60);
        printf("%s infligge %d danni all'eroe! ", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico); sleep(1);
        printf("L'eroe rimane con %d punti vita.\n", (player01->life <= 0) ? 0 : player01->life); sleep(1);
                        
        if (player01->life <= 0) {
            Text(60);
            printf("\tL'eroe e' stato sconfitto!\n"); sleep(1);
            Text(60);
            printf("\n\t=== GAME OVER ===\n"); sleep(1);
            clear();
            return;
        }
        dice_throw = DiceThrow();
        attacco_eroe = dice_throw;
    }

    // ATTACCO SUFFICIENTE PER SCONFITTA AVVERSARIO
    Text(38); // viene lanciato un dado
    printf("Il risultato e': %d", dice_throw); sleep(1);

    Text(60);
    printf("%s viene sconfitto (Attacco dell'Eroe: %d >= Colpo fatale = %d)", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale); sleep(1);
    player01->money += tipo_nemico.monete_nemico;

    return;
}

void negozio(player* player01, int MenuNegozio, int choiceMenuNegozio, int buf_size){
    // non ho ne' la spada ne' l'armatura
    if(!(player01->sword) && !(player01->armor)){
        Text(MenuNegozio); printf("\nSaldo Monete: %d", player01->money); Text(choiceMenuNegozio);
        int item_choice = InputHandlerInt(buf_size);
        switch(item_choice){
            case 1:
            // pozione curativa
                if((player01->money) >= 4){
                    player01->money -= 4;
                    player01->potions += 1;
                    printf("\nUna Pozione curativa e' stata aggiunta al tuo Inventario!\n");
                }
                else{
                    Text(50);
                }
                clear();
                break;
            case 2:
            // spada
                if((player01->money) >= 5){
                    player01->money -= 5;
                    player01->sword = true;
                    printf("\nLa Spada e' stata aggiunta al tuo Inventario!\n");
                }
                else{
                    Text(50);
                }
                clear();
                break;
            case 3:
            // armatura
                if((player01->money) >= 10){
                    player01->money -= 10;
                    player01->armor = true;
                    printf("\nL'Armatura e' stata aggiunta al tuo Inventario!\n");
                }
                else{
                    Text(50);
                }
                clear();
                break;
            case 4:
            // esci dal Negozio
                clear();
                break;
            default:
                printf("\nScelta non valida!\n");
                clear();
                break;
        }
    }
    // non ho la spada MA ho l'armatura
    else if(!(player01->sword) && (player01->armor)){
        Text(MenuNegozio + 2); printf("\nSaldo Monete: %d", player01->money); Text(choiceMenuNegozio + 1);
        int item_choice = InputHandlerInt(buf_size);
        switch(item_choice){
            case 1:
            // pozione curativa
                if((player01->money) >= 4){
                    player01->money -= 4;
                    player01->potions += 1;
                    printf("\nUna Pozione curativa e' stata aggiunta al tuo Inventario!\n");
                }
                else{
                    Text(50);
                }
                clear();
                break;
            case 2:
            // spada
                if((player01->money) >= 5){
                    player01->money -= 5;
                    player01->sword = true;
                    printf("\nLa Spada e' stata aggiunta al tuo Inventario!\n");
                }
                else{
                    Text(50);
                }
                clear();
                break;
            case 3:
            // esci dal Negozio
                clear();
                break;
            default:
                printf("\nScelta non valida!\n");
                clear();
                break;
        }
    }
    // non ho l'armatura MA ho la spada
    else if((player01->sword) && !(player01->armor)){
        Text(MenuNegozio + 1); printf("\nSaldo Monete: %d", player01->money); Text(choiceMenuNegozio + 1);
        int item_choice = InputHandlerInt(buf_size);
        switch(item_choice){
            case 1:
            // pozione curativa
                if((player01->money) >= 4){
                    player01->money -= 4;
                    player01->potions += 1;
                    printf("\nUna Pozione curativa e' stata aggiunta al tuo Inventario!\n");
                }
                else{
                    Text(50);
                }
                clear();
                break;
            case 2:
            // armatura
                if((player01->money) >= 10){
                    player01->money -= 10;
                    player01->armor = true;
                    printf("\nL'Armatura e' stata aggiunta al tuo Inventario!\n");
                }
                else{
                    Text(50);
                }
                clear();
                break;
            case 3:
            // esci dal Negozio
                clear();
                break;
            default:
                printf("\nScelta non valida!\n");
                clear();
                break;
        }
    }
    // ho sia la spada che l'armatura
    else{
        Text(MenuNegozio + 3); printf("\nSaldo Monete: %d", player01->money); Text(choiceMenuNegozio + 2);
        int item_choice = InputHandlerInt(buf_size);
        switch(item_choice){
            case 1:
            // pozione curativa
                if((player01->money) >= 4){
                    player01->money -= 4;
                    player01->potions += 1;
                    printf("\nUna Pozione curativa e' stata aggiunta al tuo Inventario!\n");
                }
                else{
                    Text(50);
                }
                clear();
                break;
            case 2:
            // esci dal Negozio
                clear();
                break;
            default:
                printf("\nScelta non valida!\n");
                clear();
                break;
        }
    }
    return;
}

void inventario(player* player01, int buf_size){
    Text(60);
    printf("\t\t\t|  STATISTICHE  GIOCATORE  |");
    Text(60);
    printf("Punti Vita: \t| \t%d\t |\n", player01->life);
    printf("Monete: \t| \t%d\t |", player01->money);
    Text(60);
    printf("\t\t\t|  I N V E N T A R I O  |");
    Text(60);
    printf("Pozioni Curative: \t| \t%d\t |\n", player01->potions);
    if(player01->sword){
        printf("Spada \t\t| \t+1 Attacco\n");
    }
    if(player01->armor){
        printf("Armatura \t| \t-1 Danno subito | Vecchia armatura abbandonata, potrebbe tornarmi utile |\n");
    }
    if(player01->heroSword){
        printf("Spada dell'Eroe \t| \t+2 Attacco | Una spada grande e lucente, incantata dalle proprieta' straordinarie |\n");
    }
    if(player01->CastleKey){
        printf("Chiave del Castello del Signore Oscuro \t| \tHo il presentimento che potrebbe tornarmi utile... |");
    }

    int usePotion = 0;
    printf("\nVuoi usare una Pozione Curativa?");
    printf("\n  1. Si\n  2. No\n");
    printf("\nSeleziona opzione [1-2]: ");
    usePotion = InputHandlerInt(buf_size);
    switch(usePotion){
        case 1:
            if(player01->potions < 1){
                printf("\nNon hai una Pozione Curativa da usare!\n");
                clear();
            }
            else{
                int throw = DiceThrow();
                player01->potions -= 1;
                if((player01->life + throw) > 20){
                    if(player01->life <= 20){ player01->life = 20;}
                    printf("La salute dell'Eroe e' salita di %d punti Vita ed e' arrivata al massimo!\n", throw);
                }
                else{
                    player01->life += throw;
                    printf("La salute dell'Eroe e' salita di %d punti Vita!\n", throw);
                }
                clear();
            }   
            break;
        case 2:
            clear();
            break;
        default:
            printf("\nScelta non valida!\n");
            clear();
            break;
        }
    
    //if(player01->potions < 0){
    //    printf("Press Enter to quit: ");
    //    int choice = getchar();
    //}
    //else{
        //getchar();
    //}
    //printf("");
    return;
}

void AcquitrinoVelenosoEvent(player* player01){
    int danno_nemico = DiceThrow();
    if(player01->armor){
        danno_nemico--;
    }
    Text(60);
    printf("L'Eroe cade in un Acquitrino Velenoso!\n"); sleep(1);
    player01->life -= danno_nemico;
    Text(60);
    printf("L'Eroe subisce %d danni!\n", danno_nemico); sleep(1);
    return;
}

void BotolaBuiaEvent(player* player01){
    int danno_nemico = 3;
    if(player01->armor){
        danno_nemico--;
    }
    Text(60);
    printf("L'Eroe cade in un Acquitrino Velenoso!\n"); sleep(1);
    player01->life -= danno_nemico;
    Text(60);
    printf("L'Eroe subisce %d danni!\n", danno_nemico); sleep(1);
    return;
}

bool padovan(int num) { // stabilisce se un numero appartiene alla sequenza di padovan e restituisce un valore di verità
    int seq_pad[500]; // questa funzione servirà per stabilire se un numero tra 1 e 500 appartiene alla sequenza, non sapendo quanti valori sono, riservo spazio per 500 interi
    seq_pad[0] = 1; //assegno i primi 3 valori della sequenza
    seq_pad[1] = 1;
    seq_pad[2] = 1;
    int contatore = 3; 
    for (int i = 3 ; i < 500; i++) { // in questo ciclo genero la sequenza di Padovan dei numeri fino a 500
        int new_num = seq_pad[i-2] + seq_pad[i-3];
        if (new_num > 500) break; // la sequenza mi serve fino al numero 500, quindi se lo supero esco dal ciclo e non genero ulteriori numeri
        seq_pad[i] = new_num; 
        contatore++; // tengo traccia di quanti numeri ho memorizzato
    }
    for (int i = 0; i < contatore; i++) { // controllo se il numero dato in input alla funzione è presente nella sequenza generata
        if (num == seq_pad[i]) {    
        //printf("Il numero %d appartiene alla sequenza di Padovan.\n", num); PER L'UTILIZZO CHE FAREMO DELLA FUNZIONE QUESTA STAMPA NON SERVE
        return true;
        } 
    }
// arrivo qui solamente se il numero non appartiene alla sequenza
// printf("Il numero %d non appartiene alla sequenza di Padovan.\n", num); PER L'UTILIZZO CHE FAREMO DELLA FUNZIONE QUESTA STAMPA NON SERVE
    return false;
}