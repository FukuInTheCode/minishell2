/*
** EPITECH PROJECT, 2024
** setenv.c
** File description:
** setenv.c
*/

#include "my.h"

static bool setenv_argv_is_good(shell_t *shell, int argc, char **argv)
{
    if (argc > 3) {
        my_dputs(2, "setenv: Too many arguments.\n");
        shell->return_code = 1;
        return false;
    }
    if (!env_val_is_good(argv[1])) {
        shell_set_code(shell, 1);
        return false;
    }
    return true;
}

int builtin_setenv(shell_t *shell, int argc, char **argv)
{
    if (argc == 1)
        return builtin_env(shell, argc, argv);
    if (!setenv_argv_is_good(shell, argc, argv))
        return 0;
    if (env_contains(shell->env, argv[1])) {
        shell->env = env_change(shell->env, argv[1], argv[2]);
        shell->return_code = 0;
        return 0;
    }
    shell->env = env_add(shell->env, argv[1], argv[2]);
    shell->return_code = 0;
    return 0;
}
