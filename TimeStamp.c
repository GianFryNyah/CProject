#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*void TimeStamp(){
    time_t rawtime;
    struct tm * timeinfo;
    char formatted_date[50];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(formatted_date, sizeof(formatted_date), "%d-%m-%Y %T\n", timeinfo);// final ' \n ' just for Macs

    printf("%s", formatted_date);
}*/

void TimeStamp(char SaveStats[]){
    time_t rawtime;
    struct tm * timeinfo;
    char formatted_date[50];
    char* test;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(formatted_date, sizeof(formatted_date), "%d-%m-%Y %T", timeinfo);
    test = formatted_date;
    printf("%s\n", test);

    FILE *pFile = fopen("/Users/gianfriddo/Documents/Codes/Cproject/savefile.txt", "a");

    fprintf(pFile, "%s %s", test, SaveStats);
    fclose(pFile);
}