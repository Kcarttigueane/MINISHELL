/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** free_node.c
*/

#include "lib.h"
#include "data_struct.h"

void free_last_node(node_t **head)
{
    if (*head == NULL) {
        write (1, "Can't free node : list is empty\n", 33);
        return;
    }
    else if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node_t *temp = *head;
    node_t *temp2 = *head;
    for (; temp->next != NULL; temp2 = temp, temp = temp->next);
    temp2->next = NULL;
    free(temp);
    temp = NULL;
}
