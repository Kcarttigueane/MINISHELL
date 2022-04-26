/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** unsetenv_command.c
*/

#include "lib.h"
#include "mysh.h"

int is_unsetenv_command_part_two(char **command_line, node_t **head,
int size_world_array)
{
    int index_pos = -1;

    if (size_world_array > 1 &&
    (my_strcmp(command_line[0], "unsetenv") == 0)) {
        for (int i = 1; i < size_world_array; i++)
            if ((index_pos = search_in_list(command_line[i], head)) >= 0)
                break;
        if (index_pos == -1) {
            free_world_array(command_line);
            return true;
        }
        if (index_pos >= 0) {
            free_world_array(command_line);
            free_node_at_position(head, index_pos);
            return true;
        }
    }
    return false;
}

int is_unsetenv_command(char **command_line, node_t **head)
{
    int size_world_array = get_size_world_array(command_line);

    if (size_world_array == 1 && (my_strcmp(command_line[0],
    "unsetenv") == 0)) {
        free_world_array(command_line);
        write (1, "unsetenv: Too few arguments.\n", 30);
        return true;
    }
    return (is_unsetenv_command_part_two(command_line , head,
    size_world_array));
}
