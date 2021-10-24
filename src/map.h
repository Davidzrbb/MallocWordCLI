//
// Created by lucas on 23/10/2021.
//

#ifndef MALLOC_WORLD_MAP_H
#define MALLOC_WORLD_MAP_H

#include <stdio.h>
#include <stdlib.h>


enum entity {
    PORTAL1_2 = -3,
    PORTAL2_3 = -2,
    IMPASSABLE = -1,
    FREE = 0,
    PLAYER = 1,
    NPC = 2,
    PLANT1 = 3,
    ROCK1= 4,
    WOOD1=5,
    PLANT2=6,
    ROCK2=7,
    WOOD2=8,
    PLANT3=9,
    ROCK3=10,
    WOOD3=11,
    END_BOSS=99,
};

void create_map();
int **generate_land(int **map, int x, int y, int map_id);



#endif //MALLOC_WORLD_MAP_H
