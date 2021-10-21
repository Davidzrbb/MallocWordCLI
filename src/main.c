#include "../include/collectRessource.h"

int main(int argc, const char *argv[]) {
    Player PlayerStruct;
    Item ItemStruct;
    //Stat du Player au début de la partie
    InitPlayer(&PlayerStruct);
    //printInventaire
    MovePlayer(PlayerStruct);
    return 0;
}

void InitPlayer(Player* firstPlayer) {

    Item *WeaponSword = malloc(sizeof(Item));
    WeaponSword->weapon.name = "sword";
    WeaponSword->weapon.damage= 1;
    WeaponSword->weapon.max_durability = 10;
    WeaponSword->weapon.actual_durabiulity  = 10;
    WeaponSword->weapon.id = 1;
    WeaponSword->type=1;

    Item *ToolsPickaxe = malloc(sizeof(Item));
    ToolsPickaxe->tools.name ="pickaxe";
    ToolsPickaxe->tools.id = WOODEN_PICKAXE;
    ToolsPickaxe->tools.max_durability=10;
    ToolsPickaxe->tools.actual_durabiulity=10;

    Item  *ToolsBillhook = malloc(sizeof(Item ));
    ToolsBillhook->tools.name ="billhook";
    ToolsBillhook->tools.id = WOODEN_BILLHOOK;
    ToolsBillhook->tools.max_durability=10;
    ToolsBillhook->tools.actual_durabiulity=10;

    Item *ToolsAx = malloc(sizeof(Item ));
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


