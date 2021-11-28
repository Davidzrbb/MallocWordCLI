//
//  fight.c
//  ESGIPROJET
//
//  Created by Marwan Khalil on 19/10/2021.
//

#include "include.h"
#include "pnjService.h"

//CHOIX DE L'ARME DU JOUEUR POUR LE COMBAT
Weapon weaponChoice(Player *player) {
    int choice = 0;
    int res;

    printf("Choisissez une arme pour le combat : \n");
    for (int i = 0; i < 10; i++) {
        if (player->inventory[i].type == WEAPON) {
            printf("\n %d %s \n ", i, player->inventory[i].weapon.name);
        }
    }
    res = scanf("%d", &choice);
    if (player->inventory[choice].type != WEAPON) {
        printf("Saisie incorrecte veuillez saisir une arme de la liste. ");
        weaponChoice(player);
    } else {
        player->currentWeapon = player->inventory[choice];
        printf(" \n ARME EQUIPEE :  %s \n ", player->currentWeapon.weapon.name);
    }
    return player->currentWeapon.weapon;
}

//AFFICHAGE DE LA VIE DU PERSO ET DU MONSTRE
void printHealth(Player *player, Monster *monster) {
    player->currentWeapon = player->inventory[0];
    printf("\n PLAYER LIFE : %f \n ", player->currentHealthPoints);
    printf("\n MONSTER LIFE : %d \n", monster->currentLife);
    //DEBUG
    printf("\n PLAYER XP : %d \n ", player->currentExperience);
}

//ATTAQUE DU JOUEUR SUR UN MONSTRE
void attackPlayer(Player *player, Monster *monster, Weapon *weapon) {
    if (weapon->actual_durabiulity != 0) {
        switch (weapon->id) {
            case 1:
                monster->currentLife -= 1;
                weapon->actual_durabiulity -= 1;
                break;
            case 8:
                monster->currentLife -= 2;
                weapon->actual_durabiulity -= 1;
                break;

            case 9:
                monster->currentLife -= 3;
                weapon->actual_durabiulity -= 1;
                break;

            case 10:
                monster->currentLife -= 4;
                weapon->actual_durabiulity -= 1;
                break;

            case 19:
                monster->currentLife -= 5;
                weapon->actual_durabiulity -= 1;
                break;

            case 20:
                monster->currentLife -= 7;
                weapon->actual_durabiulity -= 1;
                break;

            case 21:
                monster->currentLife -= 10;
                weapon->actual_durabiulity -= 1;
                break;

            case 30:
                monster->currentLife -= 10;
                weapon->actual_durabiulity -= 1;
                break;

            case 31:
                monster->currentLife -= 15;
                weapon->actual_durabiulity -= 1;
                break;

            case 32:
                monster->currentLife -= 20;
                weapon->actual_durabiulity -= 1;
                break;
            default:
                break;
        }
    } else {
        printf("Votre arme n'est plus utilisable allez la réparer ou utilisez en une autre !");
    }
}

//ATTAQUED DU MONSTRES SUR LE JOUEUR
void attackMonster(Player *player, Monster *monster) {
    int idMonster = 0;
    idMonster = monster->id;
    int armorId = 0;
    for (int i = 0; i < 10; i++) {
        if (player->inventory[i].type == 5) {
            armorId = player->inventory[i].armor.id;

        }
    }
    if (player->currentHealthPoints != 0) {
        switch (armorId) {
            case 0 :
                player->currentHealthPoints -= monster->damage;
                break;

            case 11 :
                player->currentHealthPoints = player->currentHealthPoints - (monster->damage * 0.9);
                break;

            case 22 :
                player->currentHealthPoints -= (monster->damage * 0.8);
                break;

            case 33 :
                player->currentHealthPoints -= (monster->damage * 0.6);
                break;

            default:
                break;
        }
    } else {
        player->currentExperience += monster->experience;
    }
}

