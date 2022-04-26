/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** env_command.c
*/

#include "mysh.h"
#include "lib.h"
#include "execute_command.h"

int is_env_command(char **command_line, node_t **head)
{
    int size = get_size_world_array(command_line);

    if (size == 1 && (my_strcmp(command_line[0], "env") == 0)) {
        print_list(head);
        free_world_array(command_line);
        return true;
    }
    return false;
}
