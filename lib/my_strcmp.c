/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** my_strcmp.c
*/

#include <stdlib.h>

int my_strcmp (char const * s1 , char const *s2)
{
    int i = 0;

    if (s1 == NULL)
        return -1;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
        i++;
    return s1[i] - s2[i];
}
