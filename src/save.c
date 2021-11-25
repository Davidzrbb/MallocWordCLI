#include "../include/save.h"

char nameFileManuelle[50] = "";
char nameFileAuto[50] = "";


int saveFile(int *mapSize, int ***map_list, Player *player, PnjLinkedList *stock, bool verifSaveAuto) {

    PnjLinkedList *cache = stock;
    char date[100] = "";
    strcpy(date, dateNow());
    char path[100] = "";

    if (verifSaveAuto == true) {
        strcat(path, "saveAuto");
        strcpy(nameFileAuto, date);
    }
    if (verifSaveAuto == false) {
        strcat(path, "saveManuelle");
        strcpy(nameFileManuelle, date);
    }


    strcat(path, ".txt");

    FILE *fichier = NULL;

    fichier = fopen(path, "w+");

    if (fichier != NULL) {
        fprintf(fichier, "===MAP===");

        for (int i = 0; i < 3; ++i) {
            fprintf(fichier, "\n--ZONE%d--", i);
            for (int j = 0; j < mapSize[i]; ++j) {
                fprintf(fichier, "\n");
                for (int k = 0; k < mapSize[i]; ++k) {
                    fprintf(fichier, "%d ", map_list[i][j][k]);
                }
            }
        }
        fprintf(fichier, "\n=== PLAYER ===\n{%d}\n{%f}/{%d}\n{%f}/{%f}\n-- INVENTORY --\n", player->level,player->maxHealthpoints-player->currentExperience,
                player->currentExperience,
                player->currentHealthPoints, player->maxHealthpoints);
        for (int i = 0; i < 10; i++) {
            if (player->inventory[i].type > 0 && player->inventory[i].type < 6) {
                if (player->inventory[i].type == 3 || player->inventory[i].type == 4) {
                    fprintf(fichier, "{%d}@{%d}@{0}\n", player->inventory[i].resource.quantity,
                            player->inventory[i].resource.id);
                }
                if (player->inventory[i].type == 1 || player->inventory[i].type == 2) {
                    fprintf(fichier, "{1}@{%d}@{%.2f}\n", player->inventory[i].resource.id,
                            player->inventory[i].tools.actual_durabiulity);
                }
                if (player->inventory[i].type == 5) {
                    fprintf(fichier, "{1}@{%d}@{0}\n", player->inventory[i].resource.id);
                }
            } else {
                fprintf(fichier, "{0}@{0}@{0}\n");
            }
        }
        fprintf(fichier, "-- STORAGE --\n");
        while (cache->next != NULL) {

            if (cache->data->type == 3 || cache->data->type == 4) {
                fprintf(fichier, "{%d}@{%d}\n", cache->data->resource.quantity, cache->data->resource.id);
            } else {
                fprintf(fichier, "{1}@{%d}\n", cache->data->weapon.id);
            }
            cache = cache->next;
        }
        fclose(fichier);
    }
    return 2;
}

char *dateNow() {
    // Renvoie l'heure actuelle
    char buffer[256];
    time_t timestamp = time(NULL);
    strftime(buffer, sizeof(buffer), "%A %d %B %Y - %Hh%Mm%Ss", localtime(&timestamp));
    return buffer;
}

