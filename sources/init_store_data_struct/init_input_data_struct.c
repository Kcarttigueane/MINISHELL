/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** init_input_data_struct.c
*/

#include "mysh.h"

void init_input_data_struct(input_t *input_stream)
{
    input_stream->inputlen = 10;
    input_stream->input_buffer = malloc(sizeof(char) * input_stream->inputlen);
    input_stream->command_line = NULL;
}
