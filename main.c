/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** main.c
*/

#include "mysh.h"
#include "lib.h"
#include "execute_command.h"

void shell_loop(input_t *input_stream, special_env_var_t *special_var,
node_t **head)
{
    init_input_data_struct(input_stream);
    while (1) {
        get_input(input_stream, special_var, head);
        input_stream->command_line =
        my_strtok(input_stream->input_buffer, ' ');
        is_exit_command(input_stream->command_line[0], input_stream,
        special_var, head);
        if (is_env_command(input_stream->command_line, head) == true)
            continue;
        if (is_setenv_command_part_one(input_stream->command_line,
        head) == true)
            continue;
        if (is_unsetenv_command(input_stream->command_line, head) == true)
            continue;
        if (is_cd_command(input_stream, special_var, head) == true)
            continue;
        if (is_system_command(input_stream, special_var->PATH) == true)
            continue;
    }
}

int main(int argc, __attribute__((unused))char **argv, char **envp)
{
    if (argc > 1)
        return 84;
    signal(SIGINT, &handle_signal);
    input_t *input_stream = malloc (sizeof(input_t));
    special_env_var_t *special_var = malloc (sizeof(special_env_var_t));
    node_t *head = NULL;
    store_special_env_variables(special_var, envp);
    store_env_in_list(&head, envp);

    shell_loop(input_stream, special_var, &head);

    free_all_stuff(input_stream, special_var, &head, 1);
    return 0;
}
