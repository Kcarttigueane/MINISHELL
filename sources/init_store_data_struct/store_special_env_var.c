/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** store_special_env_var.c
*/

#include "lib.h"
#include "mysh.h"

int get_path_line(char **envp, char *get_pathname, int n)
{
    for (int i = 0; envp[i] != NULL; i++)
        if (my_strncmp(envp[i], get_pathname, n) == 0)
            return i;
    return 84;
}

void store_special_env_variables(special_env_var_t *special_var, char **envp)
{
    int path_pos = get_path_line(envp, "PATH", 4);
    int home_dir_pos = get_path_line(envp, "HOME", 4);
    int len = ((my_strlen(envp[home_dir_pos])));

    special_var->PATH = my_strtok(envp[path_pos] + 5, ':');
    special_var->HOME_DIRECTORY = malloc(sizeof(char) * (len + 1));
    my_strcpy(special_var->HOME_DIRECTORY, envp[home_dir_pos] + 5);
}
