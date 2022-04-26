/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** my_strncmp.c
*/

#include "lib.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
        if (s1[i] != s2[i])
            return 1;
    return 0;
}
