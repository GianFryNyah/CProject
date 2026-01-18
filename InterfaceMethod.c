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
    }
}