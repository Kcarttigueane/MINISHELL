/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** search_in_list.c
*/

#include "lib.h"
#include "mysh.h"

int get_len_env_variables(char *str)
{
    int i = 0;
    for (; str[i] != '='; i++);
    return i;
}

int search_in_list(char *command_args, node_t **head)
{
    if (head == NULL) {
        write(1, "List is empty\n", 15);
        return -1;
    }
    node_t *temp = *head;
    int i = 0;

    for (int len_ca = my_strlen(command_args); temp != NULL;
    temp = temp->next, i++)
        if (my_strncmp(command_args, temp->str, (len_ca - 1)) == 0 &&
        (get_len_env_variables(temp->str) == len_ca))
            return (i + 1);
    return -1;
}

int search_in_list_for_cd_command(char *command_args, node_t **head)
{
    if (head == NULL) {
        write(1, "List is empty\n", 15);
        return -1;
    }
    node_t *temp = *head;
    int i = 0;

    for (int len_ca = my_strlen(command_args); temp != NULL;
    temp = temp->next, i++)
        if (my_strncmp(command_args, temp->str, (len_ca - 1)) == 0)
            return (i + 1);
    return -1;
}
