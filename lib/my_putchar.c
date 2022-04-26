/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** my_putchar.c
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
