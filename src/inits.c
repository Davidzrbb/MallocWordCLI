//
// Created by lucas on 21/11/2021.

#include "inits.h"

void initMaps(int ****map_list, int ****map_list_cpy, int ****map_list_respawn){

    int **map1 = malloc2Darray(8);
    int **map1_cpy = malloc2Darray(8);
    int **map1_respawn = malloc2Darray(8);
    int **map2 = malloc2Darray(10);
    int **map2_cpy = malloc2Darray(10);
    int **map2_respawn = malloc2Darray(10);
    int **map3  = malloc2Darray(12);
    int **map3_cpy = malloc2Darray(12);
    int **map3_respawn= malloc2Darray(12);

    map_list[0] = malloc(sizeof (map1)+sizeof (map2)+sizeof (map3));
    map_list[0][0]=map1;
    map_list[0][1]=map2;
    map_list[0][2]=map3;

    map_list_cpy[0] = malloc(sizeof (map1_cpy) + sizeof (map2_cpy) + sizeof (map3_cpy));
    map_list_cpy[0][0]=map1_cpy;
    map_list_cpy[0][1]=map2_cpy;
    map_list_cpy[0][2]=map3_cpy;

    map_list_respawn[0] = malloc(sizeof (map1_cpy) + sizeof (map2_cpy) + sizeof (map3_cpy));
    map_list_respawn[0][0]=map1_respawn;
    map_list_respawn[0][1]=map2_respawn;
    map_list_respawn[0][2]=map3_respawn;

    generate_land(map_list[0][0], 8, 8, 1);  //map1
    generate_land(map_list[0][1], 10, 10, 2); //map 2
    generate_land(map_list[0][2], 12, 12, 3); //map 3
    generate_land(map_list_cpy[0][0], 8, 8, 1);  //map 1 cpy
    generate_land(map_list_cpy[0][1], 10, 10, 2); //map 2 cpy
    generate_land(map_list_cpy[0][2], 12, 12, 3); //map 3 cpy


}
