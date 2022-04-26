/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** my_strtok.c
*/

#include "lib.h"

int get_len_word(char *str, const char delimiter)
{
    int i;
    for (i = 0; str[i] != delimiter && i < my_strlen(str); i++);
    return i;
}

int get_number_of_row(char const *str, const char delimiter)
{
    int row_count = 0;

    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] != delimiter && (str[i + 1] == delimiter ||
        str[i + 1] == '\0'))
            row_count++;
    return row_count;
}

char *remove_tab(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '\t')
            str[i] = ' ';
    return str;
}

char **my_strtok(char *str, const char delimiter)
{
    str = remove_tab(str);
    int row = get_number_of_row(str, delimiter);
    int len_string = my_strlen(str);
    int k = 0;
    char **final = malloc(sizeof(char *) * (row + 1));

    for (int i = 0; i < len_string && k < row; i++)
        if (str[i] != delimiter) {
            int len = get_len_word(str + i, delimiter);
            final[k] = malloc(sizeof(char) * (len + 1));
            my_strncpy(final[k], str + i, len);
            final[k][len] = '\0';
            i += len;
            k++;
        }
    final[row] = NULL;
    return final;
}
