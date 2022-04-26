/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** check_path_for_system_command.c
*/

#include "lib.h"
#include "execute_command.h"

int is_command_inside_path_dir(char *directory, char *command)
{
    DIR *dir = opendir(directory);

    if (dir == NULL) {
        strerror(errno);
        return 84;
    }
    struct dirent *read_struct;
    while ((read_struct = readdir(dir)) != NULL)
        if (my_strcmp(read_struct->d_name, command) == 0) {
            closedir(dir);
            return IN_THE_DIRECTORY;
        }
    closedir(dir);
    return OUT_THE_DIRECTORY;
}

char *check_all_path_directory(char **PATH, char *command)
{
    for (int i = 0; PATH[i] != NULL; i++) {
        struct stat st;
        stat(PATH[i], &st);
        if ((S_ISDIR(st.st_mode)) &&
        (is_command_inside_path_dir(PATH[i], command) == IN_THE_DIRECTORY))
            return PATH[i];
    }
    return NULL;
}
