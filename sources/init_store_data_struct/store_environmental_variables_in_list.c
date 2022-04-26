/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** store_environmental_variables_in_list.c
*/

#include "lib.h"
#include "mysh.h"

void store_env_in_list(node_t **head, char **envp)
{
    for (int i = 0; envp[i]  != NULL; i++)
        end_push(head, envp[i]);
}
