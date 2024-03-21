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
    return 0;
}
