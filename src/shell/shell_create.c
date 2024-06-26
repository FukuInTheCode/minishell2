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

    if (!shell)
        return NULL;
    shell->cmds = command_array_create();
    if (!shell->cmds) {
        free(shell);
        return NULL;
    }
    shell->user_input = NULL;
    shell->return_code = 0;
    shell->env = NULL;
    shell->oldpwd = NULL;
    shell->prompt = my_strdup("$> ");
    shell->do_exit = 0;
    if (!shell->prompt)
        return NULL;
    return shell;
}
