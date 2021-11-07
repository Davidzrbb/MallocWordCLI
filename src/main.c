#include "../include/include.h"
#include "../include/pnjService.h"
int main(int argc, const char *argv[]) {
    Player PlayerStruct;
    Item ItemStruct;

    //PnjLinkedList stock;
    PnjLinkedList *stock = malloc(sizeof (PnjLinkedList));
    initStructStock(stock);
    MovePlayer(PlayerStruct);

    //Stat du Player au début de la partie
    InitPlayer(&PlayerStruct);

    Item *WeaponSword = malloc(sizeof(Item));
    WeaponSword->weapon.name = "epee en bois";
    WeaponSword->weapon.damage= 1;
    WeaponSword->weapon.max_durability = 10;
    WeaponSword->weapon.actual_durabiulity  = 10;
    WeaponSword->weapon.id = WOODEN_SWORD;
    WeaponSword->type = WEAPON;

    //PnjFix
    pnjChoice(&PlayerStruct,stock);

    //Print
    //printTest(PlayerStruct);
    return 0;
}

void InitPlayer(Player* firstPlayer) {
    Item *WeaponSword = malloc(sizeof(Item));
    WeaponSword->weapon.damage= 1;
    WeaponSword->weapon.name ="epee en bois";
    WeaponSword->weapon.max_durability = 10;
    WeaponSword->weapon.actual_durabiulity  = 10;
    WeaponSword->weapon.id = WOODEN_SWORD;
    WeaponSword->type = WEAPON;

    Item *ToolsPickaxe = malloc(sizeof(Item));
    ToolsPickaxe->tools.name = "pioche en bois";
    ToolsPickaxe->tools.max_durability=10;
    ToolsPickaxe->tools.actual_durabiulity=5;
    ToolsPickaxe->tools.id= WOODEN_PICKAXE;
    ToolsPickaxe->type= TOOL;

    Item  *ToolsBillhook = malloc(sizeof(Item));
    ToolsBillhook->tools.name ="serpette en bois";
    ToolsBillhook->tools.max_durability=10;
    ToolsBillhook->tools.actual_durabiulity=10;
    ToolsBillhook->tools.id= WOODEN_BILLHOOK;
    ToolsBillhook->type= TOOL;

    firstPlayer->level = 1;
    firstPlayer->currentHealthPoints = 100;
    firstPlayer->maxHealthpoints = 100;
    firstPlayer->inventory[0] = *WeaponSword ;
    firstPlayer->inventory[1] = *ToolsPickaxe ;
    firstPlayer->inventory[2] = *ToolsBillhook ;
    firstPlayer->inventory[3] = *ToolsAx ;
}

    Item *ToolsAx = malloc(sizeof(Item));
    ToolsAx->tools.name = malloc(sizeof (char *));
    ToolsAx->tools.name ="hache en bois";
    ToolsAx->tools.max_durability=10;
    ToolsAx->tools.actual_durabiulity=10;
    ToolsAx->tools.id = WOODEN_AX;
    ToolsAx->type= TOOL;
void MovePlayer(Player PlayerStruct) {
    int nextBox = 3;
   // printf("Votre arme %d",PlayerStruct.inventory[0].weapon.id);
   //collecteRessources
    collecteRessources(&PlayerStruct, nextBox);
}

    Item *Sapin = malloc(sizeof(Item));
    Sapin->resource.name = malloc(sizeof (char *));
    Sapin->resource.name ="sapin";
    Sapin->resource.id = FIR;
    Sapin->resource.quantity=3;
    Sapin->type= RESOURCE;

    Item *Pierre = malloc(sizeof(Item));
    Pierre->resource.name = malloc(sizeof (char *));
    Pierre->resource.name ="pierre";
    Pierre->resource.id = ROCK;
    Pierre->resource.quantity=4;
    Pierre->type= RESOURCE;


    firstPlayer->level = 1;
    firstPlayer->currentHealthPoints = 100;
    firstPlayer->maxHealthpoints = 100;
    firstPlayer->inventory[0] = *WeaponSword ;
    firstPlayer->inventory[1] = *ToolsPickaxe ;
    firstPlayer->inventory[2] = *ToolsBillhook ;
    firstPlayer->inventory[3] = *ToolsAx ;
    firstPlayer->inventory[4] = *Sapin ;
    firstPlayer->inventory[5] = *Pierre ;

}

void printTest(Player PlayerStruct){
    for (int i = 0; i<sizeof(PlayerStruct.inventory[i].type);i++){
            //printf("Vos item %s", PlayerStruct.inventory[i].tools.name);
        }

}