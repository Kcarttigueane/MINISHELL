/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** free_map.c
*/

#include <stdlib.h>

void free_world_array(char **map)
{
    for (int i = 0; map[i] != NULL; i++)
        free(map[i]);
    free(map);
}
