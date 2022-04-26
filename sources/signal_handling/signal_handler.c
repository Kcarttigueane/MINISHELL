/*
** EPITECH PROJECT, 2021
** FINAL-MINISHELL
** File description:
** signal_handler.c
*/

#include <unistd.h>

void handle_signal (__attribute__((unused))int signal)
{
    write (1, "\n$> ", 5);
}
