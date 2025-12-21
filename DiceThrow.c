#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int DiceThrow(){
    srand(time(NULL));
    int min = 1;
    int max = 6;
    int throw = ( rand() % ( max - min + 1 ) ) + min;
    return throw;
}