#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Missione speciale, non serve conoscere le statistiche del giocatore e la struct non viene quindi passata
// Tornera' un valore di vero o falso a seconda dell'esito ( giocatore vince, missione_finale() torna true )
// consiste in 5 round di rock-paper-scissors e restituisce un valore di verità in base a vittoria/sconfitta dell'Eroe
bool missione_finale() {
    int num_round = 1; // contatore round per riga stampata di inizio round con stato punteggi
    int punteggio_eroe = 0; // inizializzazione a zero dei punteggi
    int punteggio_signore = 0;
    int buf_size = 6;
    printf("\nBenvenuto nel Castello del Signore Oscuro!\n\n");
    for (int i = 0; i < 5; i++) { // ciclo for per i 5 round di sfida 
        int mossa_eroe;
        printf("\t\t***MISSIONE FINALE***\n");
        printf("Round in corso: %d su 5 | Punteggio attuale: Eroe %d - Signore Oscuro %d\n", num_round, punteggio_eroe, punteggio_signore);

        do { // ciclo do-while in modo che se viene inserito un valore non valido viene richiesto nuovamente di scegliere la mossa
            printf("Mosse Disponibili:\n");
            printf("1. Scudo\n"); // SASSO
            printf("2. Magia\n"); // CARTA
            printf("3. Spada\n"); // FORBICI
            printf("Seleziona una delle opzioni del menu [1-3]: ");
            mossa_eroe = InputHandlerInt(buf_size);
            switch (mossa_eroe) {
                case 1: {
                    printf("\nL'Eroe ha scelto lo Scudo.\n");
                break;
                }
                case 2: {
                    printf("\nL'Eroe ha scelto la Magia.\n");
                break;    
                }
                case 3: {
                    printf("\nL'Eroe ha scelto la Spada.\n");
                break;
                }
                default: {
                    printf("\nScelta non valida!\n\n");
                break;
                }
            }
        } while (mossa_eroe < 1 || mossa_eroe >3); // controlla i valori in input e ripresenta le mosse disponibili se input non valido

        int mossa_signore = morra (); // generazione casuale mossa nemica
        switch (mossa_signore) {
            case 1: {
                printf("Il Signore Oscuro nel frattempo ha scelto lo Scudo.\n");
            break;
            }
            case 2: {
                printf("Il Signore Oscuro nel frattempo ha scelto la Magia.\n");
            break;    
            }
            case 3: {
                printf("Il Signore Oscuro nel frattempo ha scelto la Spada.\n");
            break;
            }
        }
        printf("\n\t***Premi INVIO per continuare***\n"); // pausa prima di vedere esito round
        clear();
        // Corrispondenza mosse: SASSO = (1) SCUDO, CARTA = (2) MAGIA, FORBICI = (3) SPADA
        // Regole:
        // SCUDO BATTE SPADA | (1) SCUDO VINCE CONTRO (3) SPADA E PERDE CONTRO (2) MAGIA
        // SPADA BATTE MAGIA | (3) SPADA VINCE CONTRO (2) MAGIA E PERDE CONTRO (1) SCUDO
        // MAGIA BATTE SCUDO | (2) MAGIA VINCE CONTRO (1) SCUDO E PERDE CONTRO (3) SPADA
        // STESSO OGGETTO PAREGGIO, NESSUN PUNTO ATTRIBUITO, SI DEVE RIPETERE IL ROUND
        if (mossa_eroe == mossa_signore) { // PAREGGIO 
            printf("Pareggio! Nessuno si aggiudica il Round.\n");
            printf("Il Round %d si ripete.\n", num_round);
            i--; // mettendo i-- il ciclo for non procede, il round di pareggio "non conta", si rifà
        } else if (mossa_eroe == 1 && mossa_signore == 2) { // SCUDO PERDE MAGIA
            printf("Lo Scudo dell'Eroe non puo' difenderlo dalla Magia del Signore Oscuro.\n");
            printf("Il Signore Oscuro si aggiudica il Round.\n");
            punteggio_signore++;
            num_round++; 
        } else if (mossa_eroe == 1 && mossa_signore == 3) { // SCUDO VINCE SPADA
            printf("L'Eroe para e si difende dalla Spada del Signore Oscuro.\n");
            printf("L'Eroe si aggiudica il Round.\n");
            punteggio_eroe++;
            num_round++;
        } else if (mossa_eroe == 2 && mossa_signore == 1) { // MAGIA VINCE SCUDO
            printf("Lo Scudo del Signore Oscuro non puo' difenderlo dalla Magia dell'Eroe.\n");
            printf("L'Eroe si aggiudica il Round.\n");
            punteggio_eroe++;
            num_round++;
        } else if (mossa_eroe == 2 && mossa_signore == 3) { // MAGIA PERDE SPADA
            printf("La Spada del Signore Oscuro batte la Magia dell'Eroe.\n");
            printf("Il Signore Oscuro si aggiudica il Round.\n");
            punteggio_signore++;
            num_round++;
        } else if (mossa_eroe == 3 && mossa_signore == 1) { // SPADA PERDE SCUDO
            printf("Il Signore Oscuro para e si difende dalla Spada dell'Eroe.\n");
            printf("Il Signore Oscuro si aggiudica il Round.\n");
            punteggio_signore++;
            num_round++;
        } else if (mossa_eroe == 3 && mossa_signore == 2) { // SPADA VINCE MAGIA
            printf("La Spada dell'Eroe batte la Magia del Signore Oscuro.\n");
            printf("L'Eroe si aggiudica il Round.\n");
            punteggio_eroe++;
            num_round++;
        }
        
        if (num_round <= 5) { // cambio messaggio in base al round corrente
            printf("\n\t***Premi INVIO per passare al prossimo round***\n"); // pausa a termine round
            clear();
        } 
        else {
            printf("\n\t***Premi INVIO per terminare la missione***\n");
            clear();
        }
    }
    if (punteggio_eroe >= 3) { // terminato il ciclo for e quindi i 5 round controllo se l'eroe ha vinto almeno 3 round su 5
        printf("| Punteggio finale: Eroe %d - Signore Oscuro %d |\n", punteggio_eroe, punteggio_signore);
        printf("\n\t***MISSIONE COMPLETATA***\n");
        printf("Congratulazioni hai sconfitto il Signore Oscuro!\n");
        printf("Hai completato la Missione Finale e hai vinto il gioco!\n");
        return true; // la funzione missione_finale restituisce un valore booleano che può essere utile nel resto del programma
    } else {
        printf("| Punteggio finale: Eroe %d - Signore Oscuro %d |\n", punteggio_eroe, punteggio_signore);
        printf("\n\t=== GAME OVER ===\n");
        printf("L'Eroe e' stato sconfitto!\n");
        return false;
    }
}

