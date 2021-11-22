//
// Created by lucas on 23/10/2021.
//

#include "usefulFunc.h"

void print2DIntTab(int **tab, int x, int y) {

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }

}

void fill_tab(int **tab,int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            tab[i][j]=0;
        }
    }
}

int** malloc2Darray(int size){

    int** table = malloc(sizeof(int*) * size);
    for(int i = 0; i < size; i++){
        table[i] = malloc(sizeof(int) * size);
    }

    return table;
}

void free3Darray(int ***tab, int size, int nb_tab) {
    for (int i = 0; i < nb_tab; ++i) {
        for (int y = 0; y < size; ++y) {
            free(tab[y]);
        }
        free(tab[i]);
    }
    free(tab);
}