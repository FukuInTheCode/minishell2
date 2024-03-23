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
    if (shell_run(shell) == 84)
        return 84;
    return shell_destroy(shell);
}
