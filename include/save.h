//
// Created by 33766 on 18/11/2021.
//

#ifndef MALLOCWORDCLI_SAVE_H
#define MALLOCWORDCLI_SAVE_H

#include "include.h"
#include "pnjService.h"

int saveFile(int *mapSize, int ***map_list, Player *player, PnjLinkedList *stock, bool verifSaveAuto);

char *dateNow();

void initPlayerCharge(int id,Player*,AllItemCraft*,int);
#endif //MALLOCWORDCLI_SAVE_H
