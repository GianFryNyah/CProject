#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "struct.h"
#define BUFF 4096
#define BUF 128
// Questo header contiene meotodi responsabili della manipolazione dei file di testo
// Supporta il salvataggio di tutte le statistiche di una partita, il caricamento di un salvataggio pre esistente,
// la modifica di alcune statistiche di un salvataggio e l'eliminazione di un salvataggio
// Il salvataggio e' una stringa dove le statistiche sono rappresentati da valori estrapolati da una struct player
// La struct player in questione e' descritta presso l'header struct.h
// Il formato della stringa e' " 1. xx-xx-xxxx xx:xx:xx, xx P . VITA , xxx MONETE , xx OGGETTI , x MISSIONI COMPLETATE xxxxxxxxxx"
// La stringa e' appositamente formattata in modo da non variare mai la propria dimensione
// Vita massima possibile con trucchi: 99 - Senza trucchi: 20
// Monete massime possibili: 999
// I salvataggi sono gestiti mediante scrittura su file di testo con estensione .txt

// Questa funzione conta quante linee sono presenti nel file savefile.txt
// Va a contare le occorrenze del carattere \n e ritorna un intero pari al numero di occorrenze
// Questo metodo e' usato solo dai metodi contenuti in questo header come supporto
int count_lines(); //Used by addSave(char* string); It return the number of lines (counting \n) of a text file

// Mostra in output su terminale la lista dei salvataggi con una formattazione che nasconda le statistiche che non devono essere mostrate
void newShowSaves(){
    FILE *cpFile = fopen("savefile_copy.txt", "w");
    if (cpFile == NULL){
        perror("Error opening file!");
    }
    FILE *ppFile = fopen("savefile.txt", "r");
    if (ppFile == NULL){
        perror("Error opening file!");
    }

    char data[BUFF];

    while(fgets(data, BUFF, ppFile) != NULL){
        char temp[87] = "\0";
        for(int i = 0; i < 86; i++){
            temp[i] = data[i];
        }
        temp[86] = '\0';
        fprintf(cpFile, "%s\n", temp);
    }

    fclose(ppFile);
    fclose(cpFile);

    FILE *pFile = fopen("savefile_copy.txt", "r");
    
    if(pFile == NULL){
        printf("Error opening file!");
    }

    while(fgets(data, BUFF, pFile) != NULL){
        printf("\t%s", data);
    }
    fclose(pFile);
    printf("\n");

    remove("savefile_copy.txt");
}

// Aggiunge un salvataggio al file savefile.txt se esiste ALTRIMENTI crea un nuovo file savefile.txt e gli aggiunge il salvataggio
// Il nuovo salvataggio viene sempre agganciato come ultimo salvataggio ( se esistono tre salvataggi, addSave(char* s) lo aggiungera' come quarto salvataggio )
void addSave(char* SaveStats){//It appends a save stat, given a string type with player stats (this function do the indexing job)
    // TIMESTAMP PER NUOVI SALVATAGGI
    time_t rawtime;
    struct tm * timeinfo;
    char formatted_date[50];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(formatted_date, sizeof(formatted_date), "%d-%m-%Y %T", timeinfo);

    // APERTURA FILE DI TESTO PER AGGIUNTA DI UN SALVATAGGIO
    FILE *pFile = fopen("savefile.txt", "a");
    if (pFile == NULL){
        perror("Error opening file!");
    }
    int nlines = count_lines();
    fprintf(pFile, "%2d. %s%s", nlines, formatted_date, SaveStats);
    fclose(pFile);
}

