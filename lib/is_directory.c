/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** is_directory.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "lib.h"

int is_directory(const char *pathname)
{
    struct stat st;

    if (stat(pathname, &st) == -1)
        return NOT_A_DIRECTORY;
    if (!(S_ISDIR(st.st_mode)))
        return NOT_A_DIRECTORY;
    return DIRECTORY;
}
