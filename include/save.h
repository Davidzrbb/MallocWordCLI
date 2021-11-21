//
// Created by 33766 on 18/11/2021.
//

#ifndef MALLOCWORDCLI_SAVE_H
#define MALLOCWORDCLI_SAVE_H

#include "include.h"
#include "pnjService.h"

void startChoice(Player *player, PnjLinkedList *stock);

int saveFile(int *mapSize, int ***map_list, Player *player, PnjLinkedList *stock, bool verifSaveAuto);

char *dateNow();

#endif //MALLOCWORDCLI_SAVE_H
