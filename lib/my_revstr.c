/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** my_revstr.c
*/

int my_strlen(const char *str);

char *my_revstr(char *str)
{
    int i = 0;
    int size = my_strlen(str) - 1;
    char swap;

    while (i < size) {
        swap = str[i];
        str[i] = str[size];
        str[size] = swap;
        i++;
        size--;
    }
    return str;
}
