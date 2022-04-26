/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** free_string.c
*/

#include "stdlib.h"

void free_string(char *str)
{
    if (str == NULL)
        return;
    free(str);
}
