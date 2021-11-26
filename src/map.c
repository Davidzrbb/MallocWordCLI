//
// Created by lucas on 23/10/2021.
//

#include "map.h"
#include "perlin_gen.h"
#include "usefulFunc.h"
#include "include.h"

void generate_land(int **map_list, int x, int y, int map_id) {

    double perlin;
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {

                perlin = perlin2d(i, j, 0.3f, 8, 0);

                if (perlin < 0.1 || perlin > 0.9) {
                    map_list[i][j] = IMPASSABLE;

                } else if (perlin < 0.30) {
                    if (map_id == 1) {
                        map_list[i][j] = WOOD1;
                    } else if (map_id == 2) {
                        map_list[i][j] = WOOD2;
                    } else {
                        map_list[i][j] = WOOD3;
                    }
                } else if (perlin > 0.70) {
                    if (map_id == 1) {
                        map_list[i][j] = ROCK1;
                    } else if (map_id == 2) {
                        map_list[i][j] = ROCK2;
                    } else {
                        map_list[i][j] = ROCK3;
                    }
                } else if (perlin < 0.40) {
                    if (map_id == 1) {
                        map_list[i][j] = PLANT1;
                    } else if (map_id == 2) {
                        map_list[i][j] = PLANT2;
                    } else {
                        map_list[i][j] = PLANT3;
                    }
                } else {
                    map_list[i][j] = FREE;
                }

            }
        }
    map_list[0][0] = NPC;
    if(map_id == 1){
        map_list[x - 1][y - 1] = PORTAL1_2;
    } else if(map_id == 2){
        map_list[0][y - 1] = PORTAL1_2;
        map_list[x - 1][y - 1]= PORTAL2_3;
    } else{
        map_list[0][y - 1] = PORTAL2_3;
    }
    if(map_id==1)map_list[1][0]=1;

    print2DIntTab(map_list, x, y);
    printf("\n");

}


