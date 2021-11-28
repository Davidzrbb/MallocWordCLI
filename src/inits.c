//
// Created by lucas on 21/11/2021.


#include "inits.h"


void initStartGame() {

    Player *player = malloc(sizeof(Player));
    PnjLinkedList *stock = malloc(sizeof(PnjLinkedList));

    AllItemCraft *allItemCraft = malloc(sizeof(AllItemCraft));
    initArrayCraftItem(allItemCraft);

    AllMonster allMonster;
    initMonster(&allMonster);

    int ***map_list_respawn = malloc(sizeof(int **) * 3);
    int ***map_list_cpy = malloc(sizeof(int **) * 3);
    int ***map_list = malloc(sizeof(int **) * 3);
    int *nb_line = malloc(sizeof(int) * 3);
    int *nb_col = malloc(sizeof(int) * 3);
    nb_line[0] = 8;
    nb_line[1] = 10;
    nb_line[2] = 12;
    nb_col[0] = 8;
    nb_col[1] = 10;
    nb_col[2] = 12;

    InitPlayer(player);
    initStructStock(stock);
    initMaps(nb_line, nb_col, map_list, map_list_cpy, map_list_respawn);
    generate_land(map_list[0], nb_line[0], nb_col[0], 1, map_list_cpy[0]);  //map1
    generate_land(map_list[1], nb_line[1], nb_col[1], 2, map_list_cpy[1]); //map 2
    generate_land(map_list[2], nb_line[2], nb_col[2], 3, map_list_cpy[2]); //map 3
    //   map_list_cpy[0]=map_list[0];
    // map_list_cpy[1]=map_list[1];
    //map_list_cpy[2]=map_list[2];
//    generate_land(map1_cpy, nb_line[0], nb_col[0], 1);  //map 1 cpy
//    generate_land(map2_cpy, nb_line[1], nb_col[1], 2); //map 2 cpy
//    generate_land(map3_cpy, nb_line[2], nb_col[2], 3); //map 3 cpy

    movement(map_list, map_list_cpy, map_list_respawn, player, stock, nb_line, nb_col, &allMonster);
}

void initMaps(int *nb_line, int *nb_col, int ***map_list, int ***map_list_cpy, int ***map_list_respawn) {

    int **map1 = malloc2Darray(nb_line[0], nb_col[0]);
    int **map1_cpy = malloc2Darray(nb_line[0], nb_col[0]);
    int **map1_respawn = malloc2Darray(nb_line[0], nb_col[0]);
    int **map2 = malloc2Darray(nb_line[1], nb_col[1]);
    int **map2_cpy = malloc2Darray(nb_line[1], nb_col[1]);
    int **map2_respawn = malloc2Darray(nb_line[1], nb_col[1]);
    int **map3 = malloc2Darray(nb_line[2], nb_col[2]);
    int **map3_cpy = malloc2Darray(nb_line[2], nb_col[2]);
    int **map3_respawn = malloc2Darray(nb_line[2], nb_col[2]);


    map_list[0] = map1;
    map_list[1] = map2;
    map_list[2] = map3;
    map_list_cpy[0] = map1_cpy;
    map_list_cpy[1] = map2_cpy;
    map_list_cpy[2] = map3_cpy;
    map_list_respawn[0] = map1_respawn;
    map_list_respawn[1] = map2_respawn;
    map_list_respawn[2] = map3_respawn;

    fill_tab(map1_respawn, nb_line[0], nb_col[0]);
    fill_tab(map2_respawn, nb_line[1], nb_col[1]);
    fill_tab(map3_respawn, nb_line[2], nb_col[2]);

}



