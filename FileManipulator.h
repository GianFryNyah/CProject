#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "struct.h"
#define BUFF 4096
#define BUF 128

int count_lines(); //Used by addSave(char* string); It return the number of lines (counting \n) of a text file

/*void ShowSaves(){ // Obsoleta DA RIMUOVERE ma NON ADESSO
    FILE *pFile = fopen("savefile.txt", "r");
    
    char data[BUFF];
    if(pFile == NULL){
        printf("Error opening file!");
    }

    while(fgets(data, BUFF, pFile) != NULL){
        printf("\t%s", data);
    }
    fclose(pFile);
    printf("\n");
}*/

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

void addSave(char* SaveStats){//It appends a save stat, given a string type with player stats (this function do the indexing job)
    //TIMESTAMP FOR NEW SAVE
    time_t rawtime;
    struct tm * timeinfo;
    char formatted_date[50];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(formatted_date, sizeof(formatted_date), "%d-%m-%Y %T", timeinfo);

    //OPENING TEXT FILE FOR ADDING A SAVE
    FILE *pFile = fopen("savefile.txt", "a");
    if (pFile == NULL){
        perror("Error opening file!");
    }
    int nlines = count_lines();
    fprintf(pFile, "%2d. %s%s", nlines, formatted_date, SaveStats);
    fclose(pFile);
    //printf("%s%sThere's %d saves on the file\n", formatted_date, SaveStats, nlines); //debug
}

void deleteSave(int Num){//Remove a certain save stat given his index, passed as an int type
    //IT DELETS ONE SPECIFIED SAVE BY PASSING IS INDEX NUMBER
    //IT THEN RE-SORT SAVE FILE INDEXING
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
    //Insert here re-indexing
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

player loadSave(int Num){
    // Conad, persone oltre le cose!
    //IT DELETS ONE SPECIFIED SAVE BY PASSING IS INDEX NUMBER
    //IT THEN RE-SORT SAVE FILE INDEXING
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
            // Qua al posto del debug vanno estrapolati i dati che serviranno dopo a inizializzare la struct player
            // verosimilmente rendermo questa funzione di tipo player, ci deve tornare un player settato per come vogliamo\
            // implementeremo una funzione molto simile per la modifiche del salvataggio tramite konami code

            int life; int money; int items; int CompletedMissions; bool palude; bool magione; bool grotta; bool armor; bool sword; bool heroSword; int potions;
            bool CastleKey; int mission_selector; int mission_selector_range = 7;

            // coordinates: 24-25 ; 38-40 ; 51-52 ; 64 ; 86 ; 87 ; 88 ; 90 ; 91 ; 92 ; 94 ; ? 95 ? ( se potions > 9 )
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

            oneDigitsHolder[0] = data[89];
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
    player failed_load = {20, 0, 0, 0, 6, 7, 0, false, false, false, false, false, false, false};
    return failed_load;
    // Estrapolazione delle statistiche
    // DEBUG
    //printf("\n%s\n", *SaveStat);
    // DEBUG
}

void Cheats(int Num, int life, int money){

    //char s_life[3];
    //char s_money[4];

    //sprintf(s_life, "%02d", life);
    //sprintf(s_money, "%03d", money);

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
            //printf("\n%s\n", Time);

            player toModify = loadSave(Num);
            toModify.life = life;
            toModify.money = money;

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
    //DA STUDIARE MEGLIO
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