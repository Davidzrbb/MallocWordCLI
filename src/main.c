#include "../include/collectRessource.h";

void StatDepartPlayer(Player *);

int main(int argc, const char *argv[]) {
    Player PlayerStruct;
    //Stat du Player au début de la partie
    InitPlayer(&PlayerStruct);
    //printInventaire
    MovePlayer(PlayerStruct);
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

void MovePlayer(PlayerStruct) {
    int nextBox = 3;
    //CollecteRessources
    CollecteRessources(&PlayerStruct, nextBox);
}


