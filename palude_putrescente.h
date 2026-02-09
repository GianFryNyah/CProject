#include <stdio.h>
#include <stdbool.h>
#include "struct.h"
//#include "InterfaceMethod.h"


//Da aggiungere:
//nella struct del player:
//bool sword;
//bool armor;
//mettere questi due valori a false nella creazione del New Player

/* Secondo me ci conviene chiamare la funzione game usando il puntatore, così: 
void game(int CheatMode, player *player01); e poi nel menu la lanciamo con game(CheatMode, &NewPlayer);
In questo modo tutte le modifiche che facciamo (vita, soldi, ecc.) finiscono direttamente 
nella 'player giusto' e non in una copia.

IMPORTANTE: ho visto che in alcuni case richiami menu() o game() per tornare indietro?
Il problema è che così il computer non torna davvero indietro, ma apre un nuovo menu dentro quello vecchio
Secondo me basta lasciare i break alla fine di ogni case, mi raccomando se non lo mettiamo il programma
passa al case successivo in automatico. In teoria i cicli che hai già scritto e i break ci riportano su 
in automatico senza aprire funzioni nelle funzioni. 
return: esci dalla funzione in cui sei
break: esci dallo switch e resti nel do-while, il break va messo sempre
occhio al do while true, forse metterei una condizione per veitare il loop infinito? .

IMPORTANTE i file .h devono contenere solo dichiarazioni, la logica va nei file .c
ho diviso tutti i file perchè non ruscivo a compilare

INFINE, Penso ci sia un bug in mission selector perchè quando l'eroe viene sconfitto in palude putrescente 
mi riporta al menu di selezione missione ma non si vede nessuna possibilità di scelta:

Esempio:
Scheletro infligge 2 danni all'eroe! L'eroe rimane con 0 punti vita.
L'eroe e' stato sconfitto!

Seleziona una delle opzioni del menu [1-3]: 

Seleziona una delle opzioni del menu [1-3]: -. si ripete in loop */




bool PaludePutrescenteIsCompleted = false;

void combattimento(player *player01, foe tipo_nemico) {

    printf("L'eroe incontra %s e inizia il combattimento.\n", tipo_nemico.nome_nemico);
    getchar();
                                             
    int risultato_dado = DiceThrow();
    int attacco_eroe = 0;
                        
    if (player01->sword == true && player01->armor == true){
        attacco_eroe = risultato_dado + 1; // spada
        tipo_nemico.danno_nemico--; // armatura
        while (attacco_eroe < tipo_nemico.colpo_fatale) {
            printf("Viene lanciato un dado per stabilire l'attacco dell'eroe.\n");
            printf("Il risultato e': %d\n", risultato_dado);
            printf("L'attacco dell'eroe aumenta di un punto grazie alla spada!");

            getchar();
            
            printf("Attacco non sufficiente per sconfiggere %s (%d < Colpo fatale = %d)\n", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale);
            player01->life -= tipo_nemico.danno_nemico;
            printf("Il danno inflitto dal nemico cala di un punto grazie all'armatura!\n");
            printf("%s infligge %d danni all'eroe! L'eroe rimane con %d punti vita.", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico, player01->life);
                            
            getchar();
                        
            if (player01->life <= 0) {
                printf("L'eroe e' stato sconfitto!\n");
                
                getchar();

                return;
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

            getchar();
                            
            printf("Attacco non sufficiente per sconfiggere %s (%d < Colpo fatale = %d)\n", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale);
            player01->life -= tipo_nemico.danno_nemico;
            if (player01->life <= 0) player01->life = 0;
            printf("%s infligge %d danni all'eroe! L'eroe rimane con %d punti vita.", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico, player01->life);

            getchar();
                        
            if (player01->life <= 0) {
                printf("L'eroe e' stato sconfitto!\n");
                getchar();
                return;
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
                            
            getchar();
                            
            printf("Attacco non sufficiente per sconfiggere %s (%d < Colpo fatale = %d)\n", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale);
            player01->life -= tipo_nemico.danno_nemico;
            printf("Il danno inflitto dal nemico cala di un punto grazie all'armatura!\n");

            //if (player01->life <= 0) player01->life = 0;

            printf("%s infligge %d danni all'eroe! ", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico);
            printf("L'eroe rimane con %d punti vita.", (player01->life <= 0) ? 0 : player01->life);
            //printf("%s infligge %d danni all'eroe! L'eroe rimane con %d punti vita.", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico, player01->life);

            getchar();
                        
            if (player01->life <= 0) {
                printf("L'eroe e' stato sconfitto!\n");

                getchar();

                return;
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

            getchar();
            
            printf("Attacco non sufficiente per sconfiggere %s (%d < Colpo fatale = %d)\n", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale);
            player01->life -= tipo_nemico.danno_nemico;

            if (player01->life <= 0) player01->life = 0;

            printf("%s infligge %d danni all'eroe! L'eroe rimane con %d punti vita.", tipo_nemico.nome_nemico, tipo_nemico.danno_nemico, player01->life);
            getchar();
                        
            if (player01->life <= 0) {
                printf("L'eroe e' stato sconfitto!\n");
                                
                getchar();
                
                return;
            }
            risultato_dado = DiceThrow();
            attacco_eroe = risultato_dado;
        }
    }
    
    printf("Viene lanciato un dado per stabilire l'attacco dell'eroe.\n");
    printf("Il risultato e': %d", risultato_dado);
    getchar();
    printf("%s viene sconfitto (%d >= Colpo fatale = %d)\n", tipo_nemico.nome_nemico, attacco_eroe, tipo_nemico.colpo_fatale);
    player01->money += tipo_nemico.monete_nemico;
    if (player01->life <= 0) player01->life = 0; // Da rimuovere e rivedere
    printf("L'eroe rimane con %d punti vita e riceve %d monete.\n", player01->life, tipo_nemico.monete_nemico);
    getchar();    
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

bool in_palude_putrescente = false;

void palude_putrescente(player player01, int CheatMode) {

    // dati da avere al livello scope palude_putrescente()
    int* dungeon_rooms = malloc(10);

    // template Menu' di Missione
    printf("\nMenu di missione:\n");
    printf("1. Esplora stanza del Dungeon\n");
    printf("2. Negozio\n");
    printf("3. Inventario\n");
    printf("4. Torna al Villaggio (Paga 50 monete)\n");
    
    in_palude_putrescente = true;
    
    // do-while nel quale si svolgera' la missione, uscire solo quando la missione deve finire
    do{
        // scope interno DO-WHILE

        // variabili di supporto per funzionalita' MENU'
        int choice_palude = 0;
        int choice_negozio = 0;
        int beneficio_pozione = 0;
        int buf_size = 2;

        // prompt scelta da selezionare, da ripetersi fino ad input valido
        printf("Seleziona una delle opzioni del menu [1-4]: ");
        choice_palude = InputHandlerInt(buf_size);

        switch(choice_palude){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                if(player01.money >= 50){
                    player01.money -= 50;
                    game(player01, CheatMode);
                }
            default:
                break;
        }
    
    } while(in_palude_putrescente);

    // scope palude_putrescente(), si esegue il codice seguente solo a fine missione
    printf("!!!!!!!!!!!!!!!");

    // deallocazione memoria
    free(dungeon_rooms);
    dungeon_rooms = NULL;

    return;
}