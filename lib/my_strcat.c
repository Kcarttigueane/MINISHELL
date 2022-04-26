/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** my_strcat.C
*/

#include "lib.h"

char *my_strcat(char *part_one, char *part_two)
{
    int sum_len = my_strlen(part_one) + my_strlen(part_two);
    char *sum_string = malloc(sizeof(char) * (sum_len + 1));
    int i;
    int j = 0;

    for (i = 0; part_one[i] != '\0'; i++)
        sum_string[i] = part_one[i];
    for (j = 0; part_two[j] != '\0'; j++)
        sum_string[i + j] = part_two[j];
    sum_string[i + j] = '\0';
    return sum_string;
}
