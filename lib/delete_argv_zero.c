/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** delete_argv_zero.c
*/

#include "lib.h"

char **delete_argv_zero(char **argv)
{
    for (int i = 0; argv[i] != NULL; i++)
        argv[i] = argv[i + 1];
    return argv;
}
