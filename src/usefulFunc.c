//
// Created by lucas on 23/10/2021.
//

#include "usefulFunc.h"

int **print2DIntTab(int **tab, int x, int y) {

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}