#include "../include/include.h"
#include "../include/pnjService.h"
#include "../include/save.h"
#include "../include/map.h"

char nameFileManuelle[50] = "";
char nameFileAuto[50] = "";



int saveFile(int *mapSize, int ***map_list, Player *player, PnjLinkedList *stock, bool verifSaveAuto) {

    PnjLinkedList *cache = stock;

    char date[100] = "";
    strcpy(date, dateNow());
    char path[100] = "";

    if (verifSaveAuto == true) {
        strcat(path, "..\\saveauto\\");
        strcat(path, "saveAuto");
        strcpy(nameFileAuto, date);
    }
    if (verifSaveAuto == false) {
        strcat(path, "..\\save\\");
        strcat(path, "saveManuelle");
        strcpy(nameFileManuelle, date);
    }


    strcat(path, ".txt");

    FILE *fichier = NULL;

    fichier = fopen(path, "w+");

    if (fichier != NULL) {
        fprintf(fichier, "=== PLAYER ===\n{LEVEL}\n{%d}/{0}\n{%d}/{%d}\n-- INVENTORY --\n", player->experience,
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
        fprintf(fichier, "===MAP===\n");

        for (int i = 0; i < 3; ++i) {
            fprintf(fichier, "\n--ZONE%d--", i);
            for (int j = 0; j < mapSize[i]; ++j) {
                fprintf(fichier, "\n");
                for (int k = 0; k < mapSize[i]; ++k) {
                    fprintf(fichier, "%d ", map_list[i][j][k]);
                }
            }
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

void charge(Player *player, PnjLinkedList *stock, bool verifSaveAuto, AllItemCraft *allItemCraft) {

    char path[50] = "";
    if (verifSaveAuto == true) {
        strcat(path, "..\\saveauto\\");
        strcat(path, "saveAuto");
        strcat(path, ".txt");
    }
    if (verifSaveAuto == false) {
        strcat(path, "..\\save\\");
        strcat(path, "saveManuelle");
        strcat(path, ".txt");
    }
    //LIRE LE NOMBRE DE LIGNE
    FILE *fichier;
    fichier = fopen(path, "r");
    int c;
    int nLignes = 0;
    int stopStock = 0;
    while ((c = fgetc(fichier)) != EOF) {
        if (c == '\n') {
            nLignes++;
        }
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
            player->experience = i;
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