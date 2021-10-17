#include "../include/collectRessource.h";

void StatDepartPlayer(Player *);

int main(int argc, const char *argv[]) {
    Player PlayerStruct;
    //Stat du Player au début de la partie
    StatDepartPlayer(&PlayerStruct);
    //printInventaire
    MovePlayer(PlayerStruct);
    return 0;
}

void StatDepartPlayer(Player *PlayerDebut) {
    PlayerDebut->level = 1;
    PlayerDebut->currentHealthPoints = 100;
    PlayerDebut->maxHealthpoints = 100;
    PlayerDebut->inventory[0][0] = 1;
    PlayerDebut->inventory[0][1] = 10;
    PlayerDebut->inventory[0][2] = 1;
    PlayerDebut->inventory[1][0] = 2;
    PlayerDebut->inventory[1][1] = 10;
    PlayerDebut->inventory[1][2] = 0;
    PlayerDebut->inventory[2][0] = 3;
    PlayerDebut->inventory[2][1] = 10;
    PlayerDebut->inventory[2][2] = 0;
    PlayerDebut->inventory[3][0] = 4;
    PlayerDebut->inventory[3][1] = 10;
    PlayerDebut->inventory[3][2] = 0;
}

void MovePlayer(PlayerStruct) {
    int nextBox = 3;
    //CollecteRessources
    CollecteRessources(&PlayerStruct, nextBox);
}


