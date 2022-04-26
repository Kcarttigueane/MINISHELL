/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** free_list.c
*/

#include "data_struct.h"
#include "lib.h"

void free_list(node_t **head)
{
    if (*head == NULL) {
        write(1, "Can't free list : list is empty\n", 33);
        return;
    }
    node_t *temp = *head;
    while (temp != NULL) {
        temp = temp->next;
        free ((*head)->str);
        free(*head);
        *head = temp;
    }
}
