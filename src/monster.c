//
//  monstre.c
//  ESGIPROJET
//
//  Created by Marwan Khalil on 18/10/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "include.h"
#include "monster.h"


// CREATION DES MONSTRES PAR ZONE
void initMonster(AllMonster * allMonster){
    
    Monster * wolf = malloc(sizeof(Monster));
    wolf -> id = 90;
    wolf -> name = "wolf";
    wolf -> currentLife = 5;
    wolf -> maxLife = 5;
    wolf -> damage = 2;
    wolf -> experience = 5;
    wolf -> zone = 1;
    
    Monster * creeper = malloc(sizeof(Monster));
    creeper -> id = 91;
    creeper -> name = "creeper";
    creeper -> currentLife = 7;
    creeper -> maxLife = 7;
    creeper -> damage = 3;
    creeper -> experience = 10;
    creeper -> zone = 1;
    
    Monster * cheetah = malloc(sizeof(Monster));
    cheetah -> id = 92;
    cheetah -> name = "cheetah";
    cheetah -> currentLife = 10;
    cheetah -> maxLife = 10;
    cheetah -> damage = 5;
    cheetah -> experience = 15;
    cheetah -> zone = 1;
    
    Monster * Creep3 = malloc(sizeof(Monster));
    Creep3 -> id = 93;
    Creep3 -> name = "creep3";
    Creep3 -> currentLife = 13;
    Creep3 -> maxLife = 13;
    Creep3 -> damage = 10;
    Creep3 -> experience = 23;
    Creep3 -> zone = 2;

    Monster * Creep4 = malloc(sizeof(Monster));
    Creep4 -> id = 94;
    Creep4 -> name = "creep4";
    Creep4 -> currentLife = 15;
    Creep4 -> maxLife = 15;
    Creep4 -> damage = 13;
    Creep4 -> experience = 25;
    Creep4 -> zone = 2;
    
    Monster * Creep5 = malloc(sizeof(Monster));
    Creep5 -> id = 95;
    Creep5 -> name = "creep5";
    Creep5 -> currentLife = 20;
    Creep5 -> maxLife = 20;
    Creep5 -> damage = 15;
    Creep5 -> experience = 27;
    Creep5 -> zone = 2;
    
    Monster * Creep6 = malloc(sizeof(Monster));
    Creep6 -> id = 96;
    Creep6 -> name = "creep6";
    Creep6 -> currentLife = 23;
    Creep6 -> maxLife = 23;
    Creep6 -> damage = 18;
    Creep6 -> experience = 30;
    Creep6 -> zone = 3;
    
    Monster * Creep7 = malloc(sizeof(Monster));
    Creep7 -> id = 97;
    Creep7 -> name = "creep7";
    Creep7 -> currentLife = 25;
    Creep7 -> maxLife = 25;
    Creep7 -> damage = 20;
    Creep7 -> experience = 35;
    Creep7 -> zone = 3;
    
    Monster * Creep8 = malloc(sizeof(Monster));
    Creep8 -> id = 98;
    Creep8 -> name = "creep8";
    Creep8 -> currentLife = 30;
    Creep8 -> maxLife = 30;
    Creep8 -> damage = 25;
    Creep8 -> experience = 37;
    Creep8 -> zone = 3;

    Monster * finalBoss = malloc(sizeof(Monster));
    finalBoss -> id = 99;
    finalBoss -> name = "finalBoss";
    finalBoss -> currentLife = 500;
    finalBoss -> maxLife = 500;
    finalBoss -> damage = 75;
    finalBoss -> experience = 1000;
    finalBoss -> zone = 3;

    
    allMonster -> allMonster[0] = wolf;
    allMonster -> allMonster[1] = creeper;
    allMonster -> allMonster[2] = cheetah;
    allMonster -> allMonster[3] = Creep3;
    allMonster -> allMonster[4] = Creep4;
    allMonster -> allMonster[5] = Creep5;
    allMonster -> allMonster[6] = Creep6;
    allMonster -> allMonster[7] = Creep7;
    allMonster -> allMonster[8] = Creep8;
    allMonster -> allMonster[8] = finalBoss;
    
    
}



