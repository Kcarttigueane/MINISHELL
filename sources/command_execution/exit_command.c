/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** exit_command.c
*/

#include "lib.h"
#include "mysh.h"

void is_exit_command(char *command, input_t *input_stream,
special_env_var_t *special_var, node_t **head)
{
    if (my_strcmp(command, "exit") == 0) {
        free_all_stuff(input_stream, special_var, head, 1);
        exit(0);
    }
}
