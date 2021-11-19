//
// Created by LBZ on 19/11/2021.
//

#include "../include/save.h"


savefile(int * mapSize,int *** map_list){

    File * file = fopen("saveFile.txt","a");

    fprintf( file, "===MAP===");

    for (int i = 0; i < 3; ++i) {
        fprintf( file, "--ZONE%d--",i);
        for (int j = 0; j < mapSize[i]; ++j) {
            fprintf(file,"\n");
            for (int k = 0; k <  mapSize[i]; ++k) {
                fprintf(file, "%d ",map_list[i][j][k])
            }
        }
    }


    fprint
}
