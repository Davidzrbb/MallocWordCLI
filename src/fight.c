//
//  fight.c
//  ESGIPROJET
//
//  Created by Marwan Khalil on 19/10/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include "fight.h"
#include "monster.h"
#include "include.h"

//CHOIX DE L'ARME DU JOUEUR POUR LE COMBAT
Weapon weaponChoice(Player * player){
    int choice = 0;
    int res;
    
    printf("Choisissez une arme pour le combat : \n");
    for (int i = 0; i<10; i++) {
        if(player->inventory[i].type == WEAPON){
            printf("\n %d %s \n ",i ,player -> inventory[i].weapon.name);
        }
    }
    res = scanf("%d", &choice);
    if (player -> inventory[choice].type != WEAPON) {
        printf("Saisie incorrecte veuillez saisir une arme de la liste. ");
        weaponChoice(player);
    }
    else{
        player -> currentWeapon = player -> inventory[choice];
        printf(" \n ARME EQUIPEE :  %s \n " ,player -> currentWeapon.weapon.name);
    }
    return player -> currentWeapon.weapon;
}

//AFFICHAGE DE LA VIE DU PERSO ET DU MONSTRE
void printHealth(Player * player, Monster * monster){
    player->currentWeapon = player->inventory[0];
    printf("PLAYER LIFE : %f \n " ,player->currentHealthPoints);
    printf("MONSTER LIFE : %d \n" ,monster -> currentLife);
}

//ATTAQUE DU JOUEUR SUR UN MONSTRE
void attackPlayer(Player* player, Monster* monster, Weapon* weapon) {
    if(weapon->actual_durabiulity != 0){
        switch (weapon-> id ) {
            case  1:
                monster -> currentLife -= 1;
                weapon -> actual_durabiulity -= 1;
                break;
            case  8:
                monster -> currentLife -= 2;
                weapon -> actual_durabiulity -= 1;
                break;
                
            case  9:
                monster -> currentLife -= 3;
                weapon ->actual_durabiulity -= 1;
                break;

            case 10:
                monster -> currentLife -= 4;
                weapon ->actual_durabiulity -= 1;
                break;

            case  19:
                monster -> currentLife -= 5;
                weapon-> actual_durabiulity -= 1;
                break;

            case  20:
                monster -> currentLife -= 7;
                weapon->actual_durabiulity -= 1;
                break;

            case  21:
                monster -> currentLife -= 10;
                weapon->actual_durabiulity -= 1;
                break;

            case 30:
                monster -> currentLife -= 10;
                weapon->actual_durabiulity -= 1;
                break;

            case 31:
                monster -> currentLife -= 15;
                weapon->actual_durabiulity -= 1;
                break;

            case  32:
                monster -> currentLife -= 20;
                weapon->actual_durabiulity -= 1;
                break;
            default:
                break;
        }
    }
    else {
        printf("Votre arme n'est plus utilisable allez la réparer ou utilisez en une autre !");
    }
}
//ATTAQUED DU MONSTRES SUR LE JOUEUR
void attackMonster(Player* player, Monster* monster) {
    int idMonster = 0;
    idMonster = monster -> id;
    if(player -> currentHealthPoints != 0){
        
        switch (idMonster) {
            case  1:
                switch(player -> inventory -> armor.id){
                    case 0 :
                        player -> currentHealthPoints -= monster -> damage;
                        break;
                        
                    case 11 :
                        player -> currentHealthPoints = player -> currentHealthPoints - (monster -> damage * 0.9);
                        break;
                        
                    case 21 :
                        player -> currentHealthPoints -= (monster -> damage * 0.8);
                        break;
                        
                    case 33 :
                        player -> currentHealthPoints -= (monster -> damage * 0.6);
                        break;
                        
                    default:
                        break;
                }
                break;

            case  2:
                switch(player -> inventory -> armor.id){
                    case 0 :
                        player -> currentHealthPoints -= monster -> damage;
                        break;
                        
                    case 11 :
                        player -> currentHealthPoints -= (monster -> damage * 0.9);
                        break;
                        
                    case 21 :
                        player -> currentHealthPoints -= (monster -> damage * 0.8);
                        break;
                        
                    case 33 :
                        player -> currentHealthPoints -= (monster -> damage * 0.6);
                        break;
                        
                    default:
                        break;
                }
                break;

            case 3:
                switch(player -> inventory -> armor.id){
                    case 0 :
                        player -> currentHealthPoints -= monster -> damage;
                        break;
                        
                    case 11 :
                        player -> currentHealthPoints -= (monster -> damage * 0.9);
                        break;
                        
                    case 21 :
                        player -> currentHealthPoints -= (monster -> damage * 0.8);
                        break;
                        
                    case 33 :
                        player -> currentHealthPoints -= (monster -> damage * 0.6);
                        break;
                        
                    default:
                        break;
                }
                break;
            default:
                break;
        }
    }
    
    else {
        player -> currentExperience += monster -> experience;
    }
}

