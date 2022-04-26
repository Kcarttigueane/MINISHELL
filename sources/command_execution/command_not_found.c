/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** command_not_found.c
*/

#include "lib.h"

void write_command_not_found(char *command)
{
    write (1, command, my_strlen(command));
    write (1, ": Command not found.\n", 22);
}
