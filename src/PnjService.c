#include "../include/include.h";

void pnjChoice(Player *playerStruct) {
    int c;

    printf("\n Bonjour, je suis le pnj que souhaitez vous faire ? \n 1 = Reparer votre item \n 2 = Crafter un nouvelle item \n 3 = Stocker un item \n Votre choix : ");

    scanf("%d", &c);

    switch (c) {

        case 1:
            pnjFix(playerStruct);
            break;

        case 2 :
            printf("\n deux");
            break;

        case 3 :
            printf("\n trois");
            break;

        default :
            printf("\n Choix non disponible, Aurevoir.\n");

    }
}

void pnjFix(Player *playerStruct) {
    for (int i = 0; i < sizeof(playerStruct->inventory[i].type); i++) {
        printf(" %s ,", playerStruct->inventory[i].tools.name);
    }
}