/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** get_input.c
*/

#include "mysh.h"
#include "lib.h"

void remove_backslash_n_getline(input_t *input)
{
    int len = my_strlen(input->input_buffer) - 1;
    input->input_buffer[len] = '\0';
}

void get_input(input_t *input_stream, special_env_var_t *special_var,
node_t **head)
{
    write (1 , BLUE, SIZE_COLOUR);
    if (isatty(0) == 1)
        write (1, "$> ", 3);
    write(1, RESET, SIZE_RESET);
    int return_getline_value = getline(&input_stream->input_buffer,
    &input_stream->inputlen, stdin);
    if (return_getline_value == EOF) {
        free_all_stuff(input_stream, special_var, head, 0);
        if (isatty(0) == 1)
            write(1, "exit\n", 5);
        exit(0);
    }
    if (return_getline_value == 1)
        get_input(input_stream, special_var, head);
    remove_backslash_n_getline(input_stream);
}
