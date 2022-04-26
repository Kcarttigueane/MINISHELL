/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** my_strlen.c
*/

int my_strlen(const char *str)
{
    int i = 0;
    for (; str[i] != '\0'; i++);
    return i;
}
