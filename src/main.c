#include <stdio.h>
#include <stdlib.h>
#include "map.h"


struct Player
{
    int experience;
    int level;
    int currentHealthPoints;
    int maxHealthpoints;
    int inventory[10][3];
};
typedef struct Player Player;

void initPlayer(Player*);



int main(int argc, const char *argv[]) {
    Player playerStruct;

    create_map();
    //Stat du joueur au début de la partie
    //initPlayer(&playerStruct);
    
    return 0;
}
void InitPlayer(Player* firstPlayer) {
    firstPlayer->level = 1;
    firstPlayer->currentHealthPoints = 100;
    firstPlayer->maxHealthpoints = 100;
    firstPlayer->inventory[0][0] =  1;
    firstPlayer->inventory[0][1] =  10;
    firstPlayer->inventory[0][2] =  1;

    firstPlayer->inventory[1][0] =  2;
    firstPlayer->inventory[1][1] =  10;
    firstPlayer->inventory[1][2] =  0;

    firstPlayer->inventory[2][0] =  3;
    firstPlayer->inventory[2][1] =  10;
    firstPlayer->inventory[2][2] =  0;

    firstPlayer->inventory[3][0] =  4;
    firstPlayer->inventory[3][1] =  10;
    firstPlayer->inventory[3][2] =  0;
}






