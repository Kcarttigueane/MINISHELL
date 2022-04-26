/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** free_data_struct.c
*/

#include "lib.h"
#include "data_struct.h"
#include "mysh.h"

void free_all_stuff(input_t *input_stream,
special_env_var_t *special_var, node_t **head, size_t i)
{
    free(input_stream->input_buffer);
    if (i == 1)
        free_world_array(input_stream->command_line);
    free_list(head);
    free_world_array(special_var->PATH);
    free(special_var->HOME_DIRECTORY);
    free(special_var);
    free(input_stream);
}
