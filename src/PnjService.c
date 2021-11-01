#include "../include/include.h"
#include "../include/pnjService.h"

extern int countDelet = 0;
extern int choicePnj = 0;

void pnjChoice(Player *playerStruct, PnjLinkedList *stock) {
    /* Création du nouvel élément */
    while (choicePnj != 5) {
        printf("\n Bonjour, je suis le pnj que souhaitez vous faire ? \n 1 = Reparer vos items \n 2 = Crafter un nouvelle item \n 3 = Deposer un item \n 4 = Recuperer un item \n "
               "0 = Quitter \n Votre choix : ");

        scanf("%d", &choicePnj);

        switch (choicePnj) {

            case 1:
                pnjFix(playerStruct);
                break;

            case 2 :
                printf("\n quatre");
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

void pnjStock(Player *playerStruct, PnjLinkedList *stock) {

    int stockItem = -1;
    Item nvItem;
    int index;
    int verif = 0;

    if (countDelet < sizeof(playerStruct->inventory[0].tools.id)) {
        printf("\nVeuillez choisir l'item a stocker:\n");
        for (int i = 0; i < sizeof(playerStruct->inventory[i].tools.id) - countDelet; i++) {
            printf("%d = %s \n", playerStruct->inventory[i].tools.id,
                   playerStruct->inventory[i].tools.name);
        }
        printf("0 = Quitter");
        printf("\nVotre choix : ");
        scanf("%d", &stockItem);
        for (int i = 0; i < sizeof(playerStruct->inventory[i].type); i++) {
            if (playerStruct->inventory[i].tools.id == stockItem) {
                nvItem = playerStruct->inventory[i];
                verif = 1;
                index = i;
            }
        }
        if (verif == 0) {
            if (stockItem != 0) {
                printf("\nVotre item n'est pas dans votre inventaire !\n");

            }
            pnjChoice(playerStruct, stock);
        } else {
            ++countDelet;
            deleteElementInventory(playerStruct->inventory,
                                   sizeof(playerStruct->inventory) / sizeof(playerStruct->inventory[0]),
                                   index);
            insertionToStock(&nvItem, stock);
            displayStock(playerStruct, stock);
        }

    } else {
        printf("\nVous n'avez plus d'item dans votre inventaire\n");
        pnjChoice(playerStruct, stock);
    }

}

void deleteElementInventory(Item inventory[], int sizeArr, int index) {
    int i;
    for (i = 0; i < sizeArr; i++)
        if (i == index)
            break;
    if (i < sizeArr) {
        sizeArr = sizeArr - 1;
        for (int j = i; j < sizeArr; j++)
            inventory[j] = inventory[j + 1];
    }
}

void initStructStock(PnjLinkedList *stock) {
    stock->next = NULL;
    stock->data = malloc(sizeof(Item));
    stock->data->tools.name = malloc(sizeof(char *));
}

void insertionToStock(Item *nvItem, PnjLinkedList *actualStockPos) {
    if (actualStockPos == NULL) {
        actualStockPos = malloc(sizeof(PnjLinkedList));
        actualStockPos->data = nvItem;
        actualStockPos->next = NULL;
    } else {
        PnjLinkedList *cache = actualStockPos;
        while (cache->next != NULL) {
            cache = cache->next;
        }
        cache->next = malloc(sizeof(PnjLinkedList *));
        cache->data = nvItem;
        cache = cache->next;
        cache->next = NULL;
    }
}

void displayStock(Player *playerStruct, PnjLinkedList *stock) {
    printf("\nVotre stock : \n");
    PnjLinkedList *cache = stock;
    while (cache->next != NULL) {
        printf("%d = %s \n", cache->data->weapon.id, cache->data->weapon.name);
        cache = cache->next;
    }
    if (choicePnj == 3) {
        pnjStock(playerStruct, stock);
    }
}

void recoverItemStockToInventory(Player *playerStruct, PnjLinkedList *stock) {
    if (stock->next != NULL) {
        int choiceRecover = 0;
        printf("\nQu'elle item souhaitez-vous recuperer ?");
        displayStock(playerStruct, stock);
        printf("0 = Quitter \nVotre choix : ");
        scanf("%d", &choiceRecover);
        if (choiceRecover != 0) {
            stock = deleteElementLinkedList(playerStruct, stock, choiceRecover);
            if (stock->next != NULL) {
                recoverItemStockToInventory(playerStruct, stock);
            }
        }
        pnjChoice(playerStruct, stock);
    }else{
        printf("\nVotre stock est vide !\n");
    }
}

PnjLinkedList *deleteElementLinkedList(Player *playerStruct, PnjLinkedList *stock, int choiceRecover) {
    PnjLinkedList *tmp;
    PnjLinkedList *previous;

    if (stock == NULL) {
        return (stock);
    }
    previous = stock;
    if (previous->data->weapon.id == choiceRecover) {
        playerStruct->inventory[sizeof(playerStruct->inventory[0].tools.id) - countDelet] = *previous->data;
        --countDelet;
        printf("%s est maitenant dans votre inventaire !\n", previous->data->weapon.name);
        stock = previous->next;
        return (stock);
    }
    tmp = previous->next;
    while (tmp != NULL) {
        if (previous->data->weapon.id == choiceRecover) {
            previous->next = tmp->next;
            playerStruct->inventory[sizeof(playerStruct->inventory[0].tools.id) - countDelet] = *previous->data;
            --countDelet;
            printf("%s est maitenant dans votre inventaire !\n", previous->data->weapon.name);
            return (stock);
        }
        previous = tmp;
        tmp = tmp->next;
    }
    return stock;
}

