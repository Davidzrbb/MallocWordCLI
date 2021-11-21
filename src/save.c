//
// Created by LBZ on 19/11/2021.
//

#include "../include/save.h"

int saveFile(int * mapSize,int *** map_list, Player *player){

    FILE* file = fopen("saveFile.txt","w");

    fprintf( file, "===MAP===\n");

    for (int i = 0; i < 3; ++i) {
        fprintf( file, "--ZONE%d--",i);
        for (int j = 0; j < mapSize[i]; ++j) {
            fprintf(file,"\n");
            for (int k = 0; k <  mapSize[i]; ++k) {
                fprintf(file, "%d ",map_list[i][j][k]);
            }
        }
    }

    fclose(file);
    return 2;
}
