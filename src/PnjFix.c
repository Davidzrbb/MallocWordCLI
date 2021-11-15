#include "../include/include.h"
#include "../include/pnjService.h"

void pnjFix(Player *playerStruct) {
    if (countDelet < sizeof(playerStruct->inventory[0].tools.id)) {

        for (int i = 0; i < sizeof(playerStruct->inventory[i].type); i++) {
            playerStruct->inventory[i].tools.actual_durabiulity = playerStruct->inventory[i].tools.max_durability;
        }
        printf("\nVos item sont rapares !\n");
    } else {
        printf("\nVous n'avez plus d'item dans votre inventaire !\n");
    }
}