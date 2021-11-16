#ifndef MALLOC_WORLD_INCLUDE_H
#define MALLOC_WORLD_INCLUDE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


typedef struct Player Player;


struct Weapon {
    int id;
    char *name;
    int damage;
    float max_durability;
    float actual_durabiulity;
};
typedef struct Weapon Weapon;

struct Tools {
    int id;
    char *name;
    float max_durability;
    float actual_durabiulity;
};
typedef struct Tools Tools;

struct Resource {
    int id;
    int quantity;
};
typedef struct Resource Resource;


struct Item {
    int type;
    union {
        struct Weapon weapon;
        struct Tools tools;
        struct Resource resource;
    };
};
typedef struct Item Item;

struct Player {
    int experience;
    int level;
    int currentHealthPoints;
    int maxHealthpoints;
    int coord_x;
    int coord_y;
    int actual_map;
    Item inventory[10];
};

enum entity {
    PORTAL1_2 = -3,
    PORTAL2_3 = -2,
    IMPASSABLE = -1,
    FREE = 0,
    PLAYER = 1,
    NPC = 2,
    PLANT1 = 3,
    ROCK1 = 4,
    WOOD1 = 5,
    PLANT2 = 6,
    ROCK2 = 7,
    WOOD2 = 8,
    PLANT3 = 9,
    ROCK3 = 10,
    WOOD3 = 11,
    END8BOSS = 99
};
typedef enum entity entity;

enum resource {
    FIR = 5,
    ROCK = 6,
    GRASS = 7,
    BEECH = 16,
    IRON = 17,
    LAVANDER = 18,
    OAK = 27,
    DIAMOND = 28,
    HEMP = 29,
};
typedef enum resource resource;
enum weaponEnum {
    WOODEN_SWORD = 1,
    STONE_SWORD = 8,
    STONE_SPEAR = 9,
    STONE_HAMMER = 10,
    IRON_SWORD = 19,
    IRON_SPEAR = 20,
    IRON_HAMMER = 21,
};
typedef enum weaponEnum weaponEnum;
enum tools {
    WOODEN_PICKAXE = 2,
    WOODEN_BILLHOOK = 3,
    WOODEN_AX = 4,
    STONE_PICKAXE = 12,
    STONE_BILLHOOK = 13,
    STONE_AX = 14,
    IRON_PICKAXE = 23,
    IRON_BILLHOOK = 24,
    IRON_AX = 25,
};
enum type {
    WEAPON = 1,
    TOOL = 2,
    RESOURCE = 3,
};
typedef enum tools tools;
typedef enum tools tools;


static int  mapsSize[3]={8,10,12};

void InitPlayer(Player *);

int** createTable(int size);
void fill_tab(int **tab,int size);

void printTest(Player);

#endif
