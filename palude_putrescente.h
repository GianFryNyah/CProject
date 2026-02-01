#include <stdio.h>
#include <stdbool.h>
#include "strutture.h"
//#include "DiceThrow.h"
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

void combattimento(player *player01, nemico tipo_nemico) {

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

bool in_palude_putrescente = false;

bool palude_putrescente(player player01) {

    printf("\nMenu di missione:\n");
    printf("1. Esplora stanza del Dungeon\n");
    printf("2. Negozio\n");
    printf("3. Inventario\n");
    printf("4. Torna al Villaggio (Paga 50 monete)\n");
    
    in_palude_putrescente = true;
    do{


int choice_palude = 0;
int choice_negozio = 0;
int beneficio_pozione = 0;
int buf_size = 2;

printf("Seleziona una delle opzioni del menu [1-4]: ");
choice_palude = InputHandlerInt(buf_size);

if (choice_palude == 1) {
    int vittorie_generale_orco = 0;
    for (int i = 0; i < 7; i++) { // Questo for non va bene, a stanza finita si deve ripetere il ciclo del menu di missione, invece cosi' mi propone stanze a ripetizione
        if (player01.life <= 0) break; // Non serve, da morto in primo luogo non puoi esplorare stanze del dungeon
                                        // Con playerx.life <= 0 chiamo la funzione menu() direttamente ( sei morto, game over )
        printf("\n\nStanza n. %d:\n", i+1);
        int stanza_palude = DiceThrow();
                if (stanza_palude == 1) { // Prima generiamo le stanze ( funzione RoomGen() tipo ? ), poi con uno switch vediamo quale stanza esplorare
                    nemico cane_selvaggio = {"Cane Selvaggio", 2, 1, 0};
                    combattimento(&player01, cane_selvaggio);
                    if (player01.life <= 0) return false;
                } else if (stanza_palude == 2) {
                    nemico goblin = {"Goblin", 3, 2, 2};
                    combattimento (&player01, goblin);
                    if (player01.life <= 0) return false;
                } else if (stanza_palude == 3) {
                    nemico scheletro = {"Scheletro", 4, 2, 4};
                    combattimento(&player01, scheletro);
                    if (player01.life <= 0) return false;
                } else if (stanza_palude == 4) {
                    nemico orco = {"Orco", 3, 4, 6};
                    combattimento(&player01, orco);
                    if (player01.life <= 0) return false;
                } else if (stanza_palude == 5) {
                    printf("L'eroe e' caduto in acquitrino velenoso!\n\n");
                    printf("Viene lanciato un dado per stabilire il danno subito.");
                    getchar();
                    if (player01.armor == true) {
                    int danno_trappola = DiceThrow() - 1;
                    player01.life -= danno_trappola;
                    printf("L'armatura dell'eroe diminuisce il danno della trappola di un punto!");
                    if (player01.life <= 0) player01.life = 0; // Se la tua vita va sotto zero a me non serve portarla a 0, non esiste un caso nel progetto dove mi serve avere un player con vita inferiore ad 1
                                                               // Ovunque nel codice la vita scenda sotto 1, io chiamo la funzione menu() direttamente ( I salvataggi li fai da vivo non da morto )
                    printf("La trappola infligge %d danni all'eroe! L'eroe rimane con %d punti vita.", danno_trappola, player01.life);
                    getchar();
                    if (player01.life <= 0) {
                        printf("\nL'eroe e' stato sconfitto!\n");
                        getchar();
                        return false;
                        }
                    } else {
                    int danno_trappola = DiceThrow();
                    player01.life -= danno_trappola;
                    if (player01.life <= 0) player01.life = 0;
                    printf("La trappola infligge %d danni all'eroe! L'eroe rimane con %d punti vita.", danno_trappola, player01.life);
                    getchar();
                    if (player01.life <= 0) {
                        printf("\nL'eroe e' stato sconfitto!\n");
                        getchar();
                        return false;
                        }
                    }
                } else if (stanza_palude == 6) {
                        if (player01.sword == true) {
                            nemico generale_orco = {"Generale Orco", 5, 3, 12};
                            combattimento(&player01, generale_orco);
                            if (player01.life > 0) vittorie_generale_orco++; // se arrivo qui sicuro sono vivo se chiamo menu() quando muoio
                        }else{
                            nemico generale_orco = {"Generale Orco", 6, 3, 12};
                            combattimento(&player01, generale_orco);
                            if (player01.life > 0) vittorie_generale_orco++;                           
                            }
                        }   
        }         
        int stanze_finali = 8;
        while (vittorie_generale_orco < 3 && player01.life > 0 && stanze_finali <= 10) {
            printf("\n\nStanza n. %d:\n", stanze_finali);
            if (player01.sword == true) {
                nemico generale_orco = {"Generale Orco", 5, 3, 12};
                combattimento(&player01, generale_orco);
                if (player01.life <= 0) return false;
            }
            else{
                nemico generale_orco = {"Generale Orco", 6, 3, 12};
                combattimento(&player01, generale_orco);
                if (player01.life <= 0) return false;
            }
            if (player01.life > 0) {
                vittorie_generale_orco++;
                stanze_finali++;
            }
            else{return false;}
        }
        if (vittorie_generale_orco >= 3 && player01.life > 0) { // Non posso valutare qui se ho battuto 3 generali
                                                                // Infatti sopra mi becco almeno 6 stanze a causa del for, anche se ne ho gia' sconfitto 3
                                                                // Al terzo generale sconfitto, devo TERMINARE la missione
                                                                // Le missioni:
                                                                //     O si terminano ( vittoria ), o si paga per uscire senza vincere ( 50 monete ), o basta, oppure e' GAME OVER
            printf("\nL'eroe ha completato la missione Palude Putrescente");
            player01.CompletedMissions++;
            PaludePutrescenteIsCompleted = true; // se sotto ho un return, questo booleano e' totalmente inutile
                                                 // i return fanno terminare le funzioni
            getchar();
            return true;
        }
        else{
            return false;
        }       
                
} 
else if (choice_palude == 2) { // logica negozio
            printf("\nAcquista un oggetto:\n");
            printf("1. Pozione: 4 monete\n");
            printf("2. Spada: 5 monete\n");
            printf("3. Armatura: 10 monete\n");
            printf("4. Esci\n");
            choice_negozio = InputHandlerInt(buf_size);
            switch (choice_negozio) {
                    case 1: { 
                        if (player01.money >= 4) {
                        beneficio_pozione = DiceThrow();
                        printf("Hai acquistato una pozione.\n");
                        printf("Viene lanciato un dado per stabilire il beneficio della pozione.\n");
                        printf("Il risultato e': %d, vengono ripristinati %d punti vita.\n", beneficio_pozione, beneficio_pozione);
                        getchar();
                        player01.money -= 4;
                        player01.life += beneficio_pozione;
                        } else {
                            printf("Non hai abbastanza monete per acquistare una pozione!\n");
                            getchar();
                        }
                        break;
                    }
                    case 2: {
                        if (player01.money >= 5 && player01.sword == false) {
                        printf("Hai acquistato la spada.\n");
                        printf("Gli attacchi che infliggerai aumentano di 1 punto!\n");
                        getchar();
                        player01.money -= 5;
                        player01.sword = true;
                        } else if (player01.money < 5) {
                            printf("Non hai abbastanza monete per acquistare la spada!\n");
                            getchar();
                        } else if (player01.sword == true) {
                            printf("L'eroe possiede gia' una spada!\n");
                            getchar();
                        }
                        break;
                    }
                    case 3: {
                        if (player01.money >= 10 && player01.armor == false) {
                            printf("Hai acquistato un'armatura.\n");
                            printf("I danni che subirai diminuiscono di 1 punto!\n");
                            getchar();
                            player01.money -= 10;
                            player01.armor = true;
                        } else if (player01.money < 10) {
                                printf("Non hai abbastanza monete per acquistare l'armatura!\n");
                                getchar();
                        } else if (player01.armor == true) {
                                printf("L'eroe possiede gia' un'armatura!\n");
                                getchar();
                        }
                        break;
                    }
                    case 4: {
                        break;
                    }
                        
                    
                    default: {
                        printf("\nScelta non valida!\n");
                        getchar();
                    break;
                    }
            }
} 
else if (choice_palude == 3) { // logica inventario
            printf("L'eroe possiede %d monete\n", player01.money);
            if (player01.armor == true) {
                printf("L'eroe possiede l'armatura: SI\n");
            } else {
                printf("L'eroe possiede l'armatura: NO\n");
            }
            if (player01.sword == true) {
               printf("L'eroe possiede la spada: SI\n");
            } else {
                printf("L'eroe possiede la spada: NO\n"); 
            }
            getchar();
} 
else if (choice_palude == 4) { // torna al villaggio
            if (player01.money >= 50) {
            in_palude_putrescente = false;
            player01.money -= 50; 
            return false;
            } else {
                printf("Non hai abbastanza monete per tornare al villaggio!\n");
                getchar();
            }
} 
else {
            printf("\nScelta non valida!\n");
            getchar();
        }
    } while(in_palude_putrescente); // while true o while Condizione X di Exit che desideri
                                    // tanto usi le chiamate a funzioni o i return per terminare il ciclo
                                    // noi vogliamo cicli 'infiniti', perche' abbiamo interruzioni ( fgets() )
                                    // ed essendo un gioco, non possiamo sapere quanti cicli dura un dato evento ( potrei inserire input invalidi per vent'anni nella selezione del menu )
                                    // ma quando necessitiamo una certa transizione, usiamo le chiamate a funzione IL RESTO NON CI INTERESSA PIU'
                                    // ( Esempio, muoio, del resto non me ne frega piu' niente, chiamo menu(), si distruggono tutte le variabili: benissimo, tanto siamo morti )
                                    // ( Ho appena appena sconfitto il terzo Generale Orco, benissimo, printf del tipo "Hai completato la missione!" e subito chiamata a game() passandogli l'oggetto player )

    return false;
} 
