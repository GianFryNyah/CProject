#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int CoinThrow(){ // genera un numero intero casuale tra 0 e 1 che assocerò a testa/croce
    int min = 0;
    int max = 1;
    int coin_throw = ( rand() % ( max - min + 1 ) ) + min;
    return coin_throw;
}

int randNum(){ // genera un numero intero casuale tra 1 e 500
    int min = 1;
    int max = 500;
    int rand_num = ( rand() % ( max - min + 1 ) ) + min;
    return rand_num;
}

int morra(){ // generazione numero casuale tra 1 , 2 , 3
    int min = 1;
    int max = 3;
    int num_morra = ( rand() % ( max - min + 1 ) ) + min;
    return num_morra;
}

int DiceThrow(){
    int min = 1;
    int max = 6;
    int throw = ( rand() % ( max - min + 1 ) ) + min;
    return throw;
}