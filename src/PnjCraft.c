#include "../include/include.h"
#include "../include/pnjService.h"

void verifItemCraft(AllItemCraft *pCraft, Player *pPlayer);

void craftItem(Player *playerStruct) {
    //init tab craft
    AllItemCraft  allItemCraft;
    initArrayCraftItem(&allItemCraft);
    verifItemCraft(&allItemCraft, playerStruct);

}

void verifItemCraft(AllItemCraft *allItemCraft, Player *playerStruct) {
    if (countDelet < sizeof(playerStruct->inventory[0].tools.id)) {

        for (int i = 0; i < sizeof(playerStruct->inventory[i].type); i++) {
            for (int j = 0; j <25; j++) {
                if (playerStruct->inventory[i].resource.id == allItemCraft->itemCraft[j].idCreation) {
                    printf("\nVous avez du %d !\n",playerStruct->inventory[i].resource.id);
                }
            }
        }
    } else {
        printf("\nVous n'avez plus d'item dans votre inventaire !\n");
    }
}

void initArrayCraftItem(AllItemCraft *allItemCraft) {
    ArrayItemCraft *swordWoodWeaponCraft = malloc(sizeof(ArrayItemCraft));
    swordWoodWeaponCraft->idCreation = WOODEN_SWORD;
    swordWoodWeaponCraft->arrayItemCraftNecessary[0] = FIR;
    swordWoodWeaponCraft->arrayItemCraftNecessary[1] = -1;
    swordWoodWeaponCraft->arrayQuantityCraftNecessary[0] = 3;
    swordWoodWeaponCraft->arrayQuantityCraftNecessary[1] = -1;

    ArrayItemCraft *swordRockWeaponCraft = malloc(sizeof(ArrayItemCraft));
    swordRockWeaponCraft->idCreation = STONE_SWORD;
    swordRockWeaponCraft->arrayItemCraftNecessary[0] = FIR;
    swordRockWeaponCraft->arrayItemCraftNecessary[1] = ROCK;
    swordRockWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    swordRockWeaponCraft->arrayQuantityCraftNecessary[1] = 3;

    ArrayItemCraft *swordIronWeaponCraft = malloc(sizeof(ArrayItemCraft));
    swordIronWeaponCraft->idCreation = IRON_SWORD;
    swordIronWeaponCraft->arrayItemCraftNecessary[0] = BEECH;
    swordIronWeaponCraft->arrayItemCraftNecessary[1] = IRON;
    swordIronWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    swordIronWeaponCraft->arrayQuantityCraftNecessary[1] = 4;

    ArrayItemCraft *swordDiamondWeaponCraft = malloc(sizeof(ArrayItemCraft));
    swordDiamondWeaponCraft->idCreation = DIAMOND_SWORD;
    swordDiamondWeaponCraft->arrayItemCraftNecessary[0] = OAK;
    swordDiamondWeaponCraft->arrayItemCraftNecessary[1] = DIAMOND;
    swordDiamondWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    swordDiamondWeaponCraft->arrayQuantityCraftNecessary[1] = 5;

    ArrayItemCraft *spearRockWeaponCraft = malloc(sizeof(ArrayItemCraft));
    spearRockWeaponCraft->idCreation = STONE_SPEAR;
    spearRockWeaponCraft->arrayItemCraftNecessary[0] = FIR;
    spearRockWeaponCraft->arrayItemCraftNecessary[1] = ROCK;
    spearRockWeaponCraft->arrayQuantityCraftNecessary[0] = 3;
    spearRockWeaponCraft->arrayQuantityCraftNecessary[1] = 4;

    ArrayItemCraft *spearIronWeaponCraft = malloc(sizeof(ArrayItemCraft));
    spearIronWeaponCraft->idCreation = IRON_SPEAR;
    spearIronWeaponCraft->arrayItemCraftNecessary[0] = BEECH;
    spearIronWeaponCraft->arrayItemCraftNecessary[1] = IRON;
    spearIronWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    spearIronWeaponCraft->arrayQuantityCraftNecessary[1] = 5;

    ArrayItemCraft *spearDiamondWeaponCraft = malloc(sizeof(ArrayItemCraft));
    spearDiamondWeaponCraft->idCreation = DIAMOND_SPEAR;
    spearDiamondWeaponCraft->arrayItemCraftNecessary[0] = OAK;
    spearDiamondWeaponCraft->arrayItemCraftNecessary[1] = DIAMOND;
    spearDiamondWeaponCraft->arrayQuantityCraftNecessary[0] = 3;
    spearDiamondWeaponCraft->arrayQuantityCraftNecessary[1] = 6;

    ArrayItemCraft *hammerRockWeaponCraft = malloc(sizeof(ArrayItemCraft));
    hammerRockWeaponCraft->idCreation = STONE_HAMMER;
    hammerRockWeaponCraft->arrayItemCraftNecessary[0] = FIR;
    hammerRockWeaponCraft->arrayItemCraftNecessary[1] = ROCK;
    hammerRockWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    hammerRockWeaponCraft->arrayQuantityCraftNecessary[1] = 6;

    ArrayItemCraft *hammerIronWeaponCraft = malloc(sizeof(ArrayItemCraft));
    hammerIronWeaponCraft->idCreation = IRON_HAMMER;
    hammerIronWeaponCraft->arrayItemCraftNecessary[0] = BEECH;
    hammerIronWeaponCraft->arrayItemCraftNecessary[1] = IRON;
    hammerIronWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    hammerIronWeaponCraft->arrayQuantityCraftNecessary[1] = 7;

    ArrayItemCraft *hammerDiamondWeaponCraft = malloc(sizeof(ArrayItemCraft));
    hammerDiamondWeaponCraft->idCreation = DIAMOND_HAMMER;
    hammerDiamondWeaponCraft->arrayItemCraftNecessary[0] = OAK;
    hammerDiamondWeaponCraft->arrayItemCraftNecessary[1] = DIAMOND;
    hammerDiamondWeaponCraft->arrayQuantityCraftNecessary[0] = 2;
    hammerDiamondWeaponCraft->arrayQuantityCraftNecessary[1] = 8;

    ArrayItemCraft *chestplateRockCraft = malloc(sizeof(ArrayItemCraft));
    chestplateRockCraft->idCreation = 11;
    chestplateRockCraft->arrayItemCraftNecessary[0] = ROCK;
    chestplateRockCraft->arrayItemCraftNecessary[1] = -1;
    chestplateRockCraft->arrayQuantityCraftNecessary[0] = 10;
    chestplateRockCraft->arrayQuantityCraftNecessary[1] = -1;

    ArrayItemCraft *chestplateIronCraft = malloc(sizeof(ArrayItemCraft));
    chestplateIronCraft->idCreation = 11;
    chestplateIronCraft->arrayItemCraftNecessary[0] = IRON;
    chestplateIronCraft->arrayItemCraftNecessary[1] = -1;
    chestplateIronCraft->arrayQuantityCraftNecessary[0] = 12;
    chestplateIronCraft->arrayQuantityCraftNecessary[1] = -1;

    ArrayItemCraft *chestplateDiamondCraft = malloc(sizeof(ArrayItemCraft));
    chestplateDiamondCraft->idCreation = 11;
    chestplateDiamondCraft->arrayItemCraftNecessary[0] = DIAMOND;
    chestplateDiamondCraft->arrayItemCraftNecessary[1] = -1;
    chestplateDiamondCraft->arrayQuantityCraftNecessary[0] = 16;
    chestplateDiamondCraft->arrayQuantityCraftNecessary[1] = -1;

    ArrayItemCraft *pickaxeWoodToolsCraft = malloc(sizeof(ArrayItemCraft));
    pickaxeWoodToolsCraft->idCreation = WOODEN_PICKAXE;
    pickaxeWoodToolsCraft->arrayItemCraftNecessary[0] = FIR;
    pickaxeWoodToolsCraft->arrayItemCraftNecessary[1] = -1;
    pickaxeWoodToolsCraft->arrayQuantityCraftNecessary[0] = 3;
    pickaxeWoodToolsCraft->arrayQuantityCraftNecessary[1] = -1;

    ArrayItemCraft *pickaxeStoneToolsCraft = malloc(sizeof(ArrayItemCraft));
    pickaxeStoneToolsCraft->idCreation = STONE_PICKAXE;
    pickaxeStoneToolsCraft->arrayItemCraftNecessary[0] = FIR;
    pickaxeStoneToolsCraft->arrayItemCraftNecessary[1] = ROCK;
    pickaxeStoneToolsCraft->arrayQuantityCraftNecessary[0] = 2;
    pickaxeStoneToolsCraft->arrayQuantityCraftNecessary[1] = 3;

    ArrayItemCraft *pickaxeIronToolsCraft = malloc(sizeof(ArrayItemCraft));
    pickaxeIronToolsCraft->idCreation = IRON_PICKAXE;
    pickaxeIronToolsCraft->arrayItemCraftNecessary[0] = BEECH;
    pickaxeIronToolsCraft->arrayItemCraftNecessary[1] = IRON;
    pickaxeIronToolsCraft->arrayQuantityCraftNecessary[0] = 2;
    pickaxeIronToolsCraft->arrayQuantityCraftNecessary[1] = 4;

    ArrayItemCraft *axWoodToolsCraft = malloc(sizeof(ArrayItemCraft));
    axWoodToolsCraft->idCreation = WOODEN_AX;
    axWoodToolsCraft->arrayItemCraftNecessary[0] = FIR;
    axWoodToolsCraft->arrayItemCraftNecessary[1] = -1;
    axWoodToolsCraft->arrayQuantityCraftNecessary[0] = 3;
    axWoodToolsCraft->arrayQuantityCraftNecessary[1] = -1;

    ArrayItemCraft *axStoneToolsCraft = malloc(sizeof(ArrayItemCraft));
    axStoneToolsCraft->idCreation = STONE_AX;
    axStoneToolsCraft->arrayItemCraftNecessary[0] = FIR;
    axStoneToolsCraft->arrayItemCraftNecessary[1] = ROCK;
    axStoneToolsCraft->arrayQuantityCraftNecessary[0] = 2;
    axStoneToolsCraft->arrayQuantityCraftNecessary[1] = 3;

    ArrayItemCraft *axIronToolsCraft = malloc(sizeof(ArrayItemCraft));
    axIronToolsCraft->idCreation = IRON_AX;
    axIronToolsCraft->arrayItemCraftNecessary[0] = BEECH;
    axIronToolsCraft->arrayItemCraftNecessary[1] = IRON;
    axIronToolsCraft->arrayQuantityCraftNecessary[0] = 2;
    axIronToolsCraft->arrayQuantityCraftNecessary[1] = 4;

    ArrayItemCraft *billhookWoodToolsCraft = malloc(sizeof(ArrayItemCraft));
    billhookWoodToolsCraft->idCreation = WOODEN_BILLHOOK;
    billhookWoodToolsCraft->arrayItemCraftNecessary[0] = FIR;
    billhookWoodToolsCraft->arrayItemCraftNecessary[1] = -1;
    billhookWoodToolsCraft->arrayQuantityCraftNecessary[0] = 3;
    billhookWoodToolsCraft->arrayQuantityCraftNecessary[1] = -1;

    ArrayItemCraft *billhookStoneToolsCraft = malloc(sizeof(ArrayItemCraft));
    billhookStoneToolsCraft->idCreation = STONE_BILLHOOK;
    billhookStoneToolsCraft->arrayItemCraftNecessary[0] = FIR;
    billhookStoneToolsCraft->arrayItemCraftNecessary[1] = ROCK;
    billhookStoneToolsCraft->arrayQuantityCraftNecessary[0] = 2;
    billhookStoneToolsCraft->arrayQuantityCraftNecessary[1] = 3;

    ArrayItemCraft *billhookIronToolsCraft = malloc(sizeof(ArrayItemCraft));
    billhookIronToolsCraft->idCreation = IRON_AX;
    billhookIronToolsCraft->arrayItemCraftNecessary[0] = BEECH;
    billhookIronToolsCraft->arrayItemCraftNecessary[1] = IRON;
    billhookIronToolsCraft->arrayQuantityCraftNecessary[0] = 2;
    billhookIronToolsCraft->arrayQuantityCraftNecessary[1] = 4;

    ArrayItemCraft *healOne = malloc(sizeof(ArrayItemCraft));
    healOne->idCreation = 15;
    healOne->arrayItemCraftNecessary[0] = GRASS;
    healOne->arrayItemCraftNecessary[1] = -1;
    healOne->arrayQuantityCraftNecessary[0] = 2;
    healOne->arrayQuantityCraftNecessary[1] = -1;

    ArrayItemCraft *healTwo = malloc(sizeof(ArrayItemCraft));
    healTwo->idCreation = 26;
    healTwo->arrayItemCraftNecessary[0] = LAVANDER;
    healTwo->arrayItemCraftNecessary[1] = -1;
    healTwo->arrayQuantityCraftNecessary[0] = 2;
    healTwo->arrayQuantityCraftNecessary[1] = -1;

    ArrayItemCraft *healThree = malloc(sizeof(ArrayItemCraft));
    healThree->idCreation = 34;
    healThree->arrayItemCraftNecessary[0] = HEMP;
    healThree->arrayItemCraftNecessary[1] = -1;
    healThree->arrayQuantityCraftNecessary[0] = 2;
    healThree->arrayQuantityCraftNecessary[1] = -1;

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