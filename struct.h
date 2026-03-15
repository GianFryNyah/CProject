#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>

// Qua dentro sono definiti due tipi, player e foe

// player rappresenta il giocatore, con tutte le sue statistiche, oggetti in possesso ed eventi completati
typedef struct{
    int life;
    int money;
    int items;
    int CompletedMissions;
    int potions;
    bool palude;
    bool magione;
    bool grotta;
    bool armor;
    bool sword;
    bool heroSword;
    bool CastleKey;
}player;

// foe rappresenta l'avversario, col suo nome e le sue statistiche
typedef struct{
    char nome_nemico[30];
    int colpo_fatale;
    int danno_nemico;
    int monete_nemico;   
}foe;

#endif 


