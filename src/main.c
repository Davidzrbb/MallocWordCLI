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

    int **map1 = createTable(8);
    int **map1_cpy = createTable(8);
    int **map1_respawn = createTable(8);
    int **map2 = createTable(10);
    int **map2_cpy = createTable(10);
    int **map2_respawn = createTable(10);
    int **map3  = createTable(12);
    int **map3_cpy = createTable(12);
    int **map3_respawn= createTable(12);

    int *** map_list = malloc(sizeof (map1)+sizeof (map2)+sizeof (map3));
    map_list[0]=map1;
    map_list[1]=map2;
    map_list[3]=map3;

    int *** map_list_cpy = malloc(sizeof (map1_cpy) + sizeof (map2_cpy) + sizeof (map3_cpy));
    map_list_cpy[0]=map1_cpy;
    map_list_cpy[1]=map2_cpy;
    map_list_cpy[3]=map3_cpy;

    int *** map_list_respawn = malloc(sizeof (map1_cpy) + sizeof (map2_cpy) + sizeof (map3_cpy));
    map_list_respawn[0]=map1_respawn;
    map_list_respawn[1]=map2_respawn;
    map_list_respawn[2]=map3_respawn;


    generate_land(map1, 8, 8, 1);  //map1
    generate_land(map2, 10, 10, 2); //map 2
    generate_land(map3, 12, 12, 3); //map 3
    generate_land(map1_cpy, 8, 8, 1);  //map 1 cpy
    generate_land(map2_cpy, 10, 10, 2); //map 2 cpy
    generate_land(map3_cpy, 12, 12, 3); //map 3 cpy
    fill_tab(map1_respawn,8);
    fill_tab(map2_respawn,10);
    fill_tab(map3_respawn,12);


    movement(&PlayerStruct, map_list, map_list_cpy, map_list_respawn);

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

    firstPlayer->actual_map = 1;
}

void printTest(Player PlayerStruct){
    for (int i = 0; i<sizeof(PlayerStruct.inventory[i].type);i++){
            printf("Vos item type %d", PlayerStruct.inventory[i].type);
        }
}

int** createTable(int size){

    int** table = malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++){
        table[i] = malloc(sizeof(int) * size);
    }

    return table;
}

void fill_tab(int ** map,int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            map[i][j]=0;
        }
    }
}