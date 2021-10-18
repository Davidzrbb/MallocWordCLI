#ifndef MALLOC_WORLD_CLI_COLLECT_RESSOURCE_H
#define MALLOC_WORLD_CLI_COLLECT_RESSOURCE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct Weapon Weapon;

typedef struct Player Player;

struct Weapon{
    char * name;
    int id;
    int damage;
    float max_durability;
    float actual_durabiulity;
};
typedef struct Weapon Weapon;

struct Tools{
   char * name;
    int id;
    float max_durability;
    float actual_durabiulity;
};
typedef struct Tools Tools;

struct Resource{
    int id;
    int quantity;
};
typedef struct Resource Resource;

struct AllObjectInventory{
    struct  Weapon weapon;
    struct  Tools tools;
    struct  Resource resource;
};
typedef struct AllObjectInventory AllObjectInventory;

struct Player {
    int experience;
    int level;
    int currentHealthPoints;
    int maxHealthpoints;
    AllObjectInventory inventory[10];
};

enum entity {
    PORTAL1_2 = -3,
    PORTAL2_3 = -2,
    IMPASSABLE = -1,
    FREE = 0,
    PLAYER = 1,
    NPC = 2,
    PLANT1 = 3,
    ROCK1= 4,
    WOOD1=5,
    PLANT2=6,
    ROCK2=7,
    WOOD2=8,
    PLANT3=9,
    ROCK3=10,
    WOOD3=11,
    END8BOSS=99,
};
typedef enum entity entity;

enum resource {
    FIR = 5,
    ROCK = 6,
    GRASS = 7,
    BEECH = 16,
    IRON = 17,
    LAVANDER= 18,
    OAK = 27,
    DIAMOND= 28,
    HEMP=29,
};
typedef enum resource resource;
enum tools {
    WOODEN_PICKAXE = 2,
    WOODEN_BILLHOOK = 3,
    WOODEN_AX = 4,
    STONE_PICKAXE = 12,
    STONE_BILLHOOK = 13,
    STONE_AX= 14,
    IRON_PICKAXE = 23,
    IRON_BILLHOOK= 24,
    IRON_AX =25,
};
typedef enum tools tools;

void InitPlayer(Player * );
void MovePlayer(Player);
void CollecteRessources(Player *inventoryCollect, int nextBox);
int VerifResource(Player *inventoryCollect,int nextBox);
int VerifItem(Player *inventoryCollect, int nextBox);
int VerifDurability(Player *inventoryCollect, int nextBox, int item);
int AddInventoryResources(Player *inventoryCollect, int nextBox);


#endif //MALLOC_WORLD_CLI_COLLECT_RESSOURCE_H