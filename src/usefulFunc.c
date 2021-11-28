#include "usefulFunc.h"

void print2DIntTab(int **tab, int x, int y) {

    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    fflush(stdout);
}

void fill_tab(int **tab, int size_line, int size_col) {
    for (int i = 0; i < size_line; ++i) {
        for (int j = 0; j < size_col; ++j) {
            tab[i][j] = 0;
        }
    }
}

int **malloc2Darray(int size_line, int size_col) {

    int **table = malloc(sizeof(int *) * size_line);
    for (int i = 0; i < size_line; i++) {
        table[i] = malloc(sizeof(int) * size_col);
    }

    return table;
}

void free3Darray(int ***tab, int *nb_line, int *nb_col) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0;j < nb_col[i]; ++j) {
            for (int y = 0; y < nb_line[i]; ++y) {
                free(tab[j][y]);
            }
            free(tab[j]);
        }
    }
    free(tab);
}