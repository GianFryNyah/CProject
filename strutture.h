#ifndef STRUTTURE_H
#define STRUTTURE_H

#include <stdbool.h>

typedef struct{
    int life;
    int money;
    int items;
    int CompletedMissions;
    int mission_selector;
    int mission_selector_range;
    bool armor;
    bool sword;
}player;

typedef struct{
    char nome_nemico[30];
    int colpo_fatale;
    int danno_nemico;
    int monete_nemico;   
}nemico;

#endif 


