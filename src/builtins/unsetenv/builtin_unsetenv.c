/*
** EPITECH PROJECT, 2024
** builtin_unsetenv.c
** File description:
** builtin_unsetenv.c
*/

#include "my.h"

int builtin_unsetenv(shell_t *shell, int argc, char **argv)
{
    char **tmp_env = NULL;

    if (argc == 1) {
        my_dputs(2, "unsetenv: Too few arguments.\n");
        shell->return_code = 1;
        return 0;
    }
    for (size_t i = 1; argv[i]; i++)
        if (env_contains(shell->env, argv[i])) {
            tmp_env = env_remove(shell->env, argv[i]);
        }
    if (tmp_env)
        shell->env = tmp_env;
    shell->return_code = 0;
    return 0;
}
