/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** my_itoa.c
*/

#include <stdlib.h>

char *my_revstr(char *str);

char *my_itoa(int nb)
{
    int i = 0;
    int n = nb;
    char *str = malloc(sizeof(char) * 12);

    if (str == NULL)
        return (NULL);
    if (n == 0)
        str[i++] = '0';
    if (n < 0)
        n = -n;
    while (n > 0) {
        str[i++] = n % 10 + '0';
        n = n / 10;
    }
    if (nb < 0)
        str[i++] = '-';
    str[i] = '\0';
    return (my_revstr(str));
}
