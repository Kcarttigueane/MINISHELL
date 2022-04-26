/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** free_node_at_position.c
*/

#include "lib.h"
#include "mysh.h"

void free_node_at_position(node_t **head, int position)
{
    if (position < 1)
        return;
    if (*head == NULL)
        return;
    node_t *previous = *head;
    node_t *current = *head;
    if (position == 1) {
        *head = current->next;
        free(current);
        current = NULL;
        return;
    }
    for (; position != 1; previous = current,
    current = current->next, position--);
    previous->next = current->next;
    free(current->str);
    free(current);
    current = NULL;
}
