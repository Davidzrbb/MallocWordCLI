//
// Created by lucas on 23/10/2021.
//

#ifndef MALLOC_WORLD_USEFULFUNC_H
#define MALLOC_WORLD_USEFULFUNC_H

#include <stdio.h>
#include <stdlib.h>


void print2DIntTab(int **tab, int x, int y);

void fill_tab(int **tab, int size_line, int size_col);

int** malloc2Darray(int size_line,int size_col);

void free3Darray(int ***tab, int *nb_line);

#endif //MALLOC_WORLD_USEFULFUNC_H
