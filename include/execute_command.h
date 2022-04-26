/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** execute_command.h
*/

#ifndef EXECUTE_COMMAND_H_
    #define EXECUTE_COMMAND_H_

// include .h files :

    #include "mysh.h"

// EXIT command :

void is_exit_command(char *command, input_t *input_stream,
special_env_var_t *special_var, node_t **head);

// ENV command :

int is_env_command(char **command_line, node_t **head);

// SETENV command :

int is_setenv_command_part_one(char **command_line, node_t **head);
int is_setenv_command_part_two(char **command_line, node_t **head, int size);
int is_setenv_command_part_three(char **command_line, node_t **head, int size);

// UNSETENV command :

int is_unsetenv_command(char **command_line, node_t **head);
int is_unsetenv_command_part_two(char **command_line,
node_t **head, int size_world_array);

// CD command :

int is_cd_command(input_t *input_stream,
special_env_var_t *special_var, node_t **head);

int cd_home_directory(input_t *input_stream, node_t **head,
special_env_var_t *special_var, int size);
int cd_wrong_path(input_t *input_stream, node_t **head,
special_env_var_t *special_var, int size);
int cd_good_path(input_t *input_stream, node_t **head,
special_env_var_t *special_var, int size);
int cd_home_then_directory(input_t *input_stream, node_t **head,
special_env_var_t *special_var, int size);
void part_one_cd_home_then_directory(input_t *input_stream,
node_t **head, special_env_var_t *special_var, char *last_concate);
void part_two_cd_command_home_then_directory(input_t *input_stream,
node_t **head, special_env_var_t *special_var, char *last_concate);
int cd_old_directory(input_t *input_stream, node_t **head,
special_env_var_t *special_var, int size);

// SYSTEM COMMAND :

    #define IN_THE_DIRECTORY 1
    #define OUT_THE_DIRECTORY 0

int is_command_inside_path_dir(char *directory, char *command);
char *look_in_path(char **command_line, char **PATH);
char *check_all_path_directory(char **PATH, char *command);
char **create_new_command_line(char **command_line,
char *in_which_path_directory, char *input_buffer);
int is_system_command_executed_part_one(char **command_line,
char **PATH, char *input_buffer);
int is_system_command_executed_part_two(char **command_line,
char *input_buffer, char *get_location);
int is_system_command(input_t *input_stream, char **PATH);

// UNKNOWN COMMAND :

void write_command_not_found(char *command);

#endif/* EXECUTE_COMMAND_H_ */
