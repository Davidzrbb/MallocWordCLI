//
// Created by 33766 on 18/11/2021.
//

#ifndef MALLOCWORDCLI_SAVE_H
#define MALLOCWORDCLI_SAVE_H


#include <time.h>
#include "include.h"
#include "pnjService.h"
#include "map.h"
#include "movement.h"

int saveFile(int *mapSize, int ***map_list, Player *player, PnjLinkedList *stock, bool verifSaveAuto);
void LoadMap(int ****map_list, int ****map_list_cpy, int ****map_list_respawn, char *path, int *nb_line, int *nb_col);
char *dateNow();

void initPlayerCharge(int id,Player*,AllItemCraft*,int);


#endif //MALLOCWORDCLI_SAVE_H
