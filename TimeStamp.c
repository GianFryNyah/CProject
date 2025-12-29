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

char* TimeStamp(){
    time_t rawtime;
    struct tm * timeinfo;
    char formatted_date[50];
    char* format;

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(formatted_date, sizeof(formatted_date), "%d-%m-%Y %T", timeinfo);
    format = formatted_date;

    return format;
}