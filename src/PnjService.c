#include "../include/include.h";

void pnjChoice(Player *playerStruct) {
    int c;

    printf("\n Bonjour, je suis le pnj que souhaitez vous faire ? \n 1 = Reparer votre item \n 2 = Crafter un nouvelle item \n 3 = Stocker un item \n 4 = Quitter \n Votre choix : ");

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

        case 4 :
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
        printf("Votre item n'est pas dans votre inventaire !");
    }
    pnjChoice(playerStruct);
}