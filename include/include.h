
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
    char *name;
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
    Item inventory[10];
};
typedef struct Player Player;
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
    END8BOSS = 99,
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
    IRON_SWORD = 19,
    DIAMOND_SWORD = 30,
    STONE_SPEAR = 9,
    IRON_SPEAR = 20,
    DIAMOND_SPEAR = 31,
    STONE_HAMMER = 10,
    IRON_HAMMER = 21,
    DIAMOND_HAMMER = 32,
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
typedef enum tools tools;
enum type {
    WEAPON = 1,
    TOOL = 2,
    RESOURCE = 3,
};
typedef enum item item;

void InitPlayer(Player *);
void printTest(Player);
