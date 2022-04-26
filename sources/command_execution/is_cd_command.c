/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** is_cd_command.c
*/

#include "lib.h"
#include "mysh.h"

int cd_old_directory(input_t *input_stream, node_t **head,
special_env_var_t *special_var, int size)
{
    (void) special_var;
    if ((size == 2) && (my_strcmp(input_stream->command_line[1], "-") == 0)) {
        int len = get_len_string_of_a_node("OLDPWD=", head);
        char *save_old_pwd = malloc(sizeof(char) * (len + 1));
        my_strcpy(save_old_pwd, get_string_of_a_node("OLDPWD=", head) + 7);
        int old_pwd_position = search_in_list_for_cd_command("OLDPWD=", head);
        update_linked_list(head, old_pwd_position, "OLDPWD=");
        chdir(save_old_pwd);
        free(save_old_pwd);
        return true;
    }
    return false;
}

void part_one_cd_home_then_directory(input_t *input_stream,
special_env_var_t *special_var, char *last_concate)
{
    if (is_directory(last_concate) == NOT_A_DIRECTORY) {
        write (1, special_var->HOME_DIRECTORY,
        my_strlen(special_var->HOME_DIRECTORY));
        write (1, "/", 1);
        write (1, input_stream->command_line[1] + 2,
        my_strlen(input_stream->command_line[1] + 2));
        write (1, ": No such file or directory.\n", 30);
    }
}

void part_two_cd_command_home_then_directory(input_t *input_stream,
node_t **head, special_env_var_t *special_var, char *last_concate)
{
    if (is_directory(last_concate) == DIRECTORY) {
        int old_pwd_position = search_in_list_for_cd_command("OLDPWD=", head);
        update_linked_list(head, old_pwd_position, "OLDPWD=");
        char *move = NULL;
        for (; my_strcmp(getcwd(move, 1024), special_var->HOME_DIRECTORY) != 0;
        chdir(".."), getcwd(move, 1024));
        chdir(input_stream->command_line[1] + 2);
    }
}

int cd_home_then_directory(input_t *input_stream, node_t **head,
special_env_var_t *special_var, int size)
{
    if ((size = 2) &&
    (my_strncmp(input_stream->command_line[1], "~/", 2) == 0) &&
    (my_strlen(input_stream->command_line[1] + 2) != 0)) {
        int len = my_strlen(special_var->HOME_DIRECTORY);
        char *copy_home = malloc(sizeof(char) * (len + 1));
        my_strcpy(copy_home, special_var->HOME_DIRECTORY);
        char *first_concate = my_strcat(copy_home, "/");
        char *last_concate = my_strcat(first_concate,
        (input_stream->command_line[1] + 2));
        part_one_cd_home_then_directory(input_stream,
        special_var, last_concate);
        part_two_cd_command_home_then_directory(input_stream, head,
        special_var, last_concate);
        free(first_concate);
        free(last_concate);
        free(copy_home);
        return true;
    }
    return (cd_old_directory(input_stream, head, special_var, size));
}

int cd_good_path(input_t *input_stream, node_t **head,
special_env_var_t *special_var, int size)
{
    if ((size == 2) &&
    ((is_directory(input_stream->command_line[1]) == DIRECTORY))) {
        int old_pwd_position = search_in_list_for_cd_command("OLDPWD=", head);
        update_linked_list(head, old_pwd_position, "OLDPWD=");
        if (can_access_directory(input_stream->command_line[1]) == -1) {
            write (1, input_stream->command_line[1],
            my_strlen(input_stream->command_line[1]));
            write (1, ": Permission denied.\n", 22);
            return true;
        }
        if (chdir(input_stream->command_line[1]) == -1) {
            perror("cd failed");
        }
        return true;
    }
    return (cd_home_then_directory(input_stream, head, special_var, size));
}

int cd_wrong_path(input_t *input_stream, node_t **head,
special_env_var_t *special_var, int size)
{
    if ((size = 2) &&
    ((is_directory(input_stream->command_line[1]) == NOT_A_DIRECTORY)) &&
    ((my_strncmp(input_stream->command_line[1], "~/", 2) != 0)) &&
    (my_strcmp(input_stream->command_line[1], "-") != 0)) {
        write(1, input_stream->command_line[1],
        my_strlen(input_stream->command_line[1]));
        write(1, ": Not a directory.\n", 20);
        return true;
    }
    return cd_good_path(input_stream, head, special_var, size);
}

int cd_HOME_DIRECTORY(input_t *input_stream, node_t **head,
special_env_var_t *special_var, int size)
{
    char *move = NULL;

    if (size == 1 ||
    (size == 2 && my_strcmp (input_stream->command_line[1], "~") == 0) ||
    (size == 2 && my_strcmp (input_stream->command_line[1], "$HOME") == 0) ||
    (size == 2 && my_strncmp(input_stream->command_line[1], "~/", 2) == 0 &&
    my_strlen(input_stream->command_line[1]) == 2)) {
        int old_pwd_position = search_in_list_for_cd_command("OLDPWD=", head);
        update_linked_list(head, old_pwd_position, "OLDPWD=");
        for (; my_strcmp(getcwd(move, 1024), special_var->HOME_DIRECTORY) != 0;
        chdir(".."), getcwd(move, 1024));
        free(move);
        return true;
    }
    return (cd_wrong_path(input_stream, head, special_var, size));
}

int cd_too_many_arguments(input_t *input_stream, node_t **head,
special_env_var_t *special_var, int size)
{
    if (size > 2) {
        write (1, "cd: Too many arguments.\n", 25);
        return true;
    }
    return (cd_HOME_DIRECTORY(input_stream, head, special_var, size));
}

int is_cd_command(input_t *input_stream, special_env_var_t *special_var,
node_t **head)
{
    int size_world_array = get_size_world_array(input_stream->command_line);

    if (my_strcmp(input_stream->command_line[0], "cd") == 0) {
        if ((cd_too_many_arguments(input_stream, head, special_var,
        size_world_array)) == true) {
            int pwd_position = search_in_list_for_cd_command("PWD=", head);
            update_linked_list(head , pwd_position, "PWD=");
            free_world_array(input_stream->command_line);
            return true;
        }
    }
    return false;

}
