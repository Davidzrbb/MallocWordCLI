//
//  include.h
//  ESGIPROJET
//
//  Created by Marwan Khalil on 19/10/2021.
//

#define FIGT_H
#define LEVEL_H
#define MONSTER_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct Armor{
    char * name;
    int id;
    int protection;
};
typedef struct Armor Armor;

enum armor {
    STONE_CHESTPLATE = 11,
    IRON_CHESTPLATE = 22,
    DIAMOND_CHESTPLATE = 33,
};
typedef enum armor armor;


struct healthPotion{
    char * name;
    int id;
    int pvRestore;
    int quantity;
};
typedef struct healthPotion healthPotion;

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

struct Item {
    int type;
    union {
        struct Weapon weapon;
        struct Tools tools;
        struct Resource resource;
        struct healthPotion healhPotion;
        struct Armor armor;
    };
};
typedef struct Item Item;

struct Player {
    int experience;
    int level;
    int currentExperience;
    int maxExperience;
    float currentHealthPoints;
    float maxHealthpoints;
    Item currentWeapon;
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

enum weaponEnum {
    WOODEN_SWORD = 1,
    STONE_SWORD = 8,
    STONE_SPEAR = 9,
    STONE_HAMMER = 10,
    IRON_SWORD = 19,
    IRON_SPEAR = 20,
    IRON_HAMMER = 21,
    DIAMOND_SWORD = 30,
    DIAMOND_SPEAR = 31,
    DIAMOND_HAMMER = 32
};
typedef enum weaponEnum weaponEnum;

enum type {
    WEAPON = 1,
    TOOL = 2,
    RESOURCE = 3,
    HEALTHPOTION = 4,
};
typedef enum type type;

struct Monster
{
    int id;
    char* name;
    int currentLife;
    int maxLife;
    float damage;
    int experience;
    int zone;
};
typedef struct Monster Monster;

struct AllMonster{
    Monster allMonster[10];
};

typedef struct AllMonster AllMonster;


void InitPlayer(Player * );
void printTest(Player);
void attackPlayer(Player* player, Monster* monster, Weapon*);
void attackMonster(Player* player, Monster* monster);
void addLevel(Player * player);
void initMonster(AllMonster*);
void printMonster(AllMonster);
Weapon weaponChoice(Player *);
void combat(Player *, Monster*);
void printHealth(Player * player, Monster * monster);
    
