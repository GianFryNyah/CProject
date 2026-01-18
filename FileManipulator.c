#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define BUFF 4096

int count_lines(); //Used by addSave(char* string); It return the number of lines (counting \n) of a text file

void ShowSaves(){
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
    fprintf(pFile, "%d. %s%s", nlines, formatted_date, SaveStats);
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
            if(CIndex <= 9){
                char SIndex[2];
                sprintf(SIndex, "%d", CIndex);
                data[0] = SIndex[0];
                if(Index == 10){
                    int lenght = strlen(data);
                    for (int i = 1; i < lenght; i++){
                        data[i] = data[i+1];
                    }
                }
                fprintf(cpFile, "%s", data);
            }
            else if(CIndex >= 10){
                char SIndex[4];
                sprintf(SIndex, "%d", CIndex);
                for(int i = 0; i < 2; i++){
                    data[i] = SIndex[i];
                }
                fprintf(cpFile, "%s", data);
            }
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

void loadSave(){}

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