#include "../include/include.h"
#include "../include/pnjService.h"

#include "map.h"
#include "movement.h"
#include "inits.h"


int main(int argc, const char *argv[]) {
    AllMonster allMonster;
    initMonster(&allMonster);
    startChoice();
    return 0;
}



void InitPlayer(Player *firstPlayer) {

    Item *WeaponSword = malloc(sizeof(Item));
    WeaponSword->weapon.name = "epee en bois";
    WeaponSword->weapon.damage = 1;
    WeaponSword->weapon.max_durability = 10;
    WeaponSword->weapon.actual_durabiulity = 10;
    WeaponSword->weapon.id = WOODEN_SWORD;
    WeaponSword->type = WEAPON;

    Item *ToolsPickaxe = malloc(sizeof(Item));
    ToolsPickaxe->tools.name = "pioche en bois";
    ToolsPickaxe->tools.max_durability = 10;
    ToolsPickaxe->tools.actual_durabiulity = 5;
    ToolsPickaxe->tools.id = WOODEN_PICKAXE;
    ToolsPickaxe->type = TOOL;

    Item *ToolsBillhook = malloc(sizeof(Item));
    ToolsBillhook->tools.name = "serpette en bois";
    ToolsBillhook->tools.max_durability = 10;
    ToolsBillhook->tools.actual_durabiulity = 10;
    ToolsBillhook->tools.id = WOODEN_BILLHOOK;
    ToolsBillhook->type = TOOL;


    Item *ToolsAx = malloc(sizeof(Item));
    ToolsAx->tools.name = "hache en bois";
    ToolsAx->tools.max_durability = 10;
    ToolsAx->tools.actual_durabiulity = 10;
    ToolsAx->tools.id = WOODEN_AX;
    ToolsAx->type = TOOL;


    firstPlayer->level = 1;
    firstPlayer->currentHealthPoints = 100;
    firstPlayer->maxHealthpoints = 100;
    firstPlayer->currentExperience = 0;
    firstPlayer->maxExperience = 50;
    firstPlayer->coord_x = 1;
    firstPlayer->coord_y = 0;
    firstPlayer->actual_map = 1;
    firstPlayer->inventory[0] = *WeaponSword;
    firstPlayer->inventory[1] = *ToolsPickaxe;
    firstPlayer->inventory[2] = *ToolsBillhook;
    firstPlayer->inventory[3] = *ToolsAx;
}

int **createTable(int n) {

    int **table = malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        table[i] = malloc(sizeof(int) * n);
    }

    return table;
}


void freeStock(PnjLinkedList *stock) {
    if (stock->next != NULL) {
        freeStock(stock->next);
    }
    stock = malloc(sizeof(PnjLinkedList));
    free(stock);
}




