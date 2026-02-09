#ifndef STRUCT_H
#define STRUCT_H

#include <stdbool.h>

typedef struct{
    int life;
    int money;
    int items;
    int CompletedMissions;
    int mission_selector;
    int mission_selector_range;
    int potions;
    bool palude;
    bool magione;
    bool grotta;
    bool armor;
    bool sword;
    bool heroSword;
    bool CastleKey;
}player;

typedef struct{
    char nome_nemico[30];
    int colpo_fatale;
    int danno_nemico;
    int monete_nemico;   
}foe;

#endif 


