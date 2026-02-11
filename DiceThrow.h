#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// Questo header contiene metodi di generazione di valori pseudo casuali
// Il seed impiegato e' time(NULL)
// I suoi metodi sono usati da varie funzioni tramite inclusione di questo header sull'header Interfaces.h
// ( dentro la quale ogni funzione del progetto e' invocata )

int CoinThrow(){ // generazione numero intero pseudo casuale tra 0 e 1 ( Impiegato per simulazione lancio moneta per gioco "Testa o Croce" )
    int min = 0;
    int max = 1;
    int coin_throw = ( rand() % ( max - min + 1 ) ) + min;
    return coin_throw;
}

int randNum(){ // generazione numero intero pseudo casuale tra 1 e 500
    int min = 1;
    int max = 500;
    int rand_num = ( rand() % ( max - min + 1 ) ) + min;
    return rand_num;
}

int morra(){ // generazione numero intero pseudo casuale tra 1 e 3
    int min = 1;
    int max = 3;
    int num_morra = ( rand() % ( max - min + 1 ) ) + min;
    return num_morra;
}

int DiceThrow(){ // generazione numero intero pseudo casuale tra 1 e 6
    int min = 1;
    int max = 6;
    int throw = ( rand() % ( max - min + 1 ) ) + min;
    return throw;
}