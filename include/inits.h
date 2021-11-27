//
// Created by lucas on 21/11/2021.
//

#ifndef MALLOC_WORLD_INITS_H
#define MALLOC_WORLD_INITS_H

#include "include.h"
#include "usefulFunc.h"
#include "map.h"
#include "pnjService.h"
#include "movement.h"

void initMaps(int * nb_line, int * nb_col, int ***map_list, int ***map_list_cpy, int ***map_list_respawn);
void freeMaps(int ***map_list, int ***map_list_cpy, int ***map_list_respawn);
void initStartGame();

#endif //MALLOC_WORLD_INITS_H
