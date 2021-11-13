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
    wolf -> id = 1;
    wolf -> name = "wolf";
    wolf -> currentLife = 5;
    wolf -> maxLife = 5;
    wolf -> damage = 2.0;
    wolf -> experience = 5;
    wolf -> zone = 1;
    
    Monster * creeper = malloc(sizeof(Monster));
    creeper -> id = 2;
    creeper -> name = "creeper";
    creeper -> currentLife = 7;
    creeper -> maxLife = 7;
    creeper -> damage = 3;
    creeper -> experience = 10;
    creeper -> zone = 1;
    
    Monster * cheetah = malloc(sizeof(Monster));
    cheetah -> id = 3;
    cheetah -> name = "cheetah";
    cheetah -> currentLife = 10;
    cheetah -> maxLife = 10;
    cheetah -> damage = 1.0;
    cheetah -> experience = 15;
    cheetah -> zone = 1;

    
    allMonster -> allMonster[0] = *wolf;
    allMonster -> allMonster[1] = *creeper;
    allMonster -> allMonster[2] = *cheetah;
    
}



