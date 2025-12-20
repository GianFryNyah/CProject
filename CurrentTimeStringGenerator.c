#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t rawtime;
    struct tm * timeinfo;
    char formatted_date[50];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(formatted_date, sizeof(formatted_date), "%d-%m-%Y %T", timeinfo);

    printf("%s", formatted_date);
    return 0;
}