//UTILISATION DE SOINS
void healPlayer(Player *player) {
    int hpToRestore = 0;
    int choice = 0;
    int indexHP1 = 0;
    bool heal1 = false;
    int indexHP2 = 0;
    bool heal2 = false;
    int indexHP3 = 0;
    bool heal3 = false;
    bool verifHeal = true;
    int verifHealExist = 0;
    hpToRestore = ((player->maxHealthpoints) - (player->currentHealthPoints));
    for (int i = 0; i < 10; i++) {
        if (player->inventory[i].type == 4) {
            if (player->inventory[i].heal.id == 15) {
                indexHP1 = i;
                heal1 = true;
            }

            if (player->inventory[i].heal.id == 26) {
                indexHP2 = i;
                heal2 = true;
            }

            if (player->inventory[i].heal.id == 34) {
                indexHP3 = i;
                heal3 = true;
            }

            printf("\n %d - %s", player->inventory[i].heal.id, player->inventory[i].heal.name);
            scanf("%d", &choice);
            verifHealExist = 1;
        }
    }

    if (choice == 15 && heal1 == false) {
        verifHeal = false;
    }
    if (choice == 26 && heal2 == false) {
        verifHeal = false;
    }
    if (choice == 34 && heal3 == false) {
        verifHeal = false;
    }

    if(verifHealExist == 0){
        printf("Vous n'avez pas de potion !");
    }
    if (verifHeal != false && verifHealExist != 0) {
        switch (choice) {
            case 15:
                if (player->inventory[indexHP1].heal.quantity != 0) {
                    player->currentHealthPoints += 30;
                    player->inventory[indexHP1].heal.quantity -= 1;
                    if (player->inventory[indexHP1].heal.quantity == 0) {
                        deleteElementInventory(player->inventory,
                                               (sizeof(player->inventory) / sizeof(player->inventory[0])),
                                               player->inventory[indexHP1].heal.id);
                    }
                    printf("\n +30 Hp \n");
                } else {
                    printf("\n Vous ne pouvez pas utiliser de potion de soins \n");
                }
                break;

            case 26 :
                if (player->inventory[indexHP2].heal.quantity != 0) {
                    player->currentHealthPoints += 80;
                    player->inventory[indexHP2].heal.quantity -= 1;
                    printf("\n +80 Hp \n");
                    if (player->inventory[indexHP2].heal.quantity == 0) {
                        deleteElementInventory(player->inventory,
                                               (sizeof(player->inventory) / sizeof(player->inventory[0])),
                                               player->inventory[indexHP2].heal.id);
                    }
                } else {
                    printf("\n Vous ne pouvez pas utiliser de potion de soins \n");
                }
                break;

            case 34 :
                if (player->inventory[indexHP3].heal.quantity != 0) {
                    player->currentHealthPoints += 200;
                    player->inventory[indexHP3].heal.quantity -= 1;
                    printf("\n +200 Hp \n");
                    if (player->inventory[indexHP3].heal.quantity == 0) {
                        deleteElementInventory(player->inventory,
                                               (sizeof(player->inventory) / sizeof(player->inventory[0])),
                                               player->inventory[indexHP3].heal.id);
                    }
                } else {
                    printf("\n Vous ne pouvez pas utiliser de potion de soins \n");
                }

                break;

            default:
                break;
        }
    }

    if (player->currentHealthPoints > player->maxHealthpoints) {
        player->currentHealthPoints = player->maxHealthpoints;
    }
}

//LANCEMENT DU COMBAT
int combat(Player *player, Monster *monster) {
    srand(time(NULL));
    int result = 0;
    int aleat;
    printf("\n ATTENTION UN MONSTRE AU LOIN !!! \n");

    while ((player->currentHealthPoints > 0) && (monster->currentLife > 0)) {
        printf("Que souahitez vous faire ? \n 1 - Combattre \n 2 - Se Soigner \n 3 - Fuir \n");
        int choix;
        scanf("%d", &choix);
        Weapon w;
        switch (choix) {
            case 1 :
                w = weaponChoice((player));
                attackPlayer(player, monster, &w);
                attackMonster(player, monster);
                //DEBUG
                printHealth(player, monster);

                if (monster->currentLife <= 0) {
                    printf("\n Vous avez tué le monstre \n");
                    player->currentExperience += monster->experience;
                    printf("\n +%d XP \n", monster->experience);
                    if (player->currentExperience >= player->maxExperience) {
                        int ajustXp = player->currentExperience - player->maxExperience;
                        addLevel(player);
                        player->currentExperience += ajustXp;
                        monster->currentLife = monster->maxLife;
                    }
                    return 1;
                }
                if (player->currentHealthPoints <= 0) {
                    printf("\n Vous êtes mort ! \n ");
                    monster->currentLife = monster->maxLife;
                    return 2;

                }
                break;

            case 2:
                if (player->currentHealthPoints == player->maxHealthpoints) {
                    printf("VOS PV SONT AUX MAXIMUM");
                } else {
                    healPlayer(player);
                }
                break;

            case 3:
                aleat = rand() % 100;
                if (aleat <= 33) {
                    printf("C'est dommage tu as prefere fuire\n");
                    monster->currentLife = monster->maxLife;
                    return 0;

                } else {
                    printf("Dommage pas cette fois ci reste au combat\n");
                    attackMonster(player, monster);
                }
                break;

            default:
                break;
        }
    }
    return result;
}