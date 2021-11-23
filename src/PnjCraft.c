#include "../include/include.h"
#include "../include/pnjService.h"
#include "../include/collecteResource.h"

void craftItem(Player *playerStruct) {
    //init tab craft
    ArrayItemCraft *arrayItemCraft = malloc(sizeof(ArrayItemCraft));
    AllItemCraft *allItemCraft = malloc(sizeof(AllItemCraft));
    initArrayCraftItem(allItemCraft);
    int choiceCraft = -1;
    while (choiceCraft == -1) {
        printf("\n 1 = Voir tous les crafts \n 2 = Crafter un nouvelle item \n 0 = Quitter \n Votre choix : ");

        scanf("%d", &choiceCraft);

        switch (choiceCraft) {

            case 1:
                displayItemCraft(allItemCraft);
                break;

            case 2 :
                createItemCraft(allItemCraft, playerStruct, 0);
                break;

            case 0 :
                break;

            default :
                printf("\n Choix non disponible\n");
        }
    }
    free(allItemCraft);
    free(arrayItemCraft);
}

void displayItemCraft(AllItemCraft *allItemCraft) {
    printf("\nARMES : \n");
    displayItemCraftSection(allItemCraft, WEAPON);
    printf("\nOUTILS : \n");
    displayItemCraftSection(allItemCraft, TOOL);
    printf("\nARMURES : \n");
    displayItemCraftSection(allItemCraft, ARMOR);
    printf("\nPOTION : \n");
    displayItemCraftSection(allItemCraft, HEAL);
}

void displayItemCraftSection(AllItemCraft *allItemCraft, int type) {
    char *resourceNameString;
    char *resourceNameString2;

    for (int i = 0; i < 25; i++) {
        if (allItemCraft->itemCraft[i].type == type) {
            if (allItemCraft->itemCraft[i].arrayItemCraftNecessary[1] == -1) {
                resourceNameString = resourceName(allItemCraft->itemCraft[i].arrayItemCraftNecessary[0]);
                printf("| %s = %d %s \n", allItemCraft->itemCraft[i].name,
                       allItemCraft->itemCraft[i].arrayQuantityCraftNecessary[0],
                       resourceNameString);
            }
            if (allItemCraft->itemCraft[i].arrayItemCraftNecessary[1] != -1) {
                resourceNameString = resourceName(allItemCraft->itemCraft[i].arrayItemCraftNecessary[0]);
                resourceNameString2 = resourceName(allItemCraft->itemCraft[i].arrayItemCraftNecessary[1]);
                printf("| %s = %d %s + %d %s \n", allItemCraft->itemCraft[i].name,
                       allItemCraft->itemCraft[i].arrayQuantityCraftNecessary[0],
                       resourceNameString,
                       allItemCraft->itemCraft[i].arrayQuantityCraftNecessary[1],
                       resourceNameString2);
            }
        }
    }
}

void createItemCraft(AllItemCraft *allItemCraft, Player *playerStruct, int choiceItemCraft) {
    int *verifItemCraftArray;
    verifItemCraftArray = verifItemCraft(allItemCraft, playerStruct);
    choiceItemCraft = verifItemCraftArray[0];
    if (choiceItemCraft != 0) {
        addItemCraft(allItemCraft, playerStruct, verifItemCraftArray);
    }
}

