/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** my_put_nbr.c
*/

#include <unistd.h>

void my_putchar(char c);

void my_put_nbr(int nb)
{
    if (nb < 0) {
        write(1, "-", 1);
        nb *= -1;
    }
    if (nb >= 10)
        my_put_nbr(nb / 10);
    my_putchar(nb % 10 + 48);
}