//UTILISATION DE SOINS
void healPlayer(Player* player){
    int hpToRestore = 0;
    hpToRestore = ((player -> maxHealthpoints) - (player -> currentHealthPoints));
    if(player -> inventory -> healhPotion.quantity != 0){
        switch (player -> inventory -> healhPotion.id ){
            case  1:
                if(hpToRestore >= 30 && hpToRestore < 80){
                    player -> currentHealthPoints += 30;
                    player -> inventory -> healhPotion.quantity -=1;
                }
                else{
                    printf("\n Vous ne pouvez pas utiliser de potion de soins \n");
                }
                break;
                
            case 2 :
                if(hpToRestore >= 80 && hpToRestore < 200){
                    player -> currentHealthPoints += 80;
                    player -> inventory -> healhPotion.quantity -=1;
                }
                else{
                    printf("\n Vous ne pouvez pas utiliser de potion de soins \n");
                }
                break;
                
            case  3 :
                if(hpToRestore >= 200){
                    player -> currentHealthPoints += 200;
                    player -> inventory -> healhPotion.quantity -=1;
                }
                else{
                    printf("\n Vous ne pouvez pas utiliser de potion de soins \n");
                }
                break;
                
            default:
                break;
            
//    if(hpToRestore >= 30 && hpToRestore < 80){
//        for(int i=0 ; i<10; i++){
//            if(player -> inventory -> healhPotion.pvRestore == 30)
//                player-> currentHealthPoints +=30;
//        }
//    }
//    if(hpToRestore >= 80 && hpToRestore < 200){
//        for(int i=0 ; i<10; i++){
//            if(player -> inventory -> healhPotion.pvRestore == 80)
//                player-> currentHealthPoints +=80;
//        }
//    }
//    if(hpToRestore >= 200){
//        for(int i=0 ; i<10; i++){
//            if(player -> inventory -> healhPotion.pvRestore == 200)
//                player-> currentHealthPoints +=200;
//        }
//    }
//    else{
//        printf("\n Vous ne pouvez pas utiliser de potion de soins \n ");
//    }
}
    }
}

//LANCEMENT DU COMBAT
void combat(Player * player, Monster* monster){
    int statut = 0;
    printf("\n ATTENTION UN MONSTRE AU LOIN !!! \n");
    while((player -> currentHealthPoints > 0) && (monster -> currentLife > 0) && (statut == 0)){
        printf("Que souahitez vous faire ? \n 1 - Combattre \n 2 - Se Soigner \n 3 - Fuir \n");
        int choix;
        scanf("%d", &choix);
        Weapon w;
        switch (choix) {
            case 1 :
                w = weaponChoice((player));
                attackPlayer(player, monster, &w);
                attackMonster(player, monster);
                printHealth(player, monster);
                if(monster -> currentLife == 0){
                    printf("\n Vous avez tué le monstre \n");
                    player -> currentExperience += monster -> experience;
                    printf("DURABILITY : %f", w.actual_durabiulity);
                }
                if(player -> currentHealthPoints <= 0){
                    printf("\n Vous êtes mort ! \n ");
                }
                
                break;
            case 2:
                healPlayer(player);
                break;
            case 3:
                printf("C'est dommage tu as préféré fuire\n");
                statut = 1;
                break;
                
            default:
                break;
        }
    }
    
    
    
}