void charge(bool verifSaveAuto) {

    int ***map_list;
    int ***map_list_cpy;
    int ***map_list_respawn;
    int *nb_line = malloc(sizeof(int) * 3);
    int *nb_col = malloc(sizeof(int) * 3);
    Player *player = malloc(sizeof(Player));
    PnjLinkedList *stock = malloc(sizeof(PnjLinkedList));
    initStructStock(stock);
    AllItemCraft *allItemCraft = malloc(sizeof(AllItemCraft));
    initArrayCraftItem(allItemCraft);

    char path[50] = "";
    if (verifSaveAuto == true) {
        strcat(path, "saveAuto");
        strcat(path, ".txt");
    }
    if (verifSaveAuto == false) {
        strcat(path, "saveManuelle");
        strcat(path, ".txt");
    }
    //LIRE LE NOMBRE DE LIGNE
    FILE *fichier;
    fichier = fopen(path, "r");
    int c;
    int nLignes = 0;
    int stopStock = 0;
    int startInventory = 0;
    while ((c = fgetc(fichier)) != EOF) {
        if (c == '\n') {
            nLignes++;
        }
//        if(c == ){}
        if (stopStock == 0) {
            if (nLignes >= 16) {
                if (c == 61) {
                    stopStock = nLignes;
                }
            }
        }

    }
    fclose(fichier);
    FILE *file;
    int bufferLength = nLignes;
    char buffer[255];
    int i;
    int n;
    int v;
    char str[5];
    int count = 0;

    file = fopen(path, "r");
    while (fgets(buffer, bufferLength, file)) {
        sscanf(buffer, "%c%d%c%c%c%d%c%c%c%d", str, &i, str, str, str, &n, str, str, str, &v);

        if (count == 2) {
            player->currentExperience = i;
        }
        if (count == 3) {
            player->currentHealthPoints = i;
            player->maxHealthpoints = n;
        }
        if (count >= 5 && count < 15) {
            initPlayerCharge(n, player, allItemCraft, count);
        }
        if (count > 15 && count < stopStock) {
            initStockCharge(n, stock, allItemCraft);
        }
        count += 1;
    }
    fclose(file);
    LoadMap(&map_list, &map_list_cpy, &map_list_respawn, path, nb_line, nb_col);
    movement(map_list, map_list_cpy, map_list_respawn, player, stock, nb_line, nb_col);
}

int count_nb_col(char *fileName, int nb_map) {

    FILE *file = fopen(fileName, "a+");//todo recuperer le nom du fichier et pas fichier en dur
    char *line = malloc(sizeof(char) * 255);
    fgets(line, 255, file);
    int count_map = 0;
    int nb_col = 0;
    char car = 0;
    while (count_map < nb_map) {
        fgets(line, 255, file);
        if (line[0] == '-') {
            count_map++;
            fgets(line, 255, file);
        }
    }
    while (car != '\n') {
        car = fgetc(file);
        if (car == ' ' || car == '\n') {
            nb_col++;
        }
    }
    fclose(file);
    return nb_col;
}

int count_nb_line(char *fileName, int nb_map) {

    FILE *file = fopen(fileName, "a+");//todo recuperer le nom du fichier et pas fichier en dur
    char *line = malloc(sizeof(char) * 255);
    fgets(line, 255, file);
    int count_map = 0;
    int nb_line = 0;
    char car = 0;
    while (count_map < nb_map) {
        fgets(line, 255, file);
        if (line[0] == '-') {
            count_map++;
        }
    }
    while (car != '=' && car != '-') {
        car = fgetc(file);
        if (car == '\n') {
            nb_line++;
        }
    }
    fclose(file);
    return nb_line;
}

void LoadMap(int ****map_list, int ****map_list_cpy, int ****map_list_respawn, char *path, int *nb_line, int *nb_col) {
    srand(time(NULL));
    int randMonster;
    FILE *file = fopen(path, "a+");//todo recuperer le nom du fichier et pas fichier en dur
    char *line = malloc(sizeof(char) * 255);
    fgets(line, 255, file); //enleve ==map==
    int gap = 1;
    for (int i = 0; i < 3; ++i) {
        nb_line[i] = count_nb_line(path, i + 1);
        nb_col[i] = count_nb_col(path, i + 1);
    }

    for (int i = 0; i < 3; ++i) {
        fgets(line, 255, file);
        for (int y = 0; y < nb_line[i]; ++y) {
            fgets(line, 255, file);
            char *strToken = strtok(line, " ");
            int x = 0;
            while (strToken != NULL) {
                if (atoi(strToken) > 11 && atoi(strToken) < 99) {
                    randMonster = rand() % 3;
                    if (i == 0) {
                        map_list[0][i][y][x] = randMonster + 90;
                        map_list_cpy[0][i][y][x] = randMonster + 96;
                    } else if (i == 1) {
                        map_list[0][i][y][x] = randMonster + 93;
                        map_list_cpy[0][i][y][x] = randMonster + 96;
                    } else {
                        map_list[0][i][y][x] = randMonster + 96;
                        map_list_cpy[0][i][y][x] = randMonster + 96;
                    }
                } else {
                    map_list[0][i][y][x] = atoi(strToken);
                    map_list_cpy[0][i][y][x] = atoi(strToken);
                }
                strToken = strtok(NULL, " ");
                x++;
            }
            x = 0;
        }
        gap = nb_line[i];
    }
    fclose(file);
}

