/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** is_first_char_letter.c
*/

#include "lib.h"

int is_first_char_letter(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return OK;
    return NOT_OK;
}
