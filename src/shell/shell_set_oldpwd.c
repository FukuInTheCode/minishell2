/*
** EPITECH PROJECT, 2024
** shell_set_code.c
** File description:
** shell_set_code.c
*/

#include "my.h"

int shell_set_oldpwd(shell_t *shell, char const *oldpwd)
{
    free(shell->oldpwd);
    shell->oldpwd = my_strdup(oldpwd);
    if (env_get(shell->env, "OLDPWD"))
        shell_set_env(shell, env_change(shell->env, "OLDPWD", oldpwd));
    else
        shell_set_env(shell, env_add(shell->env, "OLDPWD", oldpwd));
    return 0;
}
