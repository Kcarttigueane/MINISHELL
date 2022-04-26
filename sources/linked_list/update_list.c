/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** update_list.c
*/

#include "lib.h"
#include "mysh.h"

void update_linked_list(node_t **head, int pos, char *oldpwd)
{
    if ((pos < 1) || (*head == NULL))
        return;
    node_t *current = *head;
    char *buff = NULL;
    buff = getcwd(buff, 1024);
    char *final = my_strcat(oldpwd, buff);
    free(buff);
    if (pos == 1) {
        current = current->next;
        free(current->str);
        current->str = malloc(sizeof(char) * (my_strlen(final) + 1));
        current->str = my_strncpy(current->str, final, (my_strlen(final) + 1));
        free(final);
        return;
    }
    for (; pos != 1; current = current->next, pos--);
    free(current->str);
    current->str = malloc(sizeof(char) * (my_strlen(final) + 1));
    current->str = my_strncpy(current->str, final, (my_strlen(final) + 1));
    free(final);
}