void addItemCraft(AllItemCraft *allItemCraft, Player *playerStruct, const int *verifItemCraftArray) {
    //On verifie la disponibilité dans l'inventory du Player et on ajoute
    int sizeinv = 0;
    int healQuantity = 0;
    int addQuantityHeal = 0;
    int count = 0;
    int choiceItemCraft = verifItemCraftArray[0];
    bool checkChoice = false;
    for (int i = 0; i < 26; i++) {
        if (i != 0) {
            if (choiceItemCraft == verifItemCraftArray[i]) {
                checkChoice = true;
            }
        }
    }
    if (checkChoice == true) {
        for (int i = 0; i < 10; i++) {
            if (playerStruct->inventory[i].type > 0 && playerStruct->inventory[i].type < 6) {
                if (playerStruct->inventory[i].heal.id == choiceItemCraft) {
                    if (playerStruct->inventory[i].type == HEAL) {
                        if (playerStruct->inventory[i].heal.quantity > 19) {
                            healQuantity = -1;
                        } else {
                            healQuantity = i;
                        }
                    }
                } else {
                    healQuantity = -1;
                }
                sizeinv = i;
            }
        }
        if (sizeinv < 9) {
            sizeinv++;
            for (int i = 0; i < 25; i++) {
                if (allItemCraft->itemCraft[i].idCreation == choiceItemCraft) {
                    if (allItemCraft->itemCraft[i].type == TOOL) {
                        playerStruct->inventory[sizeinv].tools.id = choiceItemCraft;
                        playerStruct->inventory[sizeinv].tools.name = allItemCraft->itemCraft[i].name;
                        playerStruct->inventory[sizeinv].tools.actual_durabiulity = allItemCraft->itemCraft[i].actual_durabiulity;
                        playerStruct->inventory[sizeinv].tools.max_durability = allItemCraft->itemCraft[i].max_durability;
                    }
                    if (allItemCraft->itemCraft[i].type == WEAPON) {
                        playerStruct->inventory[sizeinv].weapon.id = choiceItemCraft;
                        playerStruct->inventory[sizeinv].weapon.name = allItemCraft->itemCraft[i].name;
                        playerStruct->inventory[sizeinv].weapon.actual_durabiulity = allItemCraft->itemCraft[i].actual_durabiulity;
                        playerStruct->inventory[sizeinv].weapon.max_durability = allItemCraft->itemCraft[i].max_durability;
                        playerStruct->inventory[sizeinv].weapon.damage = allItemCraft->itemCraft[i].damage;
                    }
                    if (allItemCraft->itemCraft[i].type == ARMOR) {
                        playerStruct->inventory[sizeinv].armor.id = choiceItemCraft;
                        playerStruct->inventory[sizeinv].armor.name = allItemCraft->itemCraft[i].name;
                        playerStruct->inventory[sizeinv].armor.protection = allItemCraft->itemCraft[i].protection;
                    }
                    if (allItemCraft->itemCraft[i].type == HEAL) {
                        if (healQuantity == -1) {
                            playerStruct->inventory[sizeinv].heal.id = choiceItemCraft;
                            playerStruct->inventory[sizeinv].heal.name = allItemCraft->itemCraft[i].name;
                            playerStruct->inventory[sizeinv].heal.quantity = allItemCraft->itemCraft[i].quantity;
                            playerStruct->inventory[sizeinv].heal.pvRestore = allItemCraft->itemCraft[i].pvRestore;
                        } else {
                            playerStruct->inventory[healQuantity].heal.quantity += 1;
                            addQuantityHeal = 1;
                        }
                    }
                    if (addQuantityHeal == 0) {
                        playerStruct->inventory[sizeinv].type = allItemCraft->itemCraft[i].type;
                    }
                }
            }
            if (addQuantityHeal == 0) {
                printf("\nItem ajoutee a votre inventaire : %s \n",
                       playerStruct->inventory[sizeinv].resource.name);
            } else {
                printf("\nItem ajoutee a votre inventaire : %s \n",
                       playerStruct->inventory[healQuantity].resource.name);
            }

        } else {
            printf("\nVous avez deja 10 inventaires !\n");
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 25; j++) {
                if (allItemCraft->itemCraft[j].idCreation == choiceItemCraft) {
                    if (playerStruct->inventory[i].resource.id ==
                        allItemCraft->itemCraft[j].arrayItemCraftNecessary[0] &&
                        playerStruct->inventory[i].resource.quantity >=
                        allItemCraft->itemCraft[j].arrayQuantityCraftNecessary[0] &&
                        allItemCraft->itemCraft[j].arrayItemCraftNecessary[1] == -1) {

                        playerStruct->inventory[i].resource.quantity -= allItemCraft->itemCraft[j].arrayQuantityCraftNecessary[0];

                        printf("\nIl vous reste %d %s\n", playerStruct->inventory[i].resource.quantity,
                               playerStruct->inventory[i].resource.name);
                        //supression si quantity =0
                        if (playerStruct->inventory[i].resource.quantity == 0) {
                            deleteElementInventory(playerStruct->inventory,
                                                   sizeof(playerStruct->inventory) / sizeof(playerStruct->inventory[0]),
                                                   playerStruct->inventory[i].resource.id);
                        }

                    }
                    if (playerStruct->inventory[i].resource.id ==
                        allItemCraft->itemCraft[j].arrayItemCraftNecessary[0] &&
                        playerStruct->inventory[i].resource.quantity >=
                        allItemCraft->itemCraft[j].arrayQuantityCraftNecessary[0] &&
                        allItemCraft->itemCraft[j].arrayItemCraftNecessary[1] != -1) {
                        count = 1;
                    }
                    if (count == 1) {
                        for (int k = 0; k < 10; k++) {
                            if (playerStruct->inventory[k].resource.id ==
                                allItemCraft->itemCraft[j].arrayItemCraftNecessary[1] &&
                                playerStruct->inventory[k].resource.quantity >=
                                allItemCraft->itemCraft[j].arrayQuantityCraftNecessary[1]) {

                                playerStruct->inventory[i].resource.quantity -= allItemCraft->itemCraft[j].arrayQuantityCraftNecessary[0];
                                playerStruct->inventory[k].resource.quantity -= allItemCraft->itemCraft[j].arrayQuantityCraftNecessary[1];

                                printf("\nIl vous reste %d %s et %d %s\n",
                                       playerStruct->inventory[i].resource.quantity,
                                       playerStruct->inventory[i].resource.name,
                                       playerStruct->inventory[k].resource.quantity,
                                       playerStruct->inventory[k].resource.name);

                                //supression si quantity =0
                                if (playerStruct->inventory[i].resource.quantity == 0) {
                                    deleteElementInventory(playerStruct->inventory,
                                                           sizeof(playerStruct->inventory) /
                                                           sizeof(playerStruct->inventory[0]),
                                                           playerStruct->inventory[i].resource.id);
                                }
                                if (playerStruct->inventory[k].resource.quantity == 0) {
                                    deleteElementInventory(playerStruct->inventory,
                                                           sizeof(playerStruct->inventory) /
                                                           sizeof(playerStruct->inventory[0]),
                                                           playerStruct->inventory[k].resource.id);
                                }
                            }
                        }
                    }
                }
            }
            count = 0;
        }
    } else {
        printf("Votre choix n'est pas possible !");
    }
}

