/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** print_map.c
*/

#include <unistd.h>
#include <stdlib.h>

int my_strlen(const char *str);

void print_map(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        write(1, map[i], my_strlen(map[i]));
        write(1, "\n", 1);
    }
}
