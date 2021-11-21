#include "../include/include.h"
#include "../include/pnjService.h"
#include "../include/save.h"
#include "../include/map.h"


void startChoice(Player *player, PnjLinkedList *stock) {
    dateNow();
    int saveChoice = 0;
    while (saveChoice != 1 && saveChoice != 2) {
        printf("\nCharger une partie ! Taper 1\n");
        printf("\nNouvelle partie ! Taper 2\n");
        scanf("%d", &saveChoice);
    }
    //charge
    if (saveChoice == 1) {

    }
    //New partie
    if (saveChoice == 2) {
        initStartGame(player, stock);
    }
}

int saveFile(int *mapSize, int ***map_list, Player *player, PnjLinkedList *stock, bool verifSaveAuto) {

    PnjLinkedList *cache = stock;

    char date[100];
    strcpy(date, dateNow());
    char path[100] = "";

    if (verifSaveAuto == true) {
        strcat(path, "..\\saveauto\\");
    }
    if (verifSaveAuto == false) {
        strcat(path, "..\\save\\");
    }

    strcat(path, date);
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