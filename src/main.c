#include "../include/include.h";

int main(int argc, const char *argv[]) {
    Player PlayerStruct;
    Item ItemStruct;
    //Stat du Player au début de la partie
    InitPlayer(&PlayerStruct);
    //PnjFix
    pnjChoice(&PlayerStruct);
//Print
//    printTest(PlayerStruct);
    return 0;
}

void InitPlayer(Player* firstPlayer) {

    Item *WeaponSword = malloc(sizeof(Item));
    WeaponSword->weapon.name = "sword";
    WeaponSword->weapon.damage= 1;
    WeaponSword->weapon.max_durability = 10;
    WeaponSword->weapon.actual_durabiulity  = 10;
    WeaponSword->type = WOODEN_SWORD;

    Item *ToolsPickaxe = malloc(sizeof(Item));
    ToolsPickaxe->tools.name ="pickaxe";
    ToolsPickaxe->tools.max_durability=10;
    ToolsPickaxe->tools.actual_durabiulity=10;
    ToolsPickaxe->type = WOODEN_PICKAXE;

    Item  *ToolsBillhook = malloc(sizeof(Item));
    ToolsBillhook->tools.name ="billhook";
    ToolsBillhook->tools.max_durability=10;
    ToolsBillhook->tools.actual_durabiulity=0;
    ToolsBillhook->type= WOODEN_BILLHOOK;


    Item *ToolsAx = malloc(sizeof(Item));
    ToolsAx->tools.name ="ax";
    ToolsAx->tools.max_durability=10;
    ToolsAx->tools.actual_durabiulity=10;
    ToolsAx->type = WOODEN_AX;


    firstPlayer->level = 1;
    firstPlayer->currentHealthPoints = 100;
    firstPlayer->maxHealthpoints = 100;
    firstPlayer->inventory[0] = *WeaponSword ;
    firstPlayer->inventory[1] = *ToolsPickaxe ;
    firstPlayer->inventory[2] = *ToolsBillhook ;
    firstPlayer->inventory[3] = *ToolsAx ;
}

void printTest(Player PlayerStruct){
    for (int i = 0; i<sizeof(PlayerStruct.inventory[i].type);i++){
            printf("Vos item %d", PlayerStruct.inventory[i].type);
        }

}