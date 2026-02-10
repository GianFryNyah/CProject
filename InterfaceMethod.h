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
        //MENU'
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
        //FINE MENU'
        
        //MENU' SCELTA MISSIONE
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
        //FINE MENU' SCELTA MISSIONE

        //OPZIONE MENU SCELTA MISSIONE
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
        //FINE MENU' SCELTA MISSIONE
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
            printf("\nNegozio:\n");
            printf("1. Pozione curativa\t| Prezzo per unita': 4\n");
            printf("2. Spada\t\t| Prezzo per unita': 5 ( Una sola unita' disponibile )\n");
            printf("3. Armatura\t\t| Prezzo per unita': 10 ( Una sola unita' disponibile )\n");
            printf("4. Esci dal Negozio\n");
            break;
        case 23:
            printf("\nNegozio:\n");
            printf("1. Pozione curativa\t| Prezzo per unita': 4\n");
            printf("2. Armatura\t\t| Prezzo per unita': 10 ( Una sola unita' disponibile )\n");
            printf("3. Esci dal Negozio\n");
            break;
        case 24:
            printf("\nNegozio:\n");
            printf("1. Pozione curativa\t| Prezzo per unita': 4\n");
            printf("2. Spada\t\t| Prezzo per unita': 5 ( Una sola unita' disponibile )\n");
            printf("3. Esci dal Negozio\n");
            break;
        case 25:
            printf("\nNegozio:\n");
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
        //EXIT
        case 30:
            Text(60);
            printf("\nStai uscendo dal gioco, ricordati di salvare la partita per non perdere i tuoi progressi. Sei sicuro di voler procedere?\n");
            printf("\n  1. Si\n  2. No\n");
            printf("\nSeleziona un'opzione [1-2]: ");
            break;
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

    // CASO BASE
    while(attacco_eroe < tipo_nemico.colpo_fatale){
        Text(60);
        printf("Viene lanciato un dado per stabilire l'attacco dell'eroe:\n");
        //printf("\n");
        printf("Il risultato e': %d", dice_throw); sleep(1);
        //printf("\n");
        if(player01->sword){
            printf("L'attacco dell'eroe aumenta di un punto grazie alla spada!\n");
            //printf("\n");
        }
        
        Text(60);
        printf("Attacco non sufficiente per sconfiggere %s (%d < Colpo fatale = %d)\n", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale);
        //printf("\n");
        player01->life -= tipo_nemico.danno_nemico;
        if(player01->armor){
            printf("Il danno inflitto dal nemico cala di un punto grazie all'armatura!\n");
        }

        Text(60);
        printf("%s infligge %d danni all'eroe! ", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico); sleep(1);
        printf("L'eroe rimane con %d punti vita.\n", (player01->life <= 0) ? 0 : player01->life); sleep(1);
                        
        if (player01->life <= 0) {
            Text(60);
            printf("L'eroe e' stato sconfitto!\n"); sleep(1);
            Text(60);
            printf("\nGame Over\n"); sleep(1);
            clear();
            return;
        }
        dice_throw = DiceThrow();
        attacco_eroe = dice_throw;
    }

    printf("Viene lanciato un dado per stabilire l'attacco dell'eroe:\n");
    //printf("\n");
    printf("Il risultato e': %d", dice_throw); sleep(1);
    Text(60);
    printf("%s viene sconfitto (%d >= Colpo fatale = %d)", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale); sleep(1);
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
                break;
            case 4:
            // esci dal Negozio
                break;
            default:
                printf("\nScelta non valida!\n");
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
                break;
            case 3:
            // esci dal Negozio
                break;
            default:
                printf("\nScelta non valida!\n");
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
                break;
            case 3:
            // esci dal Negozio
                break;
            default:
                printf("\nScelta non valida!\n");
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
                break;
            case 2:
            // esci dal Negozio
                break;
            default:
                printf("\nScelta non valida!\n");
                break;
        }
    }
}

void inventario(player* player01, int buf_size){
    Text(60);
    printf("STATISTICHE GIOCATORE");
    Text(60);
    printf("Punti Vita: \t| \t%d\n", player01->life);
    printf("Monete: \t| \t%d", player01->money);
    Text(60);
    printf("INVENTARIO");
    Text(60);
    printf("Pozioni Curative: \t| \t%d\n", player01->potions);
    if(player01->sword){
        printf("Spada \t\t| \t+1 Attacco\n");
    }
    if(player01->armor){
        printf("Armatura \t| \t-1 Danno subito | Vecchia armatura abbandonata, potrebbe tornarmi utile\n");
    }
    if(player01->heroSword){
        printf("Spada dell'Eroe \t| \t+2 Attacco | Una spada grande e lucente, incantata dalle proprieta' straordinarie\n");
    }
    if(player01->CastleKey){
        printf("Chiave \t| \tHo il presentimento che potrebbe tornarmi utile...");
    }

    if(player01->potions >= 1){
        int usePotion = 0;
        printf("Vuoi usare una Pozione Curativa?");
        printf("\n  1. Si\n  2. No\n");
        printf("\nSeleziona opzione [1-2]: ");
        usePotion = InputHandlerInt(buf_size);
        switch(usePotion){
            case 1:
                int throw = DiceThrow();
                player01->potions -= 1;
                if((player01->life + throw) > 20){
                    player01->life = 20;
                    int value = throw - ((player01->life + throw)-20);
                    printf("La salute dell'Eroe e' salita di %d punti Vita!\n", value);
                }
                else{
                    player01->life += throw;
                    printf("La salute dell'Eroe e' salita di %d punti Vita!\n", throw);
                }
                break;
            case 2:
                break;
            default:
                printf("\nScelta non valida!\n");
                break;
        }
    }
    
    if(player01->potions <= 0){
        printf("Press Enter to quit: ");
        int choice = getchar();
    }
    else{
        getchar();
    }
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