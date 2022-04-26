/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** malloc_2d_array.c
*/

#include "lib.h"
#include <stdlib.h>

char **malloc_2d_array(int nb_rows, int nb_cols)
{
    char **arr_aloc_2d = malloc(sizeof(char *) * (nb_rows + 1));

    if (arr_aloc_2d == NULL)
        return NULL;

    for (int i = 0; i < nb_rows; i++)
        arr_aloc_2d[i] = malloc(sizeof(char) * (nb_cols + 1));
    arr_aloc_2d[nb_rows] = NULL;
    return arr_aloc_2d;
}
