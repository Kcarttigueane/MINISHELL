/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** my_str_n_cpy.c
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i = 0; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0';
    return dest;
}
