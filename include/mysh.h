/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** mysh.h
*/

#ifndef MINI_SHELL_H_
    #define MINI_SHELL_H_

    #include <sys/types.h>
    #include <dirent.h>
    #include <sys/stat.h>
    #include <string.h>
    #include <sys/wait.h>
    #include <sys/time.h>
    #include <sys/resource.h>
    #include <signal.h>
    #include <errno.h>

    #include "data_struct.h"

// get input :

void get_input(input_t *input_stream, special_env_var_t *special_var,
node_t **head);
void remove_backslash_n_getline(input_t *input);

// SIGNAL HANDLER (CRTL + C) :

void handle_signal(__attribute__((unused))int signal);

// INIT OR STORE IN DATA STRUCT :

void init_input_data_struct(input_t *input_stream);
void store_env_in_list(node_t **head, char **envp);

int get_path_line(char **envp, char *get_pathname, int n);
void store_special_env_variables(special_env_var_t *special_var, char **envp);

// FREE DATA STRUCT :

void free_all_stuff(input_t *input_stream, special_env_var_t *special_var,
node_t **head, size_t i);

#endif/* !MINI_SHELL_H_ */