// Questa funzione elimina un salvataggio al file savefile.txt se questo esiste e se il salvataggio viene trovato
void deleteSave(int Num){
    // ELIMINA UNO SPECIFICO SALVATAGGIO PASSANDONE IL SUO INDICE ALLA FUNZIONE
    // ELIMINATO IL SALVATAGGIO CORRISPONDENTE, RIDEFINISCE IL VALORE INDICE PER OGNI SALVATAGGIO
    FILE *cpFile = fopen("savefile_copy.txt", "w");
    if (cpFile == NULL){
        perror("Error opening file!");
    }
    FILE *ppFile = fopen("savefile.txt", "r");
    if (ppFile == NULL){
        perror("Error opening file!");
    }

    char data[BUFF];
    while(fgets(data, BUFF, ppFile) != NULL){
        char *endptr;
        int Index = strtol(data, &endptr, 10);
        if(Index < Num){
            fprintf(cpFile, "%s", data);
        }
        else if(Num == Index){
            continue;
        }
        else if(Index > Num){
            int CIndex = Index;
            CIndex -= 1;

            char SIndex[4];

            if(CIndex < 10){
                sprintf(SIndex, " %d", CIndex); 
            }
            else{
                sprintf(SIndex, "%d", CIndex);
            }

            for(int i = 0; i < 2; i++){
                data[i] = SIndex[i];
            }
            fprintf(cpFile, "%s", data);
        }
    }
    fclose(ppFile);
    fclose(cpFile);
    FILE *_ppFile = fopen("savefile.txt", "w");
    if (_ppFile == NULL){
        perror("Error opening file!");
    }
    FILE *_cpFile = fopen("savefile_copy.txt", "r");
    if (_cpFile == NULL){
        perror("Error opening file!");
    }
    
    while(fgets(data, BUFF, _cpFile) != NULL){
        fprintf(_ppFile, "%s", data);
    }

    fclose(_ppFile);
    fclose(_cpFile);
    remove("savefile_copy.txt");
}

// Questa funzione si occupa del caricamento di un salvataggio mediante passaggio di un int Num che rappresenta l'indice del salvataggio da caricare
// Se il salvataggio si trova, torna un tipo player con i valori di nostro interesse
// Altrimenti gestisce l'errore e fa iniziare una nuova partita
player loadSave(int Num){
    FILE *ppFile = fopen("savefile.txt", "r");
    if (ppFile == NULL){
        perror("Error opening file!");
    }

    char data[BUFF];
    while(fgets(data, BUFF, ppFile) != NULL){
        char *endptr;
        int Index = strtol(data, &endptr, 10);
        if(Index != Num){
            continue;
        }
        else if(Num == Index){
            // Dentro questo if vengono estrapolati i dati che servono ad inizializzare la struct player
            // Tornera' un tipo Player con i valori desiderati

            int life; int money; int items; int CompletedMissions; bool palude; bool magione; bool grotta; bool armor; bool sword; bool heroSword; int potions;
            bool CastleKey; int mission_selector; int mission_selector_range = 7;

            // coordinate vari attributi per gestione salvataggi, in ordine di comparsa nella struct:
            // 25-26 ; 39-41 ; 52-53 ; 65 ; 87 ; 88 ; 89 ; 90 ; 91 ; 92 ; 93 ; 94 ; 95-96 ( se potions > 9 )
            char oneDigitsHolder[2] = "\0"; char twoDigitsHolder[3] = "\0"; char threeDigitsHolder[4] = "\0";

            // LIFE EXTRAPOLATION
            int y = 0;
            for(int i = 25; i <= 26; i++){
                twoDigitsHolder[y] = data[i];
                y++;
            }
            char* endptr;
            life = strtol(twoDigitsHolder, &endptr, 10);

            // MONEY EXTRAPOLATION
            y = 0;
            for(int i = 39; i <= 41; i++){
                threeDigitsHolder[y] = data[i];
                y++;
            }
            money = strtol(threeDigitsHolder, &endptr, 10);

            // ITEMS EXTRAPOLATION
            y = 0;
            for(int i = 52; i <= 53; i++){
                twoDigitsHolder[y] = data[i];
                y++;
            }
            items = strtol(twoDigitsHolder, &endptr, 10);

            // COMPLETEDMISSIONS EXTRAPOLATION
            oneDigitsHolder[0] = data[65];
            CompletedMissions = strtol(oneDigitsHolder, &endptr, 10);

            // BOOLS EXTRAPOLATION
            oneDigitsHolder[0] = data[87];
            int num;
            num = strtol(oneDigitsHolder, &endptr, 10);
            if(num == 1){ palude = true;}
            else{palude = false;}

            oneDigitsHolder[0] = data[88];
            num = strtol(oneDigitsHolder, &endptr, 10);
            if(num == 1){ magione = true;}
            else{magione = false;}

            oneDigitsHolder[0] = data[89];
            num = strtol(oneDigitsHolder, &endptr, 10);
            if(num == 1){ grotta = true;}
            else{grotta = false;}

            oneDigitsHolder[0] = data[90];///
            num = strtol(oneDigitsHolder, &endptr, 10);
            if(num == 1){ CastleKey = true;}
            else{CastleKey = false;}

            oneDigitsHolder[0] = data[91];
            num = strtol(oneDigitsHolder, &endptr, 10);
            if(num == 1){ armor = true;}
            else{armor = false;}

            oneDigitsHolder[0] = data[92];
            num = strtol(oneDigitsHolder, &endptr, 10);
            if(num == 1){ sword = true;}
            else{sword = false;}

            oneDigitsHolder[0] = data[93];
            num = strtol(oneDigitsHolder, &endptr, 10);
            if(num == 1){ heroSword = true;}
            else{heroSword = false;}

            // MISSION_SELECTOR EXTRAPOLATION
            oneDigitsHolder[0] = data[94];
            mission_selector = strtol(oneDigitsHolder, &endptr, 10);

            // POTIONS EXTRAPOLATION
            y = 0;
            for(int i = 95; i <= 96; i++){
                twoDigitsHolder[y] = data[i];
                y++;
            }
            potions = strtol(twoDigitsHolder, &endptr, 10);

            player playerToLoad = {life, money, items, CompletedMissions, mission_selector, mission_selector_range, potions, palude, magione, grotta, armor, sword, heroSword, CastleKey};
            fclose(ppFile);
            return playerToLoad;
        }
    }
    fclose(ppFile);

    // a questo punto del codice, non si e' riusciti a trovare il salvataggio selezionato
    // mostra l'errore al giocatore ed inizializza il tipo player da tornare con valori di default
    printf("\nErrore nel caricamento! Verra' avviata una Nuova Partita\n");
    player failed_load = {20, 0, 0, 0, 6, 7, 0, false, false, false, false, false, false, false};
    return failed_load;
}

