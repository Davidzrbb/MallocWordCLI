#include "../include/include.h"
#include "../include/pnjService.h"
#include "../include/save.h"
#include "../include/map.h"

void startChoice() {
    int saveChoice = 0;
    int typeCharge = 0;
    int validationManuelle = -1;
    int validationAuto = -1;

    Player *player = malloc(sizeof(Player));
    PnjLinkedList *stock = malloc(sizeof(PnjLinkedList));

    AllItemCraft *allItemCraft = malloc(sizeof(AllItemCraft));
    initArrayCraftItem(allItemCraft);


    while (saveChoice != 1 && saveChoice != 2) {
        printf("\nCharger une partie ! Taper 1\n");
        printf("Nouvelle partie ! Taper 2\n");
        scanf("%d", &saveChoice);

        //charge
        if (saveChoice == 1) {
            printf("\nVoir les charges automatiques ! Taper 1\n");
            printf("Voir les charges manuelles ! Taper 2\n");
            scanf("%d", &typeCharge);
            //charge auto
            if (typeCharge == 1) {
                if (strcmp(nameFileAuto, "") == 0) {
                    printf("\nVous n'avez pas de charge auto !\n");
                    saveChoice = 0;
                } else {
                    printf("\nDerniere sauvegarde auto %s \n", nameFileAuto);
                    printf("\nConfirmer ! Taper 1\n");
                    printf("Retour ! Taper 0\n");
                    scanf("%d", &validationAuto);
                    if (validationAuto == 1) {
                        saveChoice = 1;
                    } else {
                        saveChoice = 0;
                    }
                }
            }
            //charge manuelle
            if (typeCharge == 2) {
                if (strcmp(nameFileManuelle, "") == 0) {
                    printf("\nVous n'avez pas de charge manuelle !\n");
                    saveChoice = 0;
                } else {
                    printf("\nDerniere sauvegarde manuelle %s\n", nameFileManuelle);
                    printf("\nConfirmer ! Taper 1\n");
                    printf("Retour ! Taper 0\n");
                    scanf("%d", &validationManuelle);
                    if (validationManuelle == 1) {
                        saveChoice = 1;
                    } else {
                        saveChoice = 0;
                    }
                }
            }
        }
    }
    //New partie
    if (saveChoice == 2) {
        initStartGame(player, stock);
    }

    if (validationAuto == 1) {
        initStructStock(stock);
        charge(player, stock, true, allItemCraft);
    }

    if (validationManuelle == 1) {
        initStructStock(stock);
        charge(player, stock, false, allItemCraft);
    }
}