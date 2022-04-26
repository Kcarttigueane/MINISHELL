/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** lib.h
*/

#ifndef LIB_H_
    #define LIB_H_

// Include libraries :

    #include <stdlib.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>

// Include .h files :

    #include "bonus.h"
    #include "linked_list.h"

// define :

    #define OK 0
    #define NOT_OK 1

// LIB --> function prototypes :

void my_putchar(char c);
int my_strlen(const char *str);
void my_putstr(char *const str);
void my_put_nbr(int nb);
int my_strcmp(const char *a, const char *b);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_itoa(int nb);
char *my_revstr(char *str);
char *my_strcat(char *part_one, char *part_two);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
void modify_string(char **map, int i, int j);
char **delete_argv_zero(char **argv);

int is_first_char_letter(char c);

// WORD_ARRAY --> function prototypes :

int get_size_world_array(char **world);
char **get_map(char *str);
char **remove_n(char **map);
char **malloc_2d_array(int nb_rows, int nb_cols);
void free_world_array(char **map);
void print_map(char **map);
int get_nb_row(char **a);

// DEBUG --> function prototypes :

void debug_string(const char *str);
void debug_world_array(char **world);

// MY_STRTOK --> function prototypes :

int get_len_word(char *str, const char delimiter);
int get_number_of_row(char const *str, const char delimiter);
char **my_strtok(char *str, const char delimiter);

char *remove_tab(char *str);

// CHECK THE ACCESS TO A DIRECTORY :

int can_access_directory(char *directory_name);

// ARGUMENT CHECK :

    #define DIRECTORY 0
    #define NOT_A_DIRECTORY 1

int is_directory(const char *pathname);

// FREE FUNCTIONS :

void free_string(char *str);

#endif/* LIB_H_ */
