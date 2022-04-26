/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** setenv_command.c
*/

#include "lib.h"
#include "mysh.h"
#include "execute_command.h"

int is_setenv_command_part_three(char **command_line, node_t **head, int size)
{
    char *first_concate = NULL;

    if ((size == 2) && (is_first_char_letter(command_line[1][0]) == OK) &&
    (my_strcmp(command_line[0], "setenv") == 0)) {
        first_concate = my_strcat(command_line[1], "=");
        end_push(head, first_concate);
        free(first_concate);
        free_world_array(command_line);
        return true;
    }
    return false;
}

int is_setenv_command_part_two(char **command_line, node_t **head, int size)
{
    char *first_concate = NULL;
    char *secund_concate = NULL;

    if ((size == 3) && (is_first_char_letter(command_line[1][0]) == OK) &&
    (my_strcmp(command_line[0], "setenv") == 0)) {
        first_concate = my_strcat(command_line[1], "=");
        secund_concate = my_strcat(first_concate, command_line[2]);
        free(first_concate);
        end_push(head, secund_concate);
        free(secund_concate);
        free_world_array(command_line);
        return true;
    }
    return (is_setenv_command_part_three(command_line, head, size));
}

int is_setenv_command_part_one(char **command_line, node_t **head)
{
    int size = get_size_world_array(command_line);
    if (size > 3 && (my_strcmp(command_line[0], "setenv") == 0)) {
        write (1, "setenv: Too many arguments.\n", 29);
        free_world_array(command_line);
        return true;
    }
    if (size == 1 && (my_strcmp(command_line[0], "setenv") == 0)) {
        free_world_array(command_line);
        print_list(head);
        return true;
    }
    if ((size == 3) && (is_first_char_letter(command_line[1][0]) == NOT_OK) &&
    (my_strcmp(command_line[0], "setenv") == 0)) {
        free_world_array(command_line);
        write (1, "setenv: Variable name must begin with a letter.\n", 49);
        return true;
    }
    return (is_setenv_command_part_two(command_line, head, size));
}
