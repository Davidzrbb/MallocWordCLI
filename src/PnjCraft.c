#include "../include/include.h"
#include "../include/pnjService.h"

void craftItem(Player *playerStruct) {
    ArrayItemCraft *arrayItemCraft = malloc(sizeof (ArrayItemCraft));
    initArrayCraftItem(arrayItemCraft);
}

void initArrayCraftItem(ArrayItemCraft *arrayItemCraft){
    int i, j;

    for (i = 0; i < 25; i++){
        for (j = 0; j < 2; j++){
            arrayItemCraft->arrayItemCraft[i][j] = 0;
        }
    }

}