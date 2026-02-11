#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Interfaces.h"

// e' l'unico file .c del progetto e avvia il programma inizializzando il seed time(NULL) necessario per i metodi descritti su DiceThrow.c
// dopodiche' invoca la funzione menu(int x) passandogli l'intero CheatMode inizializzato ad 1
// menu(int x) e' presente dentro l'header Interfaces.h incluso su questo file
// L'intero passato a menu(int x) serve a stabilire se i cheat sono attivati e, nel caso, per tutta la restante durata del programma i cheat saranno attivi
// e' stato scelto un intero al posto di un bool per usarlo anche come valore da passare ad una funzione che torna determinati prompt testuali da mostrare
// terminata l'esecuzione di menu(int x), termina anche il main() ed il programma infine termina

// LOGICE DI BASE DI ESECUZIONE DEL PROGRAMMA
// main() --> menu(int x) --> game(player y, int x) --> missione(player* x, int* y, int* z) --> game(player y, int x) --> ... --> game(player y, int x) --> menu(int x) --> main() --> return 0;

int main(){
    srand(time(NULL));
    int CheatMode = 1;
    menu(CheatMode);
    return 0;
}