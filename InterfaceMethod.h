#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            printf("\nMenu Principale:\n");
            printf("\n  1. Nuova Partita\n  2. Carica Salvataggio\n");
            break;
        case 2:
            printf("\nMenu Principale:\n");
            printf("\n  1. Nuova Partita\n  2. Carica Salvataggio\n  3. Trucchi\n");
            break;
        case 3:
            printf("Seleziona una delle opzioni del menu [1-2]: ");
            break;
        case 4:
            printf("Seleziona una delle opzioni del menu [1-3]: ");
            break;
        case 5:
            printf("\nMenu del Villaggio:\n");
            printf("\n  1. Intraprendi una missione\n  2. Riposati\n  3. Inventario\n  4. Salva la partita\n  5. Esci\n");
            break;
        //FINE MENU'
        
        //MENU' SCELTA MISSIONE
        case 6: // P M G
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Palude Putrescente\n  2. Magione Infestata\n  3. Grotta di Cristallo\n");
            break;
        case 7: // M G
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Magione Infestata\n  2. Grotta di Cristallo\n");
            break;
        case 8: // G
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Grotta di Cristallo\n");
            break;
        case 9: // P G
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Palude Putrescente\n  2. Grotta di Cristallo\n");
            break;
        case 10: // P
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Palude Putrescente\n");
            break;
        case 11: // P M
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Palude Putrescente\n  2. Magione Infestata\n");
            break;
        case 12: // M
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Magione Infestata\n");
            break;
        //FINE MENU' SCELTA MISSIONE

        //OPZIONE MENU SCELTA MISSIONE
        case 13:
            printf("Seleziona una delle opzioni del menu [1-3]: ");
            break;
        case 14:
            printf("Seleziona una delle opzioni del menu [1-2]: ");
            break;
        case 15:
            printf("Seleziona una delle opzioni del menu [1]: ");
            break;
        case 16:
            printf("Seleziona una delle opzioni del menu [1-2]: ");
            break;
        case 17:
            printf("Seleziona una delle opzioni del menu [1]: ");
            break;
        case 18:
            printf("Seleziona una delle opzioni del menu [1-2]: ");
            break;
        case 19:
            printf("Seleziona una delle opzioni del menu [1]: ");
            break;
        //FINE MENU' SCELTA MISSIONE

        //EXIT
        case 30:
            printf("\nStai uscendo dal gioco, ricordati di salvare la partita per non perdere i tuoi progressi. Sei sicuro di voler procedere?\n");
            printf("\n  1. Si\n  2. No\n");
            printf("\nSeleziona opzione [1-2]: ");
            break;
        
    }
}