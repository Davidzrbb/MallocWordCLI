#include "map.h"
#include "../include/include.h"
#include "movement.h"

int main(int argc, const char *argv[]) {
    Player PlayerStruct;
    //Item ItemStruct;
    //Stat du Player au début de la partie
    InitPlayer(&PlayerStruct);
//Print
    //printTest(PlayerStruct);

    int **map1;
    map1 = malloc(sizeof(int *) * 8);
    for (int i = 0; i < 8; ++i) {
        map1[i] = malloc(sizeof(int) * 8);
    }
    int **map2;
    map2 = malloc(sizeof(int *) * 10);
    for (int i = 0; i < 10; ++i) {
        map2[i] = malloc(sizeof(int) * 10);
    }
    int **map3;
    map3 = malloc(sizeof(int *) * 12);
    for (int i = 0; i < 12; ++i) {
        map3[i] = malloc(sizeof(int) * 12);
    }

    int *** map_list = malloc(sizeof (map1)+sizeof (map2)+sizeof (map3));
    map_list[0]=map1;
    map_list[1]=map2;
    map_list[2]=map3;

    generate_land(map_list[0], 8, 8, 1);
    generate_land(map_list[1], 10, 10, 2);
    generate_land(map_list[2], 12, 12, 3);

    movement(&PlayerStruct, map_list);
    return 0;
}

void InitPlayer(Player* firstPlayer) {
    Item *WeaponSword = malloc(sizeof(Item));
    WeaponSword->weapon.name ="sword";
    WeaponSword->weapon.damage= 1;
    WeaponSword->weapon.max_durability = 10;
    WeaponSword->weapon.actual_durabiulity  = 10;
    WeaponSword->weapon.id = WOODEN_SWORD;
    WeaponSword->type = WEAPON;

    Item *ToolsPickaxe = malloc(sizeof(Item));
    ToolsPickaxe->tools.name ="pickaxe";
    ToolsPickaxe->tools.max_durability=10;
    ToolsPickaxe->tools.actual_durabiulity=10;
    ToolsPickaxe->tools.id= WOODEN_PICKAXE;
    ToolsPickaxe->type= TOOL;

    Item  *ToolsBillhook = malloc(sizeof(Item));
    ToolsBillhook->tools.name ="billhook";
    ToolsBillhook->tools.max_durability=10;
    ToolsBillhook->tools.actual_durabiulity=10;
    ToolsBillhook->tools.id= WOODEN_BILLHOOK;
    ToolsBillhook->type= TOOL;


    Item *ToolsAx = malloc(sizeof(Item));
    ToolsAx->tools.name ="ax";
    ToolsAx->tools.max_durability=10;
    ToolsAx->tools.actual_durabiulity=10;
    ToolsAx->tools.id = WOODEN_AX;
    ToolsAx->type= TOOL;


    firstPlayer->level = 1;
    firstPlayer->currentHealthPoints = 100;
    firstPlayer->maxHealthpoints = 100;
    firstPlayer->inventory[0] = *WeaponSword ;
    firstPlayer->inventory[1] = *ToolsPickaxe ;
    firstPlayer->inventory[2] = *ToolsBillhook ;
    firstPlayer->inventory[3] = *ToolsAx ;

    firstPlayer->coord_x = 1;
    firstPlayer->coord_y = 0;

    firstPlayer->actual_map = 0;
}

void printTest(Player PlayerStruct){
    for (int i = 0; i<sizeof(PlayerStruct.inventory[i].type);i++){
            printf("Vos item type %d", PlayerStruct.inventory[i].type);
        }
}