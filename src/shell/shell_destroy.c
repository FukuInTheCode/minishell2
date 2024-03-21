/*
** EPITECH PROJECT, 2024
** shell_destroy.c
** File description:
** shell_destroy.c
*/

#include "my.h"

int shell_destroy(shell_t *shell)
{
    int return_val = shell->return_code;

    free(shell->user_input);
    free(shell->oldpwd);
    free(shell->prompt);
    command_array_destroy(shell->cmds);
    free(shell);
    exit(return_val);
    return 0;
}
