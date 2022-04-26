/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** get_size_world_array.c
*/

#include "lib.h"

int get_size_world_array(char **world)
{
    int i;
    for (i = 0; world[i] != NULL; i++);
    return i;
}
