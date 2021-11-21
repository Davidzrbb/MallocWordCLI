#include "../include/include.h"
#include "../include/pnjService.h"
#include "../include/collecteResource.h"
#include "map.h"
#include "movement.h"
#include "inits.h"

int main(int argc, const char *argv[]) {
    Player playerStruct;
    //Stat du joueur au début de la partie
    //initPlayer(&playerStruct);
    Player PlayerStruct;
    Item ItemStruct;
    //PnjLinkedList stock;
    PnjLinkedList *stock = malloc(sizeof(PnjLinkedList));
    initStructStock(stock);
    //Stat du Player au début de la partie
    InitPlayer(&PlayerStruct);
    //Print
    //printTest(PlayerStruct);

    int*** map_list;
    int*** map_list_cpy;
    int*** map_list_respawn;

    initMaps(&map_list,&map_list_cpy,&map_list_respawn);

    movement(&PlayerStruct, map_list, map_list_cpy, map_list_respawn,stock);

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

    firstPlayer->inventory[0] = *WeaponSword;
    firstPlayer->inventory[1] = *ToolsPickaxe;
    firstPlayer->inventory[2] = *ToolsBillhook;
    firstPlayer->inventory[3] = *ToolsAx;

    firstPlayer->coord_x = 1;
    firstPlayer->coord_y = 0;

    firstPlayer->actual_map = 1;
}








