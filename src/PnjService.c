#include "../include/include.h"

extern int countDelet = 0;

void pnjChoice(Player *playerStruct, PnjLinkedList *stock) {
    /* Création du nouvel élément */
    int c;

    printf("\n Bonjour, je suis le pnj que souhaitez vous faire ? \n 1 = Reparer votre item \n 2 = Crafter un nouvelle item \n 3 = Deposer un item \n 4 = Recuperer un item \n "
           "5 = Quitter \n Votre choix : ");

    scanf("%d", &c);

    switch (c) {

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
            printf("\n quatre");
            break;

        case 5 :
            printf("\n quatre");
            break;

        default :
            printf("\n Choix non disponible, Aurevoir.\n");

    }
}

void pnjFix(Player *playerStruct) {
    int fix = 0;
    int verif = 0;
    printf("\nVeuillez choisir l'item a reparer :\n");

    for (int i = 0; i < sizeof(playerStruct->inventory[i].type); i++) {
        printf("%d = %s , durability = %.2lf\n", playerStruct->inventory[i].tools.id,
               playerStruct->inventory[i].tools.name, playerStruct->inventory[i].tools.actual_durabiulity);
    }
    printf("Votre choix : ");
    scanf("%d", &fix);
    for (int i = 0; i < sizeof(playerStruct->inventory[i].type); i++) {
        if (playerStruct->inventory[i].tools.id == fix) {
            playerStruct->inventory[i].tools.actual_durabiulity = playerStruct->inventory[i].tools.max_durability;
            printf("Votre item a ete rapare ! \n%d = %s , durability = %.2lf\n", playerStruct->inventory[i].tools.id,
                   playerStruct->inventory[i].tools.name, playerStruct->inventory[i].tools.actual_durabiulity);
            verif = 1;
        }
    }
    if (verif == 0) {
        printf("Votre item n'est pas dans votre inventaire !\n");
    }
}

void pnjStock(Player *playerStruct, PnjLinkedList *stock) {

    int stockItem = 0;
    Item data;
    int index;
    int verif = 0;

    printf("\nVeuillez choisir l'item a stocker:\n");

    for (int i = 0; i < sizeof(playerStruct->inventory[i].tools.id) - countDelet; i++) {
        printf("%d = %s \n", playerStruct->inventory[i].tools.id,
               playerStruct->inventory[i].tools.name);
    }
    printf("Votre choix : ");
    scanf("%d", &stockItem);
    for (int i = 0; i < sizeof(playerStruct->inventory[i].type); i++) {
        if (playerStruct->inventory[i].tools.id == stockItem) {
            data = playerStruct->inventory[i];
            verif = 1;
            index = i;
        }
    }
    if (verif == 0) {
        printf("Votre item n'est pas dans votre inventaire !\n");
    } else {
        ++countDelet;
        deleteElement(playerStruct->inventory, sizeof(playerStruct->inventory) / sizeof(playerStruct->inventory[0]),
                      index);
    }
    insertion(&data, stock);
    afficherListe(playerStruct, stock);
}

void deleteElement(Item arr[], int n, int x) {
// Search x in array
    int i;
    for (i = 0; i < n; i++)
        if (i == x)
            break;

// If x found in array
    if (i < n) {
        // reduce size of array and move all
        // elements on space ahead
        n = n - 1;
        for (int j = i; j < n; j++)
            arr[j] = arr[j + 1];
    }
}

void initStructStock(PnjLinkedList *stock) {
    stock->next = NULL;
    stock->data = malloc(sizeof(Item));
}

void insertion(Item *nvItem, PnjLinkedList *actualStockPos) {
    int verif = 0;
    if (actualStockPos == NULL) {
        actualStockPos = malloc(sizeof(PnjLinkedList));
        actualStockPos->data = nvItem;
        actualStockPos->next = NULL;
    } else {
        PnjLinkedList *cache = actualStockPos;
        while (cache->next != NULL) {
            cache = cache->next;
            verif++;
        }
        cache->next = malloc(sizeof(PnjLinkedList));
        cache->data = nvItem;
        cache = cache->next;
        cache->next = NULL;
    }
}


void afficherListe(Player *playerStruct, PnjLinkedList *stock) {
    PnjLinkedList *cache = stock;
    while (cache->next != NULL) {
        printf("%s -> ", cache->data->weapon.name);
        cache = cache->next;
    }
    pnjStock(playerStruct, stock);
}