// Permette la modifica delle statistiche di un salvataggio individuato tramite indice per mezzo del passaggio di un int Num
// Il bool permette di scegliere se sbloccare o meno la missione contro il Signore Oscuro
// invoca loadSave(int Num) per estrapolare le statistiche del salvataggio da dover modificare
void Cheats(int Num, int life, int money, bool missione_finale){
    char SaveStats[BUF];
    char Time[24];

    FILE *cpFile = fopen("savefile_copy.txt", "w");
    if (cpFile == NULL){
        perror("Error opening file!");
    }

    FILE *ppFile = fopen("savefile.txt", "r");
    if (ppFile == NULL){
        perror("Error opening file!");
    }

    char data[BUFF];
    while(fgets(data, BUFF, ppFile) != NULL){
        char *endptr;
        int Index = strtol(data, &endptr, 10);

        if(Index != Num){
            fprintf(cpFile, "%s", data);
        }
        else if(Num == Index){
            for(int i = 0; i < 23; i++){
                Time[i] = data[i];
            }
            Time[23] = '\0';

            player toModify = loadSave(Num);
            toModify.life = life;
            toModify.money = money;

            if(missione_finale){
                toModify.palude = true;
                toModify.magione = true;
                toModify.grotta = true;
                toModify.CastleKey = true;
                toModify.CompletedMissions = 3;
            }

            snprintf(SaveStats, BUF, ", %02d P . VITA , %03d MONETE , %02d OGGETTI , %01d MISSIONI COMPLETATE %d%d%d%d%d%d%d%d%d \n", toModify.life, toModify.money, toModify.items, toModify.CompletedMissions, toModify.palude, toModify.magione, toModify.grotta, toModify.CastleKey, toModify.armor, toModify.sword, toModify.heroSword, toModify.mission_selector, toModify.potions);
            fprintf(cpFile, "%s%s", Time, SaveStats);
        }
    }

    fclose(ppFile);
    fclose(cpFile);

    FILE *_ppFile = fopen("savefile.txt", "w");
    if (_ppFile == NULL){
        perror("Error opening file!");
    }
    FILE *_cpFile = fopen("savefile_copy.txt", "r");
    if (_cpFile == NULL){
        perror("Error opening file!");
    }
    
    while(fgets(data, BUFF, _cpFile) != NULL){
        fprintf(_ppFile, "%s", data);
    }

    fclose(_ppFile);
    fclose(_cpFile);
    remove("savefile_copy.txt");
}

int count_lines(){
    FILE* pFile;
    pFile = fopen("savefile.txt", "rb");
    if (pFile == NULL){
        perror("Error opening file!");
        return -1;
    }
    char buf[BUFF];
    int count = 0;

    for(;;){
        size_t r = fread(buf, sizeof(char), BUFF, pFile);

        if(ferror(pFile)){
            return -1;
        }

        int i;
        for(i = 0; i < r; i++){
            if(buf[i] == '\n'){
                count++;
            }
        }

        if(feof(pFile)){
            break;
        }
    }
    fclose(pFile);
    count += 1;
    return count;
}