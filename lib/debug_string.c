/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** debug_string.c
*/

#include "bonus.h"
#include "lib.h"

void debug_string(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        write(1,"str[", 5);
        write(1, RED, SIZE_COLOUR);
        my_put_nbr(i);
        write(1, RESET, SIZE_RESET);
        write(1,"] = '", 5);
        write(1, YELLOW, SIZE_COLOUR);
        write(1, &str[i], 1);
        write(1, RESET, SIZE_RESET);
        write(1, "'\n", 2);
    }
}
