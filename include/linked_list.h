/*
** EPITECH PROJECT, 2021
** Sans titre(Espace de travail)
** File description:
** linked_list.h
*/

#ifndef LINKED_LIST_H_
    #define LINKED_LIST_H_

    #include "data_struct.h"

// PUSH --> function prototypes :

void end_push(node_t **head, char *str);

// PRINT LIST --> function prototypes :

void print_list(node_t **head);
void print_list_index(node_t **head);

// GET LEN LIST --> function prototypes :

int get_len_list(node_t **head);

// GET LEN STRING OF A NODE :

int get_len_string_of_a_node(char *command_args, node_t **head);

// GET STRING OF A NODE :

char *get_string_of_a_node(char *command_args, node_t **head);

// SEARCH PATH VARIABLE IN THE LIST :

int get_len_env_variables(char *str);
int search_in_list(char *command_args, node_t **head);

int search_in_list_for_cd_command(char *command_args, node_t **head);

// UPDATE OLDPWD AND PWD IN THE LIST :

void update_linked_list(node_t **head, int pos, char *oldpwd);

// FREE --> function prototypes :

void free_last_node(node_t **head);
void free_list(node_t **head);

void free_node_at_position(node_t **head, int index_position);

// STORE IN LIST --> function prototypes :

void store_env_in_list(node_t **head, char **envp);

#endif/* LINKED_LIST_H_ */
