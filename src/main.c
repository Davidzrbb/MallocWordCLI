#include "../include/collectRessource.h";

int main(int argc, const char *argv[]) {
    Player PlayerStruct;
    AllObjectInventory AllObjectInventoryStruct;
    //Stat du Player au début de la partie
    InitPlayer(&PlayerStruct);
    //printInventaire
    MovePlayer(PlayerStruct);
    return 0;
}

void InitPlayer(Player* firstPlayer) {

    AllObjectInventory *WeaponSword = malloc(sizeof(Weapon));
    WeaponSword->weapon.name = "sword";
    WeaponSword->weapon.damage= 1;
    WeaponSword->weapon.max_durability = 10;
    WeaponSword->weapon.actual_durabiulity  = 10;
    WeaponSword->weapon.id = 1;

    AllObjectInventory *ToolsPickaxe = malloc(sizeof(Tools));
    ToolsPickaxe->tools.name ="pickaxe";
    ToolsPickaxe->tools.id = WOODEN_PICKAXE;
    ToolsPickaxe->tools.max_durability=10;
    ToolsPickaxe->tools.actual_durabiulity=10;

    AllObjectInventory  *ToolsBillhook = malloc(sizeof(Tools));
    ToolsBillhook->tools.name ="billhook";
    ToolsBillhook->tools.id = WOODEN_BILLHOOK;
    ToolsBillhook->tools.max_durability=10;
    ToolsBillhook->tools.actual_durabiulity=0;

    AllObjectInventory *ToolsAx = malloc(sizeof(Tools));
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

void MovePlayer(Player PlayerStruct) {
    int nextBox = 3;
   // printf("Votre arme %d",PlayerStruct.inventory[0].weapon.id);
    //CollecteRessources
    CollecteRessources(&PlayerStruct, nextBox);
}


