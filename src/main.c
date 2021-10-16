#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Player {
    int experience;
    int level;
    int currentHealthPoints;
    int maxHealthpoints;
    int inventory[10][3];
};
typedef struct Player Player;

void StatDepartPlayer(Player *);

void CollecteRessources(Player *);

void PrintInventory(Player);

int main(int argc, const char *argv[]) {
    Player PlayerStruct;
    //Stat du Player au début de la partie
    StatDepartPlayer(&PlayerStruct);
    //CollecteRessources
    CollecteRessources(&PlayerStruct);
    //printInventaire
    PrintInventory(PlayerStruct);
    return 0;
}
void PrintInventory(Player p){
    for (int i = 0; i < 5; i++) {
        printf("Votre inventaire : %d",p.inventory[i][0]);
    }
}

void StatDepartPlayer(Player *PlayerDebut) {
    PlayerDebut->level = 1;
    PlayerDebut->currentHealthPoints = 100;
    PlayerDebut->maxHealthpoints = 100;
    PlayerDebut->inventory[0][0] = 1;
    PlayerDebut->inventory[0][1] = 10;
    PlayerDebut->inventory[0][2] = 1;
    PlayerDebut->inventory[1][0] = 2;
    PlayerDebut->inventory[1][1] = 10;
    PlayerDebut->inventory[1][2] = 0;
    PlayerDebut->inventory[2][0] = 3;
    PlayerDebut->inventory[2][1] = 10;
    PlayerDebut->inventory[2][2] = 0;
    PlayerDebut->inventory[3][0] = 4;
    PlayerDebut->inventory[3][1] = 10;
    PlayerDebut->inventory[3][2] = 0;
}

void CollecteRessources(Player *inventoryCollect) {
    int nextBox = 6;

    //On verifie l'item
    int indexItem = VerifItem(inventoryCollect, nextBox);

    if(indexItem != -1){
        //On verifie la durabilite
        int durability = VerifDurability(inventoryCollect, nextBox, indexItem);
        if(durability != -1){
            //On ajoute la ressource
            int addResource = AddInventoryResources(inventoryCollect,nextBox);
            if(addResource != -1){
                printf("%d Ressources ajoute ! ",addResource);
            }else{
                printf("inventory pleins ! ");
            }
        }else{
            printf("Vous n'avez plus de durabilite sur l'outil necessaire !");
        }
    }else{
        printf("Vous n'avez pas l'outil necessaire !");
    }
}

int VerifResource(Player *inventoryCollect,int nextBox) {
    int resource = ResourceNecessary(nextBox);
    //on verifie si le Player a deja l'element
    for (int i = 0; i < sizeof(inventoryCollect); i++) {
        //on verifie si le Player a deja de la pierre
        if (inventoryCollect->inventory[i][0] == resource) {
            return i;
        }
    }
    return -1;
}

int *ToolsNecessary(int nextBox) {
    //PLANTE
    if (nextBox == 3) {
        int tools[3];
        tools[0] = 3;
        tools[1] = 13;
        tools[2] = 24;
        return tools;
    }
    if (nextBox == 6) {
        int tools[2];
        tools[0] = 13;
        tools[1] = 24;
        return tools;
    }
    if (nextBox == 9) {
        int tools[1];
        tools[0] = 24;
        return tools;
    }
    //ROCHE
    if (nextBox == 4) {
        int tools[3];
        tools[0] = 2;
        tools[1] = 12;
        tools[2] = 23;
        return tools;
    }
    if (nextBox == 7) {
        int tools[2];
        tools[0] = 12;
        tools[1] = 23;
        return tools;
    }
    if (nextBox == 10) {
        int tools[1];
        tools[0] = 23;
        return tools;
    }
    //BOIS
    if (nextBox == 5) {
        int tools[3];
        tools[0] = 4;
        tools[1] = 14;
        tools[2] = 25;
        return tools;
    }
    if (nextBox == 8) {
        int tools[2];
        tools[0] = 14;
        tools[1] = 25;
        return tools;
    }
    if (nextBox == 11) {
        int tools[1];
        tools[0] = 25;
        return tools;
    }
}

int ResourceNecessary(int nextBox){
    //PLANTE
    if (nextBox == 3) {
        return 7;
    }
    if (nextBox == 6) {
        return 18;
    }
    if (nextBox == 9) {
        return 29;
    }
    //ROCHE
    if (nextBox == 4) {
        return 6;
    }
    if (nextBox == 7) {
        return 17;
    }
    if (nextBox == 10) {
        return 28;
    }
    //BOIS
    if (nextBox == 5) {
        return 5;
    }
    if (nextBox == 8) {
        return 16;
    }
    if (nextBox == 11) {
        return 27;
    }
    return -1;
}

int VerifItem(Player *inventoryCollect, int nextBox) {
    //On verifie si il l'item
    int *tools = ToolsNecessary(nextBox);
    for (int i = 0; i < sizeof(inventoryCollect); i++) {
        for (int j = 0; j < sizeof(tools); j++) {
            if (inventoryCollect->inventory[i][0] == tools[j]) {
                return i;
            }
        }
    }
}

int VerifDurability(Player *inventoryCollect, int nextBox, int item) {
    int percentage =0;
    if (nextBox > 2 && nextBox < 6) {
        percentage = 10;
    }
    if (nextBox > 5 && nextBox < 9) {
        percentage = 20;
    }
    if (nextBox > 8 && nextBox < 12) {
        percentage = 40;
    }
    //si la pelle à de la durabilité
    if (inventoryCollect->inventory[item][1] != 0) {
        //on enleve % de durabilité
        inventoryCollect->inventory[item][1] -= inventoryCollect->inventory[item][1] / percentage;
        return 0;
    }
    return -1;
}

int AddInventoryResources(Player *inventoryCollect, int nextBox) {

    srand(time(NULL));
    int indexResources = VerifResource(inventoryCollect,nextBox);
    int randomResourceNumber = rand() % ((5) - 1) + 1;
    //On verifie si il y a de la pierre et on stack de 1 à 4
    if (indexResources != -1) {
        inventoryCollect->inventory[indexResources][0] += randomResourceNumber;
        inventoryCollect->inventory[indexResources][1] = 0;
        inventoryCollect->inventory[indexResources][2] = 0;
        //on verifie si il y a plus de 20 on met a 20
        if (inventoryCollect->inventory[indexResources][0] > 20) {
            inventoryCollect->inventory[indexResources][0] = 20;
        }
    } else {
        //On verifie la disponibilité dans l'inventory du Player et on ajouter 1 à 4
        if (sizeof(inventoryCollect) != 10) {
            inventoryCollect->inventory[sizeof(inventoryCollect)][0] +=
                    randomResourceNumber;
            inventoryCollect->inventory[sizeof(inventoryCollect)][1] = 0;
            inventoryCollect->inventory[sizeof(inventoryCollect)][2] = 0;
        }else{
            return -1;
        }
    }
    return randomResourceNumber;
}