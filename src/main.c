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
    shell_run(shell);
    shell_destroy(shell);
    return 0;
}
