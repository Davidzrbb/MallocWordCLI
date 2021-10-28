//
// Created by lucas on 23/10/2021.
//

#include "map.h"
#include "perlin_gen.h"
#include "usefulFunc.h"

void create_map() {

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

    generate_land(map1, 8, 8, 1);
    generate_land(map2, 10, 10, 2);
    generate_land(map3, 12, 12, 3);

}

int **generate_land(int **map, int x, int y, int map_id) {

    double perlin;

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {

            perlin = perlin2d(i, j, 0.3f, 8);

            if (perlin < 0.1 || perlin > 0.9) {
                map[i][j] = IMPASSABLE;
            } else if (perlin < 0.30) {
                if (map_id == 1) {
                    map[i][j] = WOOD1;
                } else if (map_id == 2) {
                    map[i][j] = WOOD2;
                } else {
                    map[i][j] = WOOD3;
                }
            } else if (perlin > 0.70) {
                if (map_id == 1) {
                    map[i][j] = ROCK1;
                } else if (map_id == 2) {
                    map[i][j] = ROCK2;
                } else {
                    map[i][j] = ROCK3;
                }
            } else if (perlin < 0.40) {
                if (map_id == 1) {
                    map[i][j] = PLANT1;
                } else if (map_id == 2) {
                    map[i][j] = PLANT2;
                } else {
                    map[i][j] = PLANT3;
                }
            } else {
                map[i][j] = FREE;
            }

        }
    }
    map[0][0] = NPC;
    if(map_id == 1){
        map[x - 1][y - 1] = PORTAL1_2;
    } else if(map_id == 2){
        map[0][y-1] = PORTAL1_2;
        map[x - 1][y - 1]= PORTAL2_3;
    } else{
        map[0][y-1] = PORTAL2_3;
    }

    print2DIntTab(map, x, y);
    printf("\n");

    return map;
}


