/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** print_list.c
*/

#include "lib.h"
#include "mysh.h"

void print_list(node_t **head)
{
    if (*head == NULL) {
        write(1, "Can't print : list\n", 20);
        return;
    }
    node_t *temp = *head;
    for (; temp != NULL; temp = temp->next) {
        write(1, temp->str, my_strlen(temp->str));
        write(1, "\n", 1);
    }
}
