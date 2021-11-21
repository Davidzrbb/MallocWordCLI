//
// Created by lucas on 28/10/2021.
//

#include "movement.h"

void movement(Player *player, int ***map_list, int ***map_list_cpy, int ***map_list_respawn, PnjLinkedList *stock) {
    int success;
    char direction;
    do{
        printf("%d/%d ",player->coord_y,player->coord_x);
        printf("tu veux aller ou gros tas? (l,r,t,b)");
        direction = getchar();
        printf("%c\n",direction);
        switch (direction) {
            case 'l':
                success= goForward(player, -1, 0, player->actual_map, map_list, map_list_cpy, map_list_respawn, stock);
                break;
            case 'r':
                success= goForward(player, 1, 0, player->actual_map, map_list, map_list_cpy, map_list_respawn, stock);
                break;
            case 't':
                success= goForward(player, 0, -1, player->actual_map, map_list, map_list_cpy, map_list_respawn, stock);
                break;
            case 'b':
                success = goForward(player, 0, 1, player->actual_map, map_list, map_list_cpy, map_list_respawn, stock);
                break;
            default :
                printf("???\n");
                break;
            }
        fflush(stdin);
    } while (success!=2);   //tant que player pas mort ou arret de la partie
    freeMaps(map_list,map_list_cpy,map_list_respawn);
}


int goForward(Player *player, int add_x, int add_y, int id_map, int ***actual_list_map, int ***actual_map_list_cpy,
              int ***actual_map_list_respawn, PnjLinkedList *stock) {

    if(player->coord_y+add_y<0 || player->coord_y+add_y>mapsSize[id_map-1]-1 || player->coord_x+add_x<0 || player->coord_x+add_x>mapsSize[id_map-1]-1){ //verifie bordure map
        printf("pasparla ");
        return 0;
    }
    int next_case = actual_list_map[id_map][player->coord_y+add_y][player->coord_x+add_x];
    int success =1;
     if(next_case>= PLANT1 & next_case <= WOOD3){
       success=collecteRessources(player,next_case);
       if(!success){
           printf("\nvous ne pouvez pas recolter la ressource");
           return 0;
       }
         player->coord_x+=add_x;
         player->coord_y+=add_y;
     } else if(next_case == FREE){
         player->coord_x+=add_x;
         player->coord_y+=add_y;
     } else if(next_case==NPC){
         pnjChoice(player,stock);
     }else if(next_case>=12){
         //succes=interactWithMonster
         if(success == 1){

         }
         player->coord_x+=add_x;
         player->coord_y+=add_y;
     } else if(next_case==PORTAL1_2 || next_case==PORTAL2_3){
         changeMap(player, next_case);
     }
     if(success){
         refresh_map(actual_list_map, actual_map_list_cpy, actual_map_list_respawn, player);
     }
    return success;
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

void refresh_map(int ***list_map, int ***list_map_cpy, int ***list_map_respawn, Player *player) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < mapsSize[i]; ++j) {
            for (int k = 0; k < mapsSize[i]; ++k) {
                if(list_map_respawn[i][j][k]>1){
                    list_map_respawn[i][j][k]--;
                    if(list_map_respawn[i][j][k]==0 && player->coord_x==k && player->coord_y==j){
                        list_map_respawn[i][j][k]=1;
                    } else if(list_map_respawn[i][j][k]==0){
                        list_map[i][j][k]=list_map_cpy[i][j][k];
                    }
                }
            }
        }
    }
}



