void initPlayerCharge(int id, Player *playerStruct, AllItemCraft *allItemCraft, int count) {
    count -= 5;
    if (id != 0) {
        for (int i = 0; i < 25; i++) {
            if (allItemCraft->itemCraft[i].idCreation == id) {
                if (allItemCraft->itemCraft[i].type == TOOL) {
                    playerStruct->inventory[count].tools.id = id;
                    playerStruct->inventory[count].tools.name = allItemCraft->itemCraft[i].name;
                    playerStruct->inventory[count].tools.actual_durabiulity = allItemCraft->itemCraft[i].actual_durabiulity;
                    playerStruct->inventory[count].tools.max_durability = allItemCraft->itemCraft[i].max_durability;
                    playerStruct->inventory[count].type = TOOL;
                }
                if (allItemCraft->itemCraft[i].type == WEAPON) {
                    playerStruct->inventory[count].weapon.id = id;
                    playerStruct->inventory[count].weapon.name = allItemCraft->itemCraft[i].name;
                    playerStruct->inventory[count].weapon.actual_durabiulity = allItemCraft->itemCraft[i].actual_durabiulity;
                    playerStruct->inventory[count].weapon.max_durability = allItemCraft->itemCraft[i].max_durability;
                    playerStruct->inventory[count].weapon.damage = allItemCraft->itemCraft[i].damage;
                    playerStruct->inventory[count].type = WEAPON;
                }
                if (allItemCraft->itemCraft[i].type == ARMOR) {
                    playerStruct->inventory[count].armor.id = id;
                    playerStruct->inventory[count].armor.name = allItemCraft->itemCraft[i].name;
                    playerStruct->inventory[count].armor.protection = allItemCraft->itemCraft[i].protection;
                    playerStruct->inventory[count].type = ARMOR;
                }
                if (allItemCraft->itemCraft[i].type == HEAL) {
                    playerStruct->inventory[count].heal.id = id;
                    playerStruct->inventory[count].heal.name = allItemCraft->itemCraft[i].name;
                    playerStruct->inventory[count].heal.quantity = allItemCraft->itemCraft[i].quantity;
                    playerStruct->inventory[count].heal.pvRestore = allItemCraft->itemCraft[i].pvRestore;
                    playerStruct->inventory[count].type = HEAL;
                }
            }
        }
    }
}

void initStockCharge(int id, PnjLinkedList *stock, AllItemCraft *allItemCraft) {
    Item *nvItem = malloc(sizeof(Item));
    for (int i = 0; i < 25; i++) {
        if (allItemCraft->itemCraft[i].idCreation == id) {
            if (allItemCraft->itemCraft[i].type == TOOL) {
                nvItem->tools.id = id;
                nvItem->tools.name = allItemCraft->itemCraft[i].name;
                nvItem->tools.actual_durabiulity = allItemCraft->itemCraft[i].actual_durabiulity;
                nvItem->tools.max_durability = allItemCraft->itemCraft[i].max_durability;
                nvItem->type = TOOL;
            }
            if (allItemCraft->itemCraft[i].type == WEAPON) {
                nvItem->weapon.id = id;
                nvItem->weapon.name = allItemCraft->itemCraft[i].name;
                nvItem->weapon.actual_durabiulity = allItemCraft->itemCraft[i].actual_durabiulity;
                nvItem->weapon.max_durability = allItemCraft->itemCraft[i].max_durability;
                nvItem->weapon.damage = allItemCraft->itemCraft[i].damage;
                nvItem->type = WEAPON;
            }
            if (allItemCraft->itemCraft[i].type == ARMOR) {
                nvItem->armor.id = id;
                nvItem->armor.name = allItemCraft->itemCraft[i].name;
                nvItem->armor.protection = allItemCraft->itemCraft[i].protection;
                nvItem->type = ARMOR;
            }
            if (allItemCraft->itemCraft[i].type == HEAL) {
                nvItem->heal.id = id;
                nvItem->heal.name = allItemCraft->itemCraft[i].name;
                nvItem->heal.quantity = allItemCraft->itemCraft[i].quantity;
                nvItem->heal.pvRestore = allItemCraft->itemCraft[i].pvRestore;
                nvItem->type = HEAL;
            }
        }
    }
    insertionToStock(nvItem, stock);
}