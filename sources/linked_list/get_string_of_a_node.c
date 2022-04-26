/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** get_string_of_a_node.c
*/

#include "lib.h"
#include "data_struct.h"

char *get_string_of_a_node(char *command_args, node_t **head)
{
    if (head == NULL) {
        write(1, "List is empty\n", 15);
        return NULL;
    }
    node_t *temp = *head;
    int i = 0;

    for (int len_ca = my_strlen(command_args);
    temp != NULL; temp = temp->next, i++)
        if (my_strncmp(command_args, temp->str, (len_ca - 1)) == 0)
            return (temp->str);
    return NULL;
}
