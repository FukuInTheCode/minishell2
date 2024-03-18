/*
** EPITECH PROJECT, 2024
** shell_destroy.c
** File description:
** shell_destroy.c
*/

#include "my.h"

int shell_destroy(shell_t *shell)
{
    free(shell->user_input);
    command_array_destroy(shell->cmds);
    free(shell);
    return 0;
}
