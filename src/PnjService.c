#include "../include/include.h"
#include "../include/pnjService.h"

int countDelet = 0;
int choicePnj = -1;
int sizeInv =0;

void pnjChoice(Player *playerStruct, PnjLinkedList *stock) {
    /* Création du nouvel élément */
    while (choicePnj != 0) {
        printf("\n Bonjour, je suis le pnj que souhaitez vous faire ? \n 1 = Reparer vos items \n 2 = Craft \n 3 = Deposer un item \n 4 = Recuperer un item \n "
               "0 = Quitter \n Votre choix : ");

        scanf("%d", &choicePnj);

        switch (choicePnj) {

            case 1:
                pnjFix(playerStruct);
                break;

            case 2 :
                craftItem(playerStruct);
                break;

            case 3 :
                pnjStock(playerStruct, stock);
                break;

            case 4 :
                recoverItemStockToInventory(playerStruct, stock);
                break;

            case 0 :
                printf("\n A bientot !");
                break;

            default :
                printf("\n Choix non disponible\n");

        }
    }

}



