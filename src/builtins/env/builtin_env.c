/*
** EPITECH PROJECT, 2024
** builtin_env.c
** File description:
** builtin_env.c
*/

#include "my.h"

int builtin_env(shell_t *shell, int argc, char **argv)
{
    if (argc != 1) {
        shell->return_code = 1;
        return 0;
    }
    for (size_t i = 0; shell->env[i]; i++) {
        my_dputs(1, shell->env[i]);
        my_dputs(1, "\n");
    }
    shell->return_code = 0;
    return 0;
}
