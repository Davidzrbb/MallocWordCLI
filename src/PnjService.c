#include "../include/include.h"

void pnjChoice(Player *playerStruct, PnjLinkedList *nouveau) {
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
            pnjStock(playerStruct, nouveau);
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

void pnjStock(Player *playerStruct, PnjLinkedList *nouveau) {

    int stockItem = 0;
    Item data;
    int index;
    int verif = 0;
    printf("\nVeuillez choisir l'item a stocker:\n");
    for (int i = 0; i < sizeof(playerStruct->inventory[i].type); i++) {
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
        //ON SUPRIME L'ELEMENT DANS LE TABLEAU
        for (int i = index; i < sizeof(playerStruct->inventory->type) - 1; i++) {
            playerStruct->inventory[i] = playerStruct->inventory[i + 1];
        }
    }

    insertion(&data, nouveau);
    afficherListe(playerStruct, nouveau);
}

PnjLinkedList *insertion(Item *nvItem, PnjLinkedList *actualStockPos) {
    if (actualStockPos == NULL) {
        printf("NULL");
        actualStockPos = malloc(sizeof(PnjLinkedList));
        actualStockPos->data = nvItem;
        actualStockPos->next = NULL;
    } else {
        printf(" PAS NULL");
        PnjLinkedList *cache = actualStockPos;
        while (cache->next != NULL) {
            cache = cache->next;
        }
        cache->next = malloc(sizeof(PnjLinkedList));
        cache = cache->next;
        cache->data = nvItem;
        cache->next = NULL;

        return cache;
    }

    return actualStockPos;
}


void afficherListe(Player *playerStruct, PnjLinkedList *nouveau) {
    while (nouveau->next != NULL) {
        printf("%d -> ", nouveau->data->weapon.id);
        nouveau = nouveau->next;
    }
    printf("NULL\n");
    pnjStock(playerStruct, nouveau);
}