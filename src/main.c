#include "../include/include.h"
#include "../include/pnjService.h"
#include "../include/collecteResource.h"

#include "map.h"
#include "movement.h"
#include "inits.h"


int main(int argc, const char *argv[]) {
    AllMonster allMonster;
    initMonster(&allMonster);
    startChoice();
    return 0;
}

void initNewMap(Player *player, PnjLinkedList *stock) {
    int **map1 = createTable(8);
    int **map1_cpy = createTable(8);
    int **map1_respawn = createTable(8);
    int **map2 = createTable(10);
    int **map2_cpy = createTable(10);
    int **map2_respawn = createTable(10);
    int **map3 = createTable(12);
    int **map3_cpy = createTable(12);
    int **map3_respawn = createTable(12);

    int ***map_list = malloc(sizeof(map1) + sizeof(map2) + sizeof(map3));
    map_list[0] = map1;
    map_list[1] = map2;
    map_list[2] = map3;

    int ***map_list_cpy = malloc(sizeof(map1_cpy) + sizeof(map2_cpy) + sizeof(map3_cpy));
    map_list_cpy[0] = map1_cpy;
    map_list_cpy[1] = map2_cpy;
    map_list_cpy[2] = map3_cpy;

    int ***map_list_respawn = malloc(sizeof(map1_cpy) + sizeof(map2_cpy) + sizeof(map3_cpy));
    map_list_respawn[0] = map1_respawn;
    map_list_respawn[1] = map2_respawn;
    map_list_respawn[2] = map3_respawn;


    generate_land(map1, 8, 8, 1);  //map1
    generate_land(map2, 10, 10, 2); //map 2
    generate_land(map3, 12, 12, 3); //map 3
    generate_land(map1_cpy, 8, 8, 1);  //map 1 cpy
    generate_land(map2_cpy, 10, 10, 2); //map 2 cpy
    generate_land(map3_cpy, 12, 12, 3); //map 3 cpy
    fill_tab(map1_respawn, 8);
    fill_tab(map2_respawn, 10);
    fill_tab(map3_respawn, 12);


    movement(player, map_list, map_list_cpy, map_list_respawn, stock);
}

void InitPlayer(Player *firstPlayer) {

    Item *WeaponSword = malloc(sizeof(Item));
    WeaponSword->weapon.name ="epee en bois";
    WeaponSword->weapon.damage= 1;
    WeaponSword->weapon.max_durability = 10;
    WeaponSword->weapon.actual_durabiulity  = 10;
    WeaponSword->weapon.id = WOODEN_SWORD;
    WeaponSword->type = WEAPON;

    Item *ToolsPickaxe = malloc(sizeof(Item));
    ToolsPickaxe->tools.name = "pioche en bois";
    ToolsPickaxe->tools.max_durability = 10;
    ToolsPickaxe->tools.actual_durabiulity = 5;
    ToolsPickaxe->tools.id = STONE_PICKAXE;
    ToolsPickaxe->type = TOOL;

    Item  *ToolsBillhook = malloc(sizeof(Item));
    ToolsBillhook->tools.name ="serpette en bois";
    ToolsBillhook->tools.max_durability=10;
    ToolsBillhook->tools.actual_durabiulity=10;
    ToolsBillhook->tools.id= WOODEN_BILLHOOK;
    ToolsBillhook->type= TOOL;


    Item *ToolsAx = malloc(sizeof(Item));
    ToolsAx->tools.name ="hache en bois";
    ToolsAx->tools.max_durability=10;
    ToolsAx->tools.actual_durabiulity=10;
    ToolsAx->tools.id = WOODEN_AX;
    ToolsAx->type= TOOL;


    firstPlayer->level = 1;
    firstPlayer->currentHealthPoints = 100;
    firstPlayer->maxHealthpoints = 100;
    firstPlayer->currentExperience=0;
    firstPlayer->maxExperience = 50;
    firstPlayer->coord_x = 1;
    firstPlayer->coord_y = 0;
    firstPlayer->actual_map = 1;
    firstPlayer->inventory[0] = *WeaponSword ;
    firstPlayer->inventory[1] = *ToolsPickaxe ;
    firstPlayer->inventory[2] = *ToolsBillhook ;
    firstPlayer->inventory[3] = *ToolsAx ;
}

int** createTable(int n){

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




