#include "../include/include.h";

int main(int argc, const char *argv[]) {
    Player PlayerStruct;
    Item ItemStruct;
    //Stat du Player au début de la partie
    InitPlayer(&PlayerStruct);
    //PnjFix
    pnjChoice(&PlayerStruct);
//Print
    printTest(PlayerStruct);
    return 0;
}

void InitPlayer(Player* firstPlayer) {
    Item *WeaponSword = malloc(sizeof(Item));
    WeaponSword->weapon.damage= 1;
    WeaponSword->weapon.name ="sword";
    WeaponSword->weapon.max_durability = 10;
    WeaponSword->weapon.actual_durabiulity  = 10;
    WeaponSword->weapon.id = WOODEN_SWORD;
    WeaponSword->type = WEAPON;

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
    ToolsAx->tools.name = malloc(sizeof (char *));
    ToolsAx->tools.name ="ax";
    ToolsAx->tools.max_durability=10;
    ToolsAx->tools.actual_durabiulity=10;
    ToolsAx->tools.id = WOODEN_AX;
    ToolsAx->type= TOOL;


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
            printf("Vos item %s", PlayerStruct.inventory[i].tools.name);
        }

}