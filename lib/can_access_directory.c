/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** can_access_directory.c
*/

#include "lib.h"

int can_access_directory(char *directory_name)
{
    if (access(directory_name, F_OK | X_OK) == -1)
        return -1;
    return 0;
}
