#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BUFF 4096

int count_lines();

void addSave(char* SaveStats){
    //TIMESTAMP FOR NEW SAVE
    time_t rawtime;
    struct tm * timeinfo;
    char formatted_date[50];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(formatted_date, sizeof(formatted_date), "%d-%m-%Y %T", timeinfo);

    //OPENING TEXT FILE FOR ADDING A SAVE
    FILE *pFile = fopen("savefile.txt", "a");
    int nlines = count_lines();
    fprintf(pFile, "%d. %s%s", nlines, formatted_date, SaveStats);
    fclose(pFile);
    printf("%s%sThere's %d saves on the file\n", formatted_date, SaveStats, nlines);
}

void deleteSave(){}

void loadSave(){}

int count_lines(){ //DA STUDIARE MEGLIO
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
    return count;
}