int *verifItemCraft(AllItemCraft *allItemCraft, Player *playerStruct) {
    int count = 0;
    int sizeinv = 0;
    int countArmor = 0;
    int choiceItemCraft;
    int c = 0;
    static int verifItemCraftArray[26];

    for (int i = 0; i < 26; i++) {
        verifItemCraftArray[i] = -1;
    }

    if (countDelet < sizeof(playerStruct->inventory[0].tools.id)) {
        for (int i = 0; i < 10; i++) {
            if (playerStruct->inventory[i].type > 0 && playerStruct->inventory[i].type < 6) {
                sizeinv = i;
                if (playerStruct->inventory[i].type == ARMOR) {
                    countArmor = 1;
                }
            }
        }
        if (sizeinv < 9) {
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < 25; j++) {
                    if (playerStruct->inventory[i].resource.id ==
                        allItemCraft->itemCraft[j].arrayItemCraftNecessary[0] &&
                        playerStruct->inventory[i].resource.quantity >=
                        allItemCraft->itemCraft[j].arrayQuantityCraftNecessary[0] &&
                        allItemCraft->itemCraft[j].arrayItemCraftNecessary[1] == -1) {
                        printf("\nAvec %d de %s, vous pouvez faire %s ! Taper %d\n",
                               playerStruct->inventory[i].resource.quantity,
                               playerStruct->inventory[i].resource.name,
                               allItemCraft->itemCraft[j].name, allItemCraft->itemCraft[j].idCreation);
                        c = j + 1;
                        verifItemCraftArray[c] = allItemCraft->itemCraft[j].idCreation;
                    }
                    if (playerStruct->inventory[i].resource.id ==
                        allItemCraft->itemCraft[j].arrayItemCraftNecessary[0] &&
                        playerStruct->inventory[i].resource.quantity >=
                        allItemCraft->itemCraft[j].arrayQuantityCraftNecessary[0] &&
                        allItemCraft->itemCraft[j].arrayItemCraftNecessary[1] != -1) {
                        count = 1;
                    }
                    if (count == 1) {
                        for (int k = 0; k < 10; k++) {
                            if (playerStruct->inventory[k].resource.id ==
                                allItemCraft->itemCraft[j].arrayItemCraftNecessary[1] &&
                                playerStruct->inventory[k].resource.quantity >=
                                allItemCraft->itemCraft[j].arrayQuantityCraftNecessary[1]) {

                                printf("\nAvec %d de %s et %d de %s, vous pouvez faire %s ! Taper %d\n",
                                       playerStruct->inventory[i].resource.quantity,
                                       playerStruct->inventory[i].resource.name,
                                       playerStruct->inventory[k].resource.quantity,
                                       playerStruct->inventory[k].resource.name,
                                       allItemCraft->itemCraft[j].name, allItemCraft->itemCraft[j].idCreation);
                                c = j + 1;
                                verifItemCraftArray[c] = allItemCraft->itemCraft[j].idCreation;
                            }
                        }
                    }
                }
                count = 0;
            }
            printf("\nAnnuler, Taper 0\n");
            printf("\nVotre choix : ");
            scanf("%d", &choiceItemCraft);
            if (choiceItemCraft == 11 || choiceItemCraft == 22 || choiceItemCraft == 33) {
                if (countArmor == 1) {
                    printf("\nMax une armure dans l'inventaire, veuillez la deposer dans le stock !\n");
                    choiceItemCraft = 0;
                }
            }
            verifItemCraftArray[0] = choiceItemCraft;
            return verifItemCraftArray;
        } else {
            printf("\nVous avez deja 10 inventaires !\n");
            verifItemCraftArray[0] = 0;
            return verifItemCraftArray;
        }


    } else {
        printf("\nVous n'avez plus d'item dans votre inventaire !\n");
        verifItemCraftArray[0] = 0;
        return verifItemCraftArray;
    }

}

