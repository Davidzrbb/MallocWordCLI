//
//  main.c
//  ESGIPROJET
//
//  Created by Marwan Khalil on 18/10/2021.
//
#include "include.h"

int main(int argc, const char *argv[]) {
    Player PlayerStruct;
    //Stat du Player au début de la partie
    InitPlayer(&PlayerStruct);
    AllMonster allMonster;
    initMonster(&allMonster);
    //Print
//    printMonster(allMonster);
//    printf("\n LIFE : %d \n PV : %d \n", allMonster.allMonster[2].currentLife , PlayerStruct.currentHealthPoints);
//    addLevel(&PlayerStruct);
//    attackPlayer(&PlayerStruct, &allMonster.allMonster[2]);
//    printf("\n LIFE : %d \n PV : %d \n", allMonster.allMonster[2].currentLife , PlayerStruct.currentHealthPoints);
//    return 0;
    
    combat(&PlayerStruct,&allMonster.allMonster[2]);
}

void printMonster(AllMonster m){
    for(int i=0; i<3; i++){
        printf("\n voici nos monstres :  %s \n",m.allMonster[i].name);
    }
}

void InitPlayer(Player* firstPlayer) {
    Item *WeaponSword = malloc(sizeof(Item));
    WeaponSword->weapon.name ="Iron sword";
    WeaponSword->weapon.damage= 1;
    WeaponSword->weapon.max_durability = 10;
    WeaponSword->weapon.actual_durabiulity  = 10;
    WeaponSword->weapon.id = WOODEN_SWORD;
    WeaponSword->type = WEAPON;
    
    Item *DiamondSword = malloc(sizeof(Item));
    DiamondSword->weapon.name ="Diamondsword";
    DiamondSword->weapon.damage= 1;
    DiamondSword->weapon.max_durability = 10;
    DiamondSword->weapon.actual_durabiulity  = 10;
    DiamondSword->weapon.id = DIAMOND_SWORD;
    DiamondSword->type = WEAPON;

    Item *ToolsPickaxe = malloc(sizeof(Item));
    ToolsPickaxe->tools.name ="pickaxe";
    ToolsPickaxe->tools.max_durability=10;
    ToolsPickaxe->tools.actual_durabiulity=10;
    ToolsPickaxe->tools.id= WOODEN_PICKAXE;
    ToolsPickaxe->type= TOOL;

    Item  *ToolsBillhook = malloc(sizeof(Item));
    ToolsBillhook->tools.name ="billhook";
    ToolsBillhook->tools.max_durability=10;
    ToolsBillhook->tools.actual_durabiulity=10;
    ToolsBillhook->tools.id= WOODEN_BILLHOOK;
    ToolsBillhook->type= TOOL;


    Item *ToolsAx = malloc(sizeof(Item));
    ToolsAx->tools.name ="ax";
    ToolsAx->tools.max_durability=10;
    ToolsAx->tools.actual_durabiulity=10;
    ToolsAx->tools.id = WOODEN_AX;
    ToolsAx->type= TOOL;
    
    Item *hp1 = malloc(sizeof(Item));
    hp1 -> healhPotion.name = "hp1";
    hp1 -> healhPotion.quantity = 1;
    hp1 -> healhPotion.pvRestore = 30;
    hp1 -> healhPotion.id = 1;
    
    Item *armor1 = malloc(sizeof(Item));
    armor1 -> armor.name = "chestplate11";
    armor1 -> armor.id = 11;
    armor1 -> armor.protection = 10;

    firstPlayer->level = 1;
    firstPlayer->currentHealthPoints = 40;
    firstPlayer->maxHealthpoints = 100;
    firstPlayer->inventory[0] = *WeaponSword ;
    firstPlayer->inventory[1] = *ToolsPickaxe ;
    firstPlayer->inventory[2] = *ToolsBillhook ;
    firstPlayer->inventory[3] = *ToolsAx ;
    firstPlayer->inventory[4] = *DiamondSword;
    firstPlayer->inventory[5] = *hp1;
    firstPlayer->inventory[6] = *armor1;
}


void printTest(Player PlayerStruct){
    printf("Votre arme : %s \n c'est dommage : %d",PlayerStruct.inventory[0].weapon.name,PlayerStruct.inventory[0].weapon.damage);
}
