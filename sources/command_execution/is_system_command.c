/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** is_system_command.c
*/

#include "lib.h"
#include "execute_command.h"

char *look_in_path(char **command_line, char **PATH)
{
    char *in_which_path_directory;
    in_which_path_directory = check_all_path_directory(PATH, command_line[0]);

    if ((in_which_path_directory = check_all_path_directory(PATH,
    command_line[0])) == NULL)
        if (in_which_path_directory == NULL) {
            write_command_not_found(command_line[0]);
            return NULL;
        }
    return in_which_path_directory;
}

char **create_new_command_line(char **command_line,
char *in_which_path_directory, char *input_buffer)
{
    char *first_concate = NULL;
    char *second_concate = NULL;

    first_concate = my_strcat(in_which_path_directory, "/");
    second_concate = my_strcat(first_concate, input_buffer);
    free(first_concate);
    command_line = my_strtok(second_concate, ' ');
    free(second_concate);
    return command_line;
}

int is_system_command_executed_part_two(char **command_line,
char *input_buffer, char *get_location)
{
    pid_t id = fork();
    int status = 0;

    command_line = create_new_command_line(command_line, get_location,
    input_buffer);
    if (id != 0) {
        if (id == -1)
            strerror(errno);
        wait(NULL);
    }
    if (id == 0) {
        if ((status = execve(command_line[0], command_line, NULL)) == (-1))
            strerror(status);
        exit(0);
    }
    free_world_array(command_line);
    return true;
}

int is_system_command_executed_part_one(char **command_line, char **PATH,
char *input_buffer)
{
    char *get_location;
    if ((get_location = look_in_path(command_line, PATH)) == NULL) {
        free(get_location);
        return true;
    }
    return (is_system_command_executed_part_two(command_line, input_buffer,
    get_location));
}

int is_system_command(input_t *input_stream, char **PATH)
{
    if (is_system_command_executed_part_one(input_stream->command_line, PATH,
    input_stream->input_buffer) == true)
        free_world_array(input_stream->command_line);
    return true;
}