void initArrayCraftItem(AllItemCraft *allItemCraft) {
    ArrayItemCraft *swordWoodWeaponCraft = malloc(sizeof(ArrayItemCraft));
    swordWoodWeaponCraft->name = malloc(sizeof(char *));
    swordWoodWeaponCraft->name = "epee en bois";
    swordWoodWeaponCraft->idCreation = WOODEN_SWORD;
    swordWoodWeaponCraft->arrayItemCraftNecessary[0] = FIR;
    swordWoodWeaponCraft->arrayItemCraftNecessary[1] = -1;
    swordWoodWeaponCraft->arrayQuantityCraftNecessary[0] = 3;
    swordWoodWeaponCraft->arrayQuantityCraftNecessary[1] = -1;
    swordWoodWeaponCraft->type = WEAPON;
    swordWoodWeaponCraft->max_durability = 10;
    swordWoodWeaponCraft->actual_durabiulity = 10;
    swordWoodWeaponCraft->damage = 1;


    ArrayItemCraft *swordRockWeaponCraft = malloc(sizeof(ArrayItemCraft));
    swordRockWeaponCraft->name = malloc(sizeof(char *));
    swordRockWeaponCraft->name = "epee en pierre";
    swordRockWeaponCraft->idCreation = STONE_SWORD;
    swordRockWeaponCraft->arrayItemCraftNecessary[0] = FIR;
    swordRockWeaponCraft->arrayItemCraftNecessary[1] = ROCK;
    swordRockWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    swordRockWeaponCraft->arrayQuantityCraftNecessary[1] = 3;
    swordRockWeaponCraft->type = WEAPON;
    swordRockWeaponCraft->max_durability = 10;
    swordRockWeaponCraft->actual_durabiulity = 10;
    swordRockWeaponCraft->damage = 2;

    ArrayItemCraft *swordIronWeaponCraft = malloc(sizeof(ArrayItemCraft));
    swordIronWeaponCraft->name = malloc(sizeof(char *));
    swordIronWeaponCraft->name = "epee en fer";
    swordIronWeaponCraft->idCreation = IRON_SWORD;
    swordIronWeaponCraft->arrayItemCraftNecessary[0] = BEECH;
    swordIronWeaponCraft->arrayItemCraftNecessary[1] = IRON;
    swordIronWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    swordIronWeaponCraft->arrayQuantityCraftNecessary[1] = 4;
    swordIronWeaponCraft->type = WEAPON;
    swordIronWeaponCraft->max_durability = 10;
    swordIronWeaponCraft->actual_durabiulity = 10;
    swordIronWeaponCraft->damage = 5;

    ArrayItemCraft *swordDiamondWeaponCraft = malloc(sizeof(ArrayItemCraft));
    swordDiamondWeaponCraft->name = malloc(sizeof(char *));
    swordDiamondWeaponCraft->name = "epee en diamant";
    swordDiamondWeaponCraft->idCreation = DIAMOND_SWORD;
    swordDiamondWeaponCraft->arrayItemCraftNecessary[0] = OAK;
    swordDiamondWeaponCraft->arrayItemCraftNecessary[1] = DIAMOND;
    swordDiamondWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    swordDiamondWeaponCraft->arrayQuantityCraftNecessary[1] = 5;
    swordDiamondWeaponCraft->type = WEAPON;
    swordDiamondWeaponCraft->max_durability = 10;
    swordDiamondWeaponCraft->actual_durabiulity = 10;
    swordDiamondWeaponCraft->damage = 10;


    ArrayItemCraft *spearRockWeaponCraft = malloc(sizeof(ArrayItemCraft));
    spearRockWeaponCraft->name = malloc(sizeof(char *));
    spearRockWeaponCraft->name = "lance en pierre";
    spearRockWeaponCraft->idCreation = STONE_SPEAR;
    spearRockWeaponCraft->arrayItemCraftNecessary[0] = FIR;
    spearRockWeaponCraft->arrayItemCraftNecessary[1] = ROCK;
    spearRockWeaponCraft->arrayQuantityCraftNecessary[0] = 3;
    spearRockWeaponCraft->arrayQuantityCraftNecessary[1] = 4;
    spearRockWeaponCraft->type = WEAPON;
    spearRockWeaponCraft->max_durability = 8;
    spearRockWeaponCraft->actual_durabiulity = 8;
    spearRockWeaponCraft->damage = 3;

    ArrayItemCraft *spearIronWeaponCraft = malloc(sizeof(ArrayItemCraft));
    spearIronWeaponCraft->name = malloc(sizeof(char *));
    spearIronWeaponCraft->name = "lance en fer";
    spearIronWeaponCraft->idCreation = IRON_SPEAR;
    spearIronWeaponCraft->arrayItemCraftNecessary[0] = BEECH;
    spearIronWeaponCraft->arrayItemCraftNecessary[1] = IRON;
    spearIronWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    spearIronWeaponCraft->arrayQuantityCraftNecessary[1] = 5;
    spearIronWeaponCraft->type = WEAPON;
    spearIronWeaponCraft->max_durability = 8;
    spearIronWeaponCraft->actual_durabiulity = 8;
    spearIronWeaponCraft->damage = 7;

    ArrayItemCraft *spearDiamondWeaponCraft = malloc(sizeof(ArrayItemCraft));
    spearDiamondWeaponCraft->name = malloc(sizeof(char *));
    spearDiamondWeaponCraft->name = "lance en diamant";
    spearDiamondWeaponCraft->idCreation = DIAMOND_SPEAR;
    spearDiamondWeaponCraft->arrayItemCraftNecessary[0] = OAK;
    spearDiamondWeaponCraft->arrayItemCraftNecessary[1] = DIAMOND;
    spearDiamondWeaponCraft->arrayQuantityCraftNecessary[0] = 3;
    spearDiamondWeaponCraft->arrayQuantityCraftNecessary[1] = 6;
    spearDiamondWeaponCraft->type = WEAPON;
    spearDiamondWeaponCraft->max_durability = 8;
    spearDiamondWeaponCraft->actual_durabiulity = 8;
    spearDiamondWeaponCraft->damage = 15;

    ArrayItemCraft *hammerRockWeaponCraft = malloc(sizeof(ArrayItemCraft));
    hammerRockWeaponCraft->name = malloc(sizeof(char *));
    hammerRockWeaponCraft->name = "marteau en pierre";
    hammerRockWeaponCraft->idCreation = STONE_HAMMER;
    hammerRockWeaponCraft->arrayItemCraftNecessary[0] = FIR;
    hammerRockWeaponCraft->arrayItemCraftNecessary[1] = ROCK;
    hammerRockWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    hammerRockWeaponCraft->arrayQuantityCraftNecessary[1] = 6;
    hammerRockWeaponCraft->type = WEAPON;
    hammerRockWeaponCraft->max_durability = 5;
    hammerRockWeaponCraft->actual_durabiulity = 5;
    hammerRockWeaponCraft->damage = 4;

    ArrayItemCraft *hammerIronWeaponCraft = malloc(sizeof(ArrayItemCraft));
    hammerIronWeaponCraft->name = malloc(sizeof(char *));
    hammerIronWeaponCraft->name = "marteau en fer";
    hammerIronWeaponCraft->idCreation = IRON_HAMMER;
    hammerIronWeaponCraft->arrayItemCraftNecessary[0] = BEECH;
    hammerIronWeaponCraft->arrayItemCraftNecessary[1] = IRON;
    hammerIronWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    hammerIronWeaponCraft->arrayQuantityCraftNecessary[1] = 7;
    hammerIronWeaponCraft->type = WEAPON;
    hammerIronWeaponCraft->max_durability = 5;
    hammerIronWeaponCraft->actual_durabiulity = 5;
    hammerIronWeaponCraft->damage = 10;

    ArrayItemCraft *hammerDiamondWeaponCraft = malloc(sizeof(ArrayItemCraft));
    hammerDiamondWeaponCraft->name = malloc(sizeof(char *));
    hammerDiamondWeaponCraft->name = "marteau en diamant";
    hammerDiamondWeaponCraft->idCreation = DIAMOND_HAMMER;
    hammerDiamondWeaponCraft->arrayItemCraftNecessary[0] = OAK;
    hammerDiamondWeaponCraft->arrayItemCraftNecessary[1] = DIAMOND;
    hammerDiamondWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    hammerDiamondWeaponCraft->arrayQuantityCraftNecessary[1] = 8;
    hammerDiamondWeaponCraft->type = WEAPON;
    hammerDiamondWeaponCraft->max_durability = 5;
    hammerDiamondWeaponCraft->actual_durabiulity = 5;
    hammerDiamondWeaponCraft->damage = 20;

    ArrayItemCraft *chestplateRockCraft = malloc(sizeof(ArrayItemCraft));
    chestplateRockCraft->name = malloc(sizeof(char *));
    chestplateRockCraft->name = "armure en pierre";
    chestplateRockCraft->idCreation = 11;
    chestplateRockCraft->arrayItemCraftNecessary[0] = ROCK;
    chestplateRockCraft->arrayItemCraftNecessary[1] = -1;
    chestplateRockCraft->arrayQuantityCraftNecessary[0] = 10;
    chestplateRockCraft->arrayQuantityCraftNecessary[1] = -1;
    chestplateRockCraft->type = ARMOR;
    chestplateRockCraft->protection = 10;

    ArrayItemCraft *chestplateIronCraft = malloc(sizeof(ArrayItemCraft));
    chestplateIronCraft->name = malloc(sizeof(char *));
    chestplateIronCraft->name = "armure en fer";
    chestplateIronCraft->idCreation = 22;
    chestplateIronCraft->arrayItemCraftNecessary[0] = IRON;
    chestplateIronCraft->arrayItemCraftNecessary[1] = -1;
    chestplateIronCraft->arrayQuantityCraftNecessary[0] = 12;
    chestplateIronCraft->arrayQuantityCraftNecessary[1] = -1;
    chestplateIronCraft->type = ARMOR;
    chestplateIronCraft->protection = 20;

    ArrayItemCraft *chestplateDiamondCraft = malloc(sizeof(ArrayItemCraft));
    chestplateDiamondCraft->name = malloc(sizeof(char *));
    chestplateDiamondCraft->name = "armure en diamant";
    chestplateDiamondCraft->idCreation = 33;
    chestplateDiamondCraft->arrayItemCraftNecessary[0] = DIAMOND;
    chestplateDiamondCraft->arrayItemCraftNecessary[1] = -1;
    chestplateDiamondCraft->arrayQuantityCraftNecessary[0] = 16;
    chestplateDiamondCraft->arrayQuantityCraftNecessary[1] = -1;
    chestplateDiamondCraft->type = ARMOR;
    chestplateDiamondCraft->protection = 40;

    ArrayItemCraft *pickaxeWoodToolsCraft = malloc(sizeof(ArrayItemCraft));
    pickaxeWoodToolsCraft->name = malloc(sizeof(char *));
    pickaxeWoodToolsCraft->name = "pioche en bois";
    pickaxeWoodToolsCraft->idCreation = WOODEN_PICKAXE;
    pickaxeWoodToolsCraft->arrayItemCraftNecessary[0] = FIR;
    pickaxeWoodToolsCraft->arrayItemCraftNecessary[1] = -1;
    pickaxeWoodToolsCraft->arrayQuantityCraftNecessary[0] = 3;
    pickaxeWoodToolsCraft->arrayQuantityCraftNecessary[1] = -1;
    pickaxeWoodToolsCraft->type = TOOL;
    pickaxeWoodToolsCraft->max_durability = 10;
    pickaxeWoodToolsCraft->actual_durabiulity = 10;

    ArrayItemCraft *pickaxeStoneToolsCraft = malloc(sizeof(ArrayItemCraft));
    pickaxeStoneToolsCraft->name = malloc(sizeof(char *));
    pickaxeStoneToolsCraft->name = "pioche en pierre";
    pickaxeStoneToolsCraft->idCreation = STONE_PICKAXE;
    pickaxeStoneToolsCraft->arrayItemCraftNecessary[0] = FIR;
    pickaxeStoneToolsCraft->arrayItemCraftNecessary[1] = ROCK;
    pickaxeStoneToolsCraft->arrayQuantityCraftNecessary[0] = 2;
    pickaxeStoneToolsCraft->arrayQuantityCraftNecessary[1] = 3;
    pickaxeStoneToolsCraft->type = TOOL;
    pickaxeStoneToolsCraft->max_durability = 10;
    pickaxeStoneToolsCraft->actual_durabiulity = 10;

    ArrayItemCraft *pickaxeIronToolsCraft = malloc(sizeof(ArrayItemCraft));
    pickaxeIronToolsCraft->name = malloc(sizeof(char *));
    pickaxeIronToolsCraft->name = "pioche en fer";
    pickaxeIronToolsCraft->idCreation = IRON_PICKAXE;
    pickaxeIronToolsCraft->arrayItemCraftNecessary[0] = BEECH;
    pickaxeIronToolsCraft->arrayItemCraftNecessary[1] = IRON;
    pickaxeIronToolsCraft->arrayQuantityCraftNecessary[0] = 2;
    pickaxeIronToolsCraft->arrayQuantityCraftNecessary[1] = 4;
    pickaxeIronToolsCraft->type = TOOL;
    pickaxeIronToolsCraft->max_durability = 10;
    pickaxeIronToolsCraft->actual_durabiulity = 10;

    ArrayItemCraft *axWoodToolsCraft = malloc(sizeof(ArrayItemCraft));
    axWoodToolsCraft->name = malloc(sizeof(char *));
    axWoodToolsCraft->name = "hache en bois";
    axWoodToolsCraft->idCreation = WOODEN_AX;
    axWoodToolsCraft->arrayItemCraftNecessary[0] = FIR;
    axWoodToolsCraft->arrayItemCraftNecessary[1] = -1;
    axWoodToolsCraft->arrayQuantityCraftNecessary[0] = 3;
    axWoodToolsCraft->arrayQuantityCraftNecessary[1] = -1;
    axWoodToolsCraft->type = TOOL;
    axWoodToolsCraft->max_durability = 10;
    axWoodToolsCraft->actual_durabiulity = 10;

    ArrayItemCraft *axStoneToolsCraft = malloc(sizeof(ArrayItemCraft));
    axStoneToolsCraft->name = malloc(sizeof(char *));
    axStoneToolsCraft->name = "hache en pierre";
    axStoneToolsCraft->idCreation = STONE_AX;
    axStoneToolsCraft->arrayItemCraftNecessary[0] = FIR;
    axStoneToolsCraft->arrayItemCraftNecessary[1] = ROCK;
    axStoneToolsCraft->arrayQuantityCraftNecessary[0] = 2;
    axStoneToolsCraft->arrayQuantityCraftNecessary[1] = 3;
    axStoneToolsCraft->type = TOOL;
    axStoneToolsCraft->max_durability = 10;
    axStoneToolsCraft->actual_durabiulity = 10;

    ArrayItemCraft *axIronToolsCraft = malloc(sizeof(ArrayItemCraft));
    axIronToolsCraft->name = malloc(sizeof(char *));
    axIronToolsCraft->name = "hache en fer";
    axIronToolsCraft->idCreation = IRON_AX;
    axIronToolsCraft->arrayItemCraftNecessary[0] = BEECH;
    axIronToolsCraft->arrayItemCraftNecessary[1] = IRON;
    axIronToolsCraft->arrayQuantityCraftNecessary[0] = 2;
    axIronToolsCraft->arrayQuantityCraftNecessary[1] = 4;
    axIronToolsCraft->type = TOOL;
    axIronToolsCraft->max_durability = 10;
    axIronToolsCraft->actual_durabiulity = 10;

    ArrayItemCraft *billhookWoodToolsCraft = malloc(sizeof(ArrayItemCraft));
    billhookWoodToolsCraft->name = malloc(sizeof(char *));
    billhookWoodToolsCraft->name = "serpe en bois";
    billhookWoodToolsCraft->idCreation = WOODEN_BILLHOOK;
    billhookWoodToolsCraft->arrayItemCraftNecessary[0] = FIR;
    billhookWoodToolsCraft->arrayItemCraftNecessary[1] = -1;
    billhookWoodToolsCraft->arrayQuantityCraftNecessary[0] = 3;
    billhookWoodToolsCraft->arrayQuantityCraftNecessary[1] = -1;
    billhookWoodToolsCraft->type = TOOL;
    billhookWoodToolsCraft->max_durability = 10;
    billhookWoodToolsCraft->actual_durabiulity = 10;

    ArrayItemCraft *billhookStoneToolsCraft = malloc(sizeof(ArrayItemCraft));
    billhookStoneToolsCraft->name = malloc(sizeof(char *));
    billhookStoneToolsCraft->name = "serpe en pierre";
    billhookStoneToolsCraft->idCreation = STONE_BILLHOOK;
    billhookStoneToolsCraft->arrayItemCraftNecessary[0] = FIR;
    billhookStoneToolsCraft->arrayItemCraftNecessary[1] = ROCK;
    billhookStoneToolsCraft->arrayQuantityCraftNecessary[0] = 2;
    billhookStoneToolsCraft->arrayQuantityCraftNecessary[1] = 3;
    billhookStoneToolsCraft->type = TOOL;
    billhookStoneToolsCraft->max_durability = 10;
    billhookStoneToolsCraft->actual_durabiulity = 10;

    ArrayItemCraft *billhookIronToolsCraft = malloc(sizeof(ArrayItemCraft));
    billhookIronToolsCraft->name = malloc(sizeof(char *));
    billhookIronToolsCraft->name = "serpe en fer";
    billhookIronToolsCraft->idCreation = IRON_AX;
    billhookIronToolsCraft->arrayItemCraftNecessary[0] = BEECH;
    billhookIronToolsCraft->arrayItemCraftNecessary[1] = IRON;
    billhookIronToolsCraft->arrayQuantityCraftNecessary[0] = 2;
    billhookIronToolsCraft->arrayQuantityCraftNecessary[1] = 4;
    billhookIronToolsCraft->type = TOOL;
    billhookIronToolsCraft->max_durability = 10;
    billhookIronToolsCraft->actual_durabiulity = 10;

    ArrayItemCraft *healOne = malloc(sizeof(ArrayItemCraft));
    healOne->name = malloc(sizeof(char *));
    healOne->name = "potion 1";
    healOne->idCreation = 15;
    healOne->arrayItemCraftNecessary[0] = GRASS;
    healOne->arrayItemCraftNecessary[1] = -1;
    healOne->arrayQuantityCraftNecessary[0] = 2;
    healOne->arrayQuantityCraftNecessary[1] = -1;
    healOne->type = HEAL;
    healOne->pvRestore = 30;
    healOne->quantity = 1;


    ArrayItemCraft *healTwo = malloc(sizeof(ArrayItemCraft));
    healTwo->name = malloc(sizeof(char *));
    healTwo->name = "potion 2";
    healTwo->idCreation = 26;
    healTwo->arrayItemCraftNecessary[0] = LAVANDER;
    healTwo->arrayItemCraftNecessary[1] = -1;
    healTwo->arrayQuantityCraftNecessary[0] = 2;
    healTwo->arrayQuantityCraftNecessary[1] = -1;
    healTwo->type = HEAL;
    healTwo->pvRestore = 80;
    healTwo->quantity = 1;

    ArrayItemCraft *healThree = malloc(sizeof(ArrayItemCraft));
    healThree->name = malloc(sizeof(char *));
    healThree->name = "potion 3";
    healThree->idCreation = 34;
    healThree->arrayItemCraftNecessary[0] = HEMP;
    healThree->arrayItemCraftNecessary[1] = -1;
    healThree->arrayQuantityCraftNecessary[0] = 2;
    healThree->arrayQuantityCraftNecessary[1] = -1;
    healThree->type = HEAL;
    healThree->pvRestore = 200;
    healThree->quantity = 1;

    allItemCraft->itemCraft[0] = *swordWoodWeaponCraft;
    allItemCraft->itemCraft[1] = *swordRockWeaponCraft;
    allItemCraft->itemCraft[2] = *swordIronWeaponCraft;
    allItemCraft->itemCraft[3] = *swordDiamondWeaponCraft;
    allItemCraft->itemCraft[4] = *spearRockWeaponCraft;
    allItemCraft->itemCraft[5] = *spearIronWeaponCraft;
    allItemCraft->itemCraft[6] = *spearDiamondWeaponCraft;
    allItemCraft->itemCraft[7] = *hammerRockWeaponCraft;
    allItemCraft->itemCraft[8] = *hammerIronWeaponCraft;
    allItemCraft->itemCraft[9] = *hammerDiamondWeaponCraft;
    allItemCraft->itemCraft[10] = *chestplateRockCraft;
    allItemCraft->itemCraft[11] = *chestplateIronCraft;
    allItemCraft->itemCraft[12] = *chestplateDiamondCraft;
    allItemCraft->itemCraft[13] = *pickaxeWoodToolsCraft;
    allItemCraft->itemCraft[14] = *pickaxeStoneToolsCraft;
    allItemCraft->itemCraft[15] = *pickaxeIronToolsCraft;
    allItemCraft->itemCraft[16] = *axWoodToolsCraft;
    allItemCraft->itemCraft[17] = *axStoneToolsCraft;
    allItemCraft->itemCraft[18] = *axIronToolsCraft;
    allItemCraft->itemCraft[19] = *billhookWoodToolsCraft;
    allItemCraft->itemCraft[20] = *billhookStoneToolsCraft;
    allItemCraft->itemCraft[21] = *billhookIronToolsCraft;
    allItemCraft->itemCraft[22] = *healOne;
    allItemCraft->itemCraft[23] = *healTwo;
    allItemCraft->itemCraft[24] = *healThree;
}

