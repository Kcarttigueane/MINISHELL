/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** get_number_row_world_array.c
*/

#include <stdlib.h>

int get_nb_row(char **a)
{
    int i = 0;
    for (; a[i] != NULL; i++);
    return (i - 1);
}
