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


#include "../include/include.h"
#include "../include/pnjService.h"
#include "../include/collecteResource.h"

int main(int argc, const char *argv[]) {
    Player playerStruct;

    create_map();
    //Stat du joueur au début de la partie
    //initPlayer(&playerStruct);
    
    Player PlayerStruct;
    Item ItemStruct;
    //PnjLinkedList stock;
    PnjLinkedList *stock = malloc(sizeof(PnjLinkedList));
    initStructStock(stock);
    //Stat du Player au début de la partie
    InitPlayer(&PlayerStruct);
    //PnjFix
    //pnjChoice(&PlayerStruct, stock);
    return 0;
}

void InitPlayer(Player *firstPlayer) {
    Item *WeaponSword = malloc(sizeof(Item));
    WeaponSword->weapon.damage = 1;
    WeaponSword->weapon.name = "epee en bois";
    WeaponSword->weapon.max_durability = 10;
    WeaponSword->weapon.actual_durabiulity = 10;
    WeaponSword->weapon.id = WOODEN_SWORD;
    WeaponSword->type = WEAPON;

    Item *ToolsPickaxe = malloc(sizeof(Item));
    ToolsPickaxe->tools.name = "pioche en bois";
    ToolsPickaxe->tools.max_durability = 10;
    ToolsPickaxe->tools.actual_durabiulity = 5;
    ToolsPickaxe->tools.id = STONE_PICKAXE;
    ToolsPickaxe->type = TOOL;


    Item *ToolsBillhook = malloc(sizeof(Item));
    ToolsBillhook->tools.name = "serpette en bois";
    ToolsBillhook->tools.max_durability = 10;
    ToolsBillhook->tools.actual_durabiulity = 10;
    ToolsBillhook->tools.id = WOODEN_BILLHOOK;
    ToolsBillhook->type = TOOL;

    Item *ToolsAx = malloc(sizeof(Item));
    ToolsAx->tools.name = malloc(sizeof(char *));
    ToolsAx->tools.name = "hache en bois";
    ToolsAx->tools.max_durability = 10;
    ToolsAx->tools.actual_durabiulity = 10;
    ToolsAx->tools.id = WOODEN_AX;
    ToolsAx->type = TOOL;

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






