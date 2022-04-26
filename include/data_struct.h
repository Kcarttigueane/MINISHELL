/*
** EPITECH PROJECT, 2021
** MINI-SHELL-REPOT
** File description:
** data_struct.h
*/

#ifndef DATA_STRUCT_H_
    #define DATA_STRUCT_H_

    #include <stdlib.h>

typedef struct special_env_var {
    char **PATH;
    char *HOME_DIRECTORY;
}special_env_var_t;

typedef struct env_list {
    char *str;
    struct env_list *next;
}node_t;

typedef struct input_struct {
    char *input_buffer;
    size_t inputlen;
    char **command_line;
}input_t;

typedef enum {
    true,
    false
}boolean;

#endif/* DATA_STRUCT_H_ */
