#include "../include/include.h"
#include "../include/pnjService.h"

#include "../include/save.h"


void pnjStock(Player *playerStruct, PnjLinkedList *stock) {

    int stockItem = -1;
    Item nvItem;
    int index;
    int verif = 0;

    if (countDelet < sizeof(playerStruct->inventory[0].tools.id)) {
        printf("\nVeuillez choisir l'item a stocker:\n");
        for (int i = 0; i < 10; i++) {
            if (playerStruct->inventory[i].type > 0 && playerStruct->inventory[i].type < 6) {
                printf("%d = %s \n", playerStruct->inventory[i].tools.id,
                       playerStruct->inventory[i].tools.name);
            }
        }
        printf("0 = Quitter");
        printf("\nVotre choix : ");
        scanf("%d", &stockItem);
        for (int i = 0; i < 10; i++) {
            if (playerStruct->inventory[i].tools.id == stockItem) {
                nvItem = playerStruct->inventory[i];
                verif = 1;
                index = stockItem;
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
            saveFile(playerStruct, stock);
            displayStock(playerStruct, stock);

        }

    } else {
        printf("\nVous n'avez plus d'item dans votre inventaire\n");
        pnjChoice(playerStruct, stock);
    }

}

void deleteElementInventory(Item inventory[], int sizeArr, int index) {
    int i;
    int j;

    for (i = 0; i < sizeArr; i++) {
        if (inventory[i].tools.id == index) {
            for (j = i; j < 10; j++) {
                if (j < 10 - 1) {
                    inventory[j] = inventory[j + 1];
                } else {
                    inventory[j].type = -1;
                }
            }
            break;
        }
    }


}

void initStructStock(PnjLinkedList *stock) {
    stock->next = NULL;
    stock->data = malloc(sizeof(Item));
    stock->data->tools.name = malloc(sizeof(char *));
}


void insertionToStock(Item *nvItem, PnjLinkedList *stock) {
    if (stock == NULL) {
        stock = malloc(sizeof(PnjLinkedList));
        stock->data = nvItem;
        stock->next = NULL;
    } else {
        PnjLinkedList *cache = stock;
        while (cache->next != NULL) {
            cache = cache->next;
        }
        cache->next = malloc(sizeof(PnjLinkedList *));
        cache->data = nvItem;
        cache = cache->next;
        cache->next = NULL;
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
        //   saveFile(playerStruct, stock);
        pnjChoice(playerStruct, stock);
    } else {
        printf("\nVotre stock est vide !\n");
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

PnjLinkedList *deleteElementLinkedList(Player *playerStruct, PnjLinkedList *stock, int choiceRecover) {
    PnjLinkedList *tmp;
    PnjLinkedList *previous;

    if (stock == NULL) {
        return (stock);
    }
    previous = stock;
    if (previous->data->weapon.id == choiceRecover) {
        sizeInv = 0;
        for (int i = 0; i < 10; i++) {
            if (playerStruct->inventory[i].type > 0 && playerStruct->inventory[i].type < 6) {
                sizeInv++;
            }
        }
        playerStruct->inventory[sizeInv] = *previous->data;
        --countDelet;
        printf("%s est maitenant dans votre inventaire !\n", previous->data->weapon.name);
        stock = previous->next;
        return (stock);
    }
    tmp = previous->next;
    while (tmp != NULL) {
        if (previous->data->weapon.id == choiceRecover) {
            previous->next = tmp->next;
            playerStruct->inventory[sizeInv] = *previous->data;
            --countDelet;
            printf("%s est maitenant dans votre inventaire !\n", previous->data->weapon.name);
            return (stock);
        }
        previous = tmp;
        tmp = tmp->next;
    }
    return stock;
}

