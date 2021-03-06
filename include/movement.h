//
// Created by lucas on 28/10/2021.
//

#ifndef MALLOC_WORLD_MOVEMENT_H
#define MALLOC_WORLD_MOVEMENT_H


#include "include.h"
#include "collecteResource.h"
#include "pnjService.h"
#include "inits.h"

void movement(int ***map_list, int ***map_list_cpy, int ***map_list_respawn, Player *player, PnjLinkedList *stock,
              int *nb_line, int *nb_col,AllMonster * allMonster);
int goForward(Player *player, int add_x, int add_y, int id_map, int ***actual_list_map, int ***actual_map_list_cpy,
              int ***actual_map_list_respawn, PnjLinkedList *stock, AllMonster *allMonster, int *nb_line, int *nb_col);
void changeMap(Player *player, int id_portal, int *nb_line, int *nb_col, int ***actual_list_map);
void
refresh_map(int ***list_map, int ***list_map_cpy, int ***list_map_respawn, Player *player, int *nb_line, int *nb_col);


#endif //MALLOC_WORLD_MOVEMENT_H
