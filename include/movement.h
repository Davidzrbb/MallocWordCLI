//
// Created by lucas on 28/10/2021.
//

#ifndef MALLOC_WORLD_MOVEMENT_H
#define MALLOC_WORLD_MOVEMENT_H


#include "include.h"

void movement(Player *player, int ***map_list, int ***map_list_cpy, int ***map_list_respawn);
int goForward(Player *player, int add_x, int add_y, int id_map, int ***actual_map, int ***actual_map_cpy,
              int ***actual_map_respawn);
void changeMap(Player *player, int id_portal);
void refresh_map(int ***list_map, int ***list_map_cpy, int ***list_map_respawn, Player *player);


#endif //MALLOC_WORLD_MOVEMENT_H
