//
//  level.c
//  ESGIPROJET
//
//  Created by Marwan Khalil on 18/10/2021.
//
#include <stdlib.h>
#include "include.h"

//MONTEE DE NIVEAU PAR RAPPORT AU NIVEAU ACTUEL
void addLevel(Player * player){
    switch (player -> level) {
        case 1:
            player -> level = 2;
            player -> maxHealthpoints = 110;
            player -> currentHealthPoints = 110;
            player -> currentExperience = 0;
            player -> maxExperience = 10;
            printf("\n LVL UP : 2 \n");

            
            break;
            
        case 2:
            player -> level = 3;
            player -> maxHealthpoints = 130;
            player -> currentHealthPoints = 130;
            player -> currentExperience = 0;
            player -> maxExperience = 10;
            printf("\n LVL UP : 3 \n");

            break;
        
        case 3:
            player -> level = 4;
            player -> maxHealthpoints = 160;
            player -> currentHealthPoints = 160;
            player -> currentExperience = 0;
            player -> maxExperience = 10;
            printf("\n LVL UP : 4 \n ");

            break;
            
        case 4:
            player -> level = 5;
            player -> maxHealthpoints = 200;
            player -> currentHealthPoints = 200;
            player -> currentExperience = 0;
            player -> maxExperience = 10;
            printf("\n LVL UP : 5 \n");
            break;
            
        case 5:
            player -> level = 6;
            player -> maxHealthpoints = 250;
            player -> currentHealthPoints = 250;
            player -> currentExperience = 0;
            player -> maxExperience = 10;
            printf("\n LVL UP : 6 \n");

            break;
            
        case 6:
            player -> level = 7;
            player -> maxHealthpoints = 300;
            player -> currentHealthPoints = 300;
            player -> currentExperience = 0;
            player -> maxExperience = 10;
            printf("\n LVL UP : 7 \n ");

            break;
            
        case 7:
            player -> level = 8;
            player -> maxHealthpoints = 350;
            player -> currentHealthPoints = 350;
            player -> currentExperience = 0;
            player -> maxExperience = 10;
            printf("\n LVL UP : 8 \n");

            break;
            
        case 8:
            player -> level = 9;
            player -> maxHealthpoints = 425;
            player -> currentHealthPoints = 425;
            player -> currentExperience = 0;
            player -> maxExperience = 10;
            printf("\n LVL UP : 9 \n");

            break;
            
        case 9:
            player -> level = 10;
            player -> maxHealthpoints = 500;
            player -> currentHealthPoints = 500;
            player -> currentExperience = 0;
            player -> maxExperience = 10;
            printf("\n LVL UP : 10 \n ");

            break;
            
        default:
            break;
    }
    if (player -> level == 10){
        printf("Vous avez atteint le niveau MAX");
    }
}






