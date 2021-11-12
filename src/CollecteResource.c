#include "include.h"
#include "collecteResource.h"

int collecteRessources(Player *inventoryCollect, int nextBox) {
    //on verifie si ressource
    int nextBoxRessource = verifResource(inventoryCollect, nextBox);
    if (nextBoxRessource != -1) {
        //On verifie l'item
        int indexItem = verifItem(inventoryCollect, nextBox);
        if (indexItem != -1) {
            //On verifie la durabilite
            int durability = verifDurability(inventoryCollect, nextBox, indexItem);
            if (durability != -1) {
                //On ajoute la ressource
                int addResource = addInventoryResources(inventoryCollect, nextBox);
                if (addResource > 0) {
                    printf("%d Ressources ajoute ! ", addResource);
                } else if (addResource == -1) {
                    printf("C'est pas une ressource ");
                    return 0;
                } else {
                    printf("Inventaire pleins !");
                    return 0;
                }
            } else {
                printf("Vous n'avez plus de durabilite sur l'outil necessaire !");
                return 0;
            }
        } else {
            printf("Vous n'avez pas l'outil necessaire !");
            return 0;
        }
    } else {
        printf("PAS UNE RESSOURCE");
        return 0;
    }
    return 1;
}

int *toolsNecessary(int nextBox) {

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
        tools[0] = STONE_AX;
        tools[1] = IRON_AX;
        return tools;
    }
    if (nextBox == WOOD3) {
        int tools[1];
        tools[0] = IRON_AX;
        return tools;
    }
}

int resourceNecessary(int nextBox) {
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

int verifResource(Player *inventoryCollect, int nextBox) {
    int resource = resourceNecessary(nextBox);
    if (resource == -1) {
        return -1;
    }
    //on verifie si le Player a deja l'element
    for (int i = 0; i < 10; i++) {
        //on verifie si le Player a deja de la pierre
        if (inventoryCollect->inventory[i].type == RESOURCE) {
            if (inventoryCollect->inventory[i].resource.id == resource) {
                return i;
            }
        }
    }
    resource += 100;
    return resource;
}

int verifItem(Player *inventoryCollect, int nextBox) {
    //On verifie si il l'item
    int *tools = toolsNecessary(nextBox);
    for (int i = 0; i < 10;i++) {
        for (int j = 0; j < 4; j++) {
            if (inventoryCollect->inventory[i].type == TOOL) {
                if (inventoryCollect->inventory[i].tools.id == tools[j]) {
                    return i;
                }
            }
        }
    }
    return -1;
}

char *resourceName(int resourceId) {
    if (resourceId == GRASS) {
        return "herbe";
    }
    if (resourceId == LAVANDER) {
        return "lavande";
    }
    if (resourceId == HEMP) {
        return "chanvre";
    }
    //ROCHE
    if (resourceId == ROCK) {
        return "pierre";
    }
    if (resourceId == IRON) {
        return "fer";
    }
    if (resourceId == DIAMOND) {
        return "diamant";
    }
    //BOIS
    if (resourceId == FIR) {
        return "sapin";
    }
    if (resourceId == BEECH) {
        return "hetre";
    }
    if (resourceId == OAK) {
        return "chene";
    }
    return "null";
}

int verifDurability(Player *inventoryCollect, int nextBox, int item) {
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
        inventoryCollect->inventory[item].tools.actual_durabiulity -=
                inventoryCollect->inventory[item].tools.actual_durabiulity / percentage;
        return 0;
    }
    return -1;
}

int addInventoryResources(Player *inventoryCollect, int nextBox) {

    srand(time(NULL));
    int indexResources = verifResource(inventoryCollect, nextBox);
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
        int sizeinv = 0;
        for (int i = 0; i < 10; i++) {
            if (inventoryCollect->inventory[i].type > 0 && inventoryCollect->inventory[i].type < 6) {
                sizeinv++;

            }
        }
        if (sizeinv < 9) {

            indexResources -= 100;
            inventoryCollect->inventory[sizeinv].type = RESOURCE;
            inventoryCollect->inventory[sizeinv].resource.name = resourceName(indexResources);
            inventoryCollect->inventory[sizeinv].resource.id = indexResources;
            inventoryCollect->inventory[sizeinv].resource.quantity = randomResourceNumber;
            printf("Item ajoutee a votre inventaire : \n %s ",
                   inventoryCollect->inventory[sizeinv].resource.name = resourceName(
                           indexResources));
        } else {
            printf("Vous avez deja 10 inventaires !");
        }
    }
    return randomResourceNumber;
}

