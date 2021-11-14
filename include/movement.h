//
// Created by lucas on 28/10/2021.
//

#ifndef MALLOC_WORLD_MOVEMENT_H
#define MALLOC_WORLD_MOVEMENT_H


#include "include.h"

void movement(Player *player, int ***actual_map);
int goForward(Player *player, int add_x, int add_y, int **actual_map, int id_map);
void changeMap(Player *player, int id_portal);



#endif //MALLOC_WORLD_MOVEMENT_H
