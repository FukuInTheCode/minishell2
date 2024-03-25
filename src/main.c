/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main.c
*/

#include "my.h"

int main(int argc, char **argv, char **envp)
{
    shell_t *shell = NULL;

    if (argc != 1)
        return 84;
    shell = shell_create();
    if (!shell)
        return 84;
    shell_set_env(shell, env_copy(envp));
    if (shell_run(shell) == 84) {
        shell_destroy(shell);
        return 84;
    }
    return shell_destroy(shell);
}
