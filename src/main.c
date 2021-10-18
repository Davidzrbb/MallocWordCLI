#include "../include/include.h";

#include <string.h>

int main(int argc, const char *argv[]) {
    Player PlayerStruct;
    AllObjectInventory AllObjectInventoryStruct;
    //Stat du Player au début de la partie
    InitPlayer(&PlayerStruct);
//Print
    printTest(PlayerStruct);
    return 0;
}

void InitPlayer(Player* firstPlayer) {

    AllObjectInventory *WeaponSword = malloc(sizeof(AllObjectInventory));
    WeaponSword->weapon.name = "sword";
    WeaponSword->weapon.damage= 1;
    WeaponSword->weapon.max_durability = 10;
    WeaponSword->weapon.actual_durabiulity  = 10;
    WeaponSword->weapon.id = 1;

    AllObjectInventory *ToolsPickaxe = malloc(sizeof(AllObjectInventory));
    ToolsPickaxe->tools.name ="pickaxe";
    ToolsPickaxe->tools.id = WOODEN_PICKAXE;
    ToolsPickaxe->tools.max_durability=10;
    ToolsPickaxe->tools.actual_durabiulity=10;

    AllObjectInventory  *ToolsBillhook = malloc(sizeof(AllObjectInventory));
    ToolsBillhook->tools.name ="billhook";
    ToolsBillhook->tools.id = WOODEN_BILLHOOK;
    ToolsBillhook->tools.max_durability=10;
    ToolsBillhook->tools.actual_durabiulity=0;

    AllObjectInventory *ToolsAx = malloc(sizeof(AllObjectInventory));
    ToolsAx->tools.name ="ax";
    ToolsAx->tools.id = WOODEN_AX;
    ToolsAx->tools.max_durability=10;
    ToolsAx->tools.actual_durabiulity=10;

    firstPlayer->level = 1;
    firstPlayer->currentHealthPoints = 100;
    firstPlayer->maxHealthpoints = 100;
    firstPlayer->inventory[0] = *WeaponSword ;
    firstPlayer->inventory[1] = *ToolsPickaxe ;
    firstPlayer->inventory[2] = *ToolsBillhook ;
    firstPlayer->inventory[3] = *ToolsAx ;
}

void printTest(Player PlayerStruct){
    printf("Votre arme : %s \n c'est dommage : %d",PlayerStruct.inventory[0].weapon.name,PlayerStruct.inventory[0].weapon.damage);
}