/*
** EPITECH PROJECT, 2024
** shell_set_env.c
** File description:
** shell_set_env.c
*/

#include "my.h"

int shell_set_env(shell_t *shell, char **env)
{
    shell->env = env;
    return 0;
}
