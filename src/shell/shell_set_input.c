/*
** EPITECH PROJECT, 2024
** shell_set_input.c
** File description:
** shell_set_input.c
*/

#include "my.h"

int shell_set_input(shell_t *shell, char *input)
{
    shell->user_input = input;
    return 0;
}
