/*
** EPITECH PROJECT, 2024
** shell_destroy.c
** File description:
** shell_destroy.c
*/

#include "my.h"

int shell_destroy(shell_t *shell)
{
    env_destroy(shell_get_env(shell));
    command_destroy(shell_get_cmds(shell));
    free(shell);
    return 0;
}
