/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** end_push.c
*/

#include "lib.h"
#include "data_struct.h"

void end_push(node_t **head, char *str)
{
    node_t *new_node = malloc(sizeof(node_t));

    new_node->str = malloc(sizeof(char) * my_strlen(str) + 1);
    my_strcpy(new_node->str, str);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t *temp = *head;
    for (; temp->next != NULL; temp = temp->next);
    temp->next = new_node;
}
