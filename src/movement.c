//
// Created by lucas on 28/10/2021.
//
#include "movement.h"

void movement(Player *player, int ***map_list, int ***map_list_cpy, int ***map_list_respawn) {
    int success;
    char direction;
    do{
        printf("tu veux aller ou gros tas? (l,r,t,b)");
        direction = getchar();
        printf("%c\n",direction);
        switch (direction) {
            case 'l':
                success= goForward(player, -1, 0, map_list[player->actual_map], 0);
                break;
            case 'r':
                success= goForward(player, 1, 0, map_list[player->actual_map], 0);
                break;
            case 't':
                success= goForward(player, 0, 1, map_list[player->actual_map], 0);
                break;
            case 'b':
                success = goForward(player, 0, -1, map_list[player->actual_map], 0);
                break;
            default :
                printf("???\n");
                break;
            }
        fflush(stdin);
    } while (success==2);   //tant que player pas mort ou arret de la partie
}


int goForward(Player *player, int add_x, int add_y, int **actual_map, int id_map) {
    printf("%d/%d ",player->coord_y,player->coord_x);
    int next_case = actual_map[player->coord_y+add_y][player->coord_x+add_x];
    int success;

     if(next_case>= PLANT1 & next_case <= WOOD3){
         //CollectRessouce();
       success = 1;
       if(!success){
           printf("\nvous ne pouvez pas recolter la ressource");
           return 0;
       }
         player->coord_x+=add_x;
         player->coord_x+=add_x;
     } else if(next_case == FREE){
         player->coord_x+=add_x;
         player->coord_y+=add_y;
     } else if(next_case==NPC){
         //interactWithPnj
     }else if(next_case>=12){
         success = 1;//interactWithMonster
         if(success == 1){

         }
         if(!success){
             return 2;
         }
         player->coord_x+=add_x;
         player->coord_x+=add_x;
     } else if(next_case==PORTAL1_2 || next_case==PORTAL2_3){
         changeMap(player, next_case);
     }
    return 1;
}
void changeMap(Player *player, int id_portal){

    if(player->level < 3 && id_portal == -3){
        printf("\nreviens au niveau 3 ");
        return;
    } else if(player->level < 7 && id_portal == -2){
        printf("reviens au niveau 7");
        return;
    }

    if(id_portal==-3 && player->actual_map==0){              //actual map 0 = map1
        player->actual_map=1;  //map1->map2                  //actual map 1 = map2
    } else if (id_portal==-3 && player->actual_map==1){      //actual map 2 = map3
        player->actual_map=0; // map2->map1
    } else if(id_portal==-2 && player->actual_map==2){
        player->actual_map=1; // map3->map2
    } else{
        player->actual_map=2; // map2->map3
    }


    //TODO changer les coordonnées du joueur
}
































