#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int InputHandlerInt(int buf_size){
    char *endptr;
    char buff[buf_size];
    fgets(buff, sizeof(buff), stdin);
    return strtol(buff, &endptr, 10);
}

void Text(int code){
    switch (code){
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
        case 6:
            printf("\nMenu di Selezione Missione:\n");
            printf("\n  1. Palude Putrescente\n  2. Magione Infestata\n  3. Grotta di Cristallo\n");
            break;
        case 7:
            printf("\nStai uscendo dal gioco, ricordati di salvare la partita per non perdere i tuoi progressi. Sei sicuro di voler procedere?\n");
            printf("\n  1. Si\n  2. No\n");
            printf("\nSeleziona opzione [1-2]: ");
            break;
        case 8:
            break;
    }
}