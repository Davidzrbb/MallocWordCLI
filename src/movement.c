//
// Created by lucas on 28/10/2021.
//
#include <pnjService.h>
#include "movement.h"
#include "collecteResource.h"
#include "save.h"


void movement(int ***map_list, int ***map_list_cpy, int ***map_list_respawn, Player *player, PnjLinkedList *stock,
              int *nb_line, int *nb_col, AllMonster *allMonster) {
    int success = 0;
    char direction = NULL;
    int countMov = 0;
    while (success != 2) {
        print2DIntTab(map_list[player->actual_map], nb_line[player->actual_map], nb_col[player->actual_map]);
        printf("tu veux aller ou gros tas? (q,d,z,s)");
        direction = getchar();
        switch (direction) {
            case 'q':
                success = goForward(player, 0, -1, player->actual_map, map_list, map_list_cpy, map_list_respawn, stock,
                                    allMonster, nb_line, nb_col);
                break;
            case 'd':
                success = goForward(player, 0, 1, player->actual_map, map_list, map_list_cpy, map_list_respawn, stock,
                                    allMonster, nb_line, nb_col);
                break;
            case 'z':
                success = goForward(player, -1, 0, player->actual_map, map_list, map_list_cpy, map_list_respawn, stock,
                                    allMonster, nb_line, nb_col);
                break;
            case 's':
                success = goForward(player, 1, 0, player->actual_map, map_list, map_list_cpy, map_list_respawn, stock,
                                    allMonster, nb_line, nb_col);
                break;
            case 't':
                success = saveFile(map_list, player, stock, false, nb_line, nb_col);
                break;
            default :
                printf("???\n");
                break;
        }
        fflush(stdin);
        countMov += 1;
        if (countMov == 10) {
            saveFile(map_list, player, stock, true, nb_line, nb_col);
            countMov = 0;
        }
    }   //tant que player pas mort ou arret de la partie
    freeStock(stock);
    free(player);
    //freeMaps(map_list, map_list_cpy, map_list_respawn, nb_line);
    free(nb_col);
    free(nb_line);
}

void freeMaps(int ***map_list, int ***map_list_cpy, int ***map_list_respawn, int *nb_line) {
    free3Darray(map_list, nb_line);
    free3Darray(map_list_cpy, nb_line);
    free3Darray(map_list_respawn, nb_line);
}

int goForward(Player *player, int add_x, int add_y, int id_map, int ***actual_list_map, int ***actual_map_list_cpy,
              int ***actual_map_list_respawn, PnjLinkedList *stock, AllMonster *allMonster, int *nb_line, int *nb_col) {

    if (player->coord_y + add_y < 0 || player->coord_y + add_y > nb_col[id_map] - 1 ||
        player->coord_x + add_x < 0 || player->coord_x + add_x > nb_line[id_map] - 1) { //verifie bordure map
        printf("pas par la\n ");
        return 0;
    }
    int next_case = actual_list_map[id_map][player->coord_x + add_x][player->coord_y + add_y];
    int success = 0;
    if (next_case >= PLANT1 && next_case <= WOOD3) {
        success = collecteRessources(player, next_case);
        if (success) {
            actual_map_list_respawn[player->actual_map][player->coord_x + add_x][player->coord_y + add_y] = 10;
        }
    } else if (next_case == FREE) {
        success = 1;
    } else if (next_case == NPC) {
        pnjChoice(player, stock);
        return success;
    } else if (next_case >= 12) {
        //    Monster *actual_monster = malloc(sizeof(Monster));
        for (int i = 0; i < 10; i++) {
            if (allMonster->allMonster[i]->id == next_case) {
                success = combat(player, allMonster->allMonster[i]);
                break;
            }
        }
        if (success)actual_map_list_respawn[player->actual_map][player->coord_x + add_x][player->coord_y + add_y] = 15;
    } else if (next_case == PORTAL1_2 || next_case == PORTAL2_3) {
        changeMap(player, next_case, nb_line, nb_col, actual_list_map
        );
        return
                success;
    }
    if (success) {
        actual_list_map[id_map][player->coord_x][player->coord_y] = 0;
        player->coord_x +=
                add_x;
        player->coord_y +=
                add_y;
        actual_list_map[id_map][player->coord_x][player->coord_y] = 1;
        print2DIntTab(actual_list_map[player->actual_map], nb_line[player->actual_map], nb_col[player->actual_map]);
        refresh_map(actual_list_map, actual_map_list_cpy, actual_map_list_respawn, player, nb_line, nb_col
        );
    }
    return
            success;
}

void changeMap(Player *player, int id_portal, int *nb_line, int *nb_col, int ***actual_list_map) {

    if (player->level < 3 && id_portal == PORTAL1_2) {         //verif lvl
        printf("\nreviens au niveau 3 ");
        return;
    } else if (player->level < 7 && id_portal == PORTAL2_3) {
        printf("reviens au niveau 7");
        return;
    }
    actual_list_map[player->actual_map][player->coord_x][player->coord_y] = 0;
    if (id_portal == PORTAL1_2 && player->actual_map == 0) {              //actual map 0 = map1
        player->actual_map = 1;  //map1->map2                             // actual map 1 = map2
    } else if (id_portal == PORTAL1_2 && player->actual_map == 1) {      //actual map 2 = map3
        player->actual_map = 0; // map2->map1
    } else if (id_portal == PORTAL2_3 && player->actual_map == 2) {
        player->actual_map = 1; // map3->map2
    } else {
        player->actual_map = 2; // map2->map3
    }

    for (int x = 0; x < nb_line[player->actual_map]; ++x) {
        for (int y = 0; y < nb_col[player->actual_map]; ++y) {
            if (actual_list_map[player->actual_map][x][y] == id_portal) {
                if (actual_list_map[player->actual_map][x][y - 1] == FREE) {
                    actual_list_map[player->actual_map][x][y - 1] = PLAYER;
                    player->coord_x = x;
                    player->coord_y = y - 1;
                    return;
                } else if (actual_list_map[player->actual_map][x - 1][y] == FREE) {
                    player->coord_x = x - 1;
                    player->coord_y = y;
                    actual_list_map[player->actual_map][x - 1][y] = PLAYER;
                    return;
                } else if (actual_list_map[player->actual_map][x][y + 1] == FREE) {
                    player->coord_x = x;
                    player->coord_y = y + 1;
                    actual_list_map[player->actual_map][x][y + 1] = PLAYER;
                    return;
                } else {
                    actual_list_map[player->actual_map][x + 1][y] = PLAYER;
                    player->coord_x = x + 1;
                    player->coord_y = y;
                    return;
                }
            }
        }
    }
}


void
refresh_map(int ***list_map, int ***list_map_cpy, int ***list_map_respawn, Player *player, int *nb_line, int *nb_col) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < nb_line[i]; ++j) {
            for (int k = 0; k < nb_col[i]; ++k) {
                if (list_map_respawn[i][j][k] >= 1) {
                    list_map_respawn[i][j][k]--;
                    if (list_map_respawn[i][j][k] == 0 && player->coord_x == j && player->coord_y == k) {
                        list_map_respawn[i][j][k] = 1;
                    } else if (list_map_respawn[i][j][k] == 0) {
                        list_map[i][j][k] = list_map_cpy[i][j][k];
                    }
                }
            }
        }
    }
}



































