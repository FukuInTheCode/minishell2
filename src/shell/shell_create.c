/*
** EPITECH PROJECT, 2024
** shell_create.c
** File description:
** shell_create.c
*/

#include "my.h"

shell_t *shell_create(void)
{
    shell_t *shell = malloc(sizeof(shell_t));

    shell->cmds = command_array_create();
    shell->user_input = NULL;
    shell->return_code = 0;
    return shell;
}
