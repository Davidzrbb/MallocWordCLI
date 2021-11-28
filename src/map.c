//
// Created by lucas on 23/10/2021.
//

#include "map.h"
#include "perlin_gen.h"
#include "usefulFunc.h"
#include "include.h"

void generate_land(int **map_list, int x, int y, int map_id, int **map_cpy) {
    srand(time(NULL));
    double perlin;
    int randMonster;
    int randSeed = rand() % 100;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {

            perlin = perlin2d(i, j, 0.2f, 15, randSeed);

            if (perlin < 0.40) {
                if (map_id == 1) {
                    map_list[i][j] = WOOD1;
                    map_cpy[i][j] = WOOD1;
                } else if (map_id == 2) {
                    map_list[i][j] = WOOD2;
                    map_cpy[i][j] = WOOD2;
                } else {
                    map_list[i][j] = WOOD3;
                    map_cpy[i][j] = WOOD3;
                }
            } else if (perlin < 0.48) {
                if (map_id == 1) {
                    map_list[i][j] = PLANT1;
                    map_cpy[i][j] = PLANT1;
                } else if (map_id == 2) {
                    map_list[i][j] = PLANT2;
                    map_cpy[i][j] = PLANT2;
                } else {
                    map_list[i][j] = PLANT3;
                    map_cpy[i][j] = PLANT3;
                }
            } else if (perlin < 0.66) {
                map_list[i][j] = FREE;
                map_cpy[i][j] = FREE;
            } else if (perlin < 0.85) {
                if (map_id == 1) {
                    map_list[i][j] = ROCK1;
                    map_cpy[i][j] = ROCK1;
                } else if (map_id == 2) {
                    map_list[i][j] = ROCK2;
                    map_cpy[i][j] = ROCK2;
                } else {
                    map_list[i][j] = ROCK3;
                    map_cpy[i][j] = ROCK3;
                }
            } else if (perlin < 0.9) {
                randMonster = rand() % 3;
                if (i == 0) {
                    map_list[i][j] = randMonster + 90;
                    map_cpy[i][j] = randMonster + 90;
                } else if (i == 1) {
                    map_list[i][j] = randMonster + 93;
                    map_cpy[i][j] = randMonster + 93;
                } else {
                    map_list[i][j] = randMonster + 96;
                    map_cpy[i][j] = randMonster + 96;
                }
            } else {
                map_list[i][j] = IMPASSABLE;
                map_cpy[i][j] = IMPASSABLE;
            }
        }
    }

    map_list[0][0] = NPC;
    map_cpy[0][0] = NPC;
    if (map_id == 1) {
        map_list[x - 2][y - 2] = PORTAL1_2;
        map_cpy[x - 2][y - 2] = PORTAL1_2;
    } else if (map_id == 2) {
        map_list[1][y - 2] = PORTAL1_2;
        map_list[x - 2][y - 2] = PORTAL2_3;
        map_cpy[1][y - 2] = PORTAL1_2;
        map_cpy[x - 2][y - 2] = PORTAL2_3;
    } else {
        map_list[1][y - 2] = PORTAL2_3;
        map_list[x - 2][1] = END_BOSS;
        map_cpy[1][y - 2] = PORTAL2_3;
        map_cpy[x - 2][1] = END_BOSS;
    }
    if (map_id == 1) {
        map_list[1][0] = 1;
        map_cpy[1][0] = 1;
    }

}


