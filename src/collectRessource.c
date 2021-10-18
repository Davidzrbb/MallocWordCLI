#include "../include/collectRessource.h"

void CollecteRessources(Player *inventoryCollect, int nextBox) {
    //on verifie si ressource
    int nextBoxRessource = VerifResource(inventoryCollect, nextBox);
    if (nextBoxRessource != -1) {
        //On verifie l'item
        int indexItem = VerifItem(inventoryCollect, nextBox);
        if (indexItem != -1) {
            //On verifie la durabilite
            int durability = VerifDurability(inventoryCollect, nextBox, indexItem);
            if (durability != -1) {
                //On ajoute la ressource
                int addResource = AddInventoryResources(inventoryCollect, nextBox);
                if (addResource > 0) {
                    printf("%d Ressources ajoute ! ", addResource);
                } else if (addResource == -1) {
                    printf("C'est pas une ressource ");
                } else {
                    printf("Inventaire pleins !");
                }
            } else {
                printf("Vous n'avez plus de durabilite sur l'outil necessaire !");
            }
        } else {
            printf("Vous n'avez pas l'outil necessaire !");
        }
    }else{
        printf("PAS UNE RESSOURCE");
    }
}

int *ToolsNecessary(int nextBox) {

    //PLANTE
    if (nextBox == PLANT1) {
        int tools[3];
        tools[0] = WOODEN_BILLHOOK;
        tools[1] = STONE_BILLHOOK;
        tools[2] = IRON_BILLHOOK;
        return tools;
    }
    if (nextBox == PLANT2) {
        int tools[2];
        tools[0] = STONE_BILLHOOK;
        tools[1] = IRON_BILLHOOK;
        return tools;
    }
    if (nextBox == PLANT3) {
        int tools[1];
        tools[0] = IRON_BILLHOOK;
        return tools;
    }
    //ROCHE
    if (nextBox == ROCK1) {
        int tools[3];
        tools[0] = WOODEN_PICKAXE;
        tools[1] = STONE_PICKAXE;
        tools[2] = IRON_PICKAXE;
        return tools;
    }
    if (nextBox == ROCK2) {
        int tools[2];
        tools[0] = STONE_PICKAXE;
        tools[1] = IRON_PICKAXE;
        return tools;
    }
    if (nextBox == ROCK3) {
        int tools[1];
        tools[0] = IRON_PICKAXE;
        return tools;
    }
    //BOIS
    if (nextBox == WOOD1) {
        int tools[3];
        tools[0] = WOODEN_AX;
        tools[1] = STONE_AX;
        tools[2] = IRON_AX;
        return tools;
    }
    if (nextBox == WOOD2) {
        int tools[2];
        tools[0] =  STONE_AX;
        tools[1] = IRON_AX;
        return tools;
    }
    if (nextBox == WOOD3) {
        int tools[1];
        tools[0] = IRON_AX;
        return tools;
    }
}

int ResourceNecessary(int nextBox) {
    if (nextBox < PLANT1 || nextBox > WOOD3) {
        return -1;
    }
    //PLANTE
    if (nextBox == PLANT1) {
        return GRASS;
    }
    if (nextBox == PLANT2) {
        return LAVANDER;
    }
    if (nextBox == PLANT3) {
        return HEMP;
    }
    //ROCHE
    if (nextBox == ROCK1) {
        return ROCK;
    }
    if (nextBox == ROCK2) {
        return IRON;
    }
    if (nextBox == ROCK3) {
        return DIAMOND;
    }
    //BOIS
    if (nextBox == WOOD1) {
        return FIR;
    }
    if (nextBox == WOOD2) {
        return BEECH;
    }
    if (nextBox == WOOD3) {
        return OAK;
    }
}

int VerifResource(Player *inventoryCollect, int nextBox) {
    int resource = ResourceNecessary(nextBox);
    if (resource == -1) {
        return -1;
    }
    //on verifie si le Player a deja l'element
    for (int i = 0; i < sizeof(inventoryCollect); i++) {
        //on verifie si le Player a deja de la pierre
        if (inventoryCollect->inventory[i].resource.id == resource) {
            return i;
        }
    }
    resource += 100;
    return resource;
}

int VerifItem(Player *inventoryCollect, int nextBox) {
    //On verifie si il l'item
    int *tools = ToolsNecessary(nextBox);
    for (int i = 0; i < sizeof(inventoryCollect); i++) {
        for (int j = 0; j < sizeof(tools); j++) {
            if (inventoryCollect->inventory[i].tools.id == tools[j]) {
                return i;
            }
        }
    }
    return -1;
}

int VerifDurability(Player *inventoryCollect, int nextBox, int item) {
    int percentage = 0;
    //On determine la zone
    if (nextBox > NPC && nextBox < PLANT2) {
        percentage = 10;
    }
    if (nextBox > WOOD1 && nextBox < PLANT3) {
        percentage = 20;
    }
    if (nextBox > WOOD2 && nextBox <= WOOD3) {
        percentage = 40;
    }
    //si la pelle à de la durabilité
    if (inventoryCollect->inventory[item].tools.actual_durabiulity != 0) {
        //on enleve % de durabilité
        inventoryCollect->inventory[item].tools.actual_durabiulity -= inventoryCollect->inventory[item].tools.actual_durabiulity / percentage;
        return 0;
    }
    return -1;
}

int AddInventoryResources(Player *inventoryCollect, int nextBox) {

    srand(time(NULL));
    int indexResources = VerifResource(inventoryCollect, nextBox);
    int randomResourceNumber = rand() % ((5) - 1) + 1;
    //on verifie si la next box est une ressource si -1 pas ressource
    if (indexResources == -1) {
        return -1;
    }
    //On verifie si il y a de la pierre et on stack de 1 à 4
    if (indexResources < 100) {
        inventoryCollect->inventory[indexResources].resource.quantity += randomResourceNumber;
        //on verifie si il y a plus de 20 on met a 20
        if (inventoryCollect->inventory[indexResources].resource.quantity > 20) {
            inventoryCollect->inventory[indexResources].resource.quantity = 20;
        }
    } else {
        //On verifie la disponibilité dans l'inventory du Player et on ajouter 1 à 4
        if (sizeof(inventoryCollect) != 10) {
            indexResources -= 100;
            inventoryCollect->inventory[sizeof(inventoryCollect)].resource.id = indexResources;
            inventoryCollect->inventory[sizeof(inventoryCollect)].resource.quantity = randomResourceNumber;
        } else {
            //pas de place dans l'inventaire
            return -2;
        }
    }
    return randomResourceNumber;
}