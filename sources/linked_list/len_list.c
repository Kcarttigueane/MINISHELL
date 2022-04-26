/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** len_list.c
*/

#include <unistd.h>
#include "data_struct.h"

int get_len_list(node_t **head)
{
    if (*head == NULL) {
        write (1, "len : 0\n", 9);
        return 0;
    }
    int len_counter = 0;
    for (node_t *temp = *head;  temp != NULL;
    temp = temp->next, len_counter++);
    return len_counter;
}
