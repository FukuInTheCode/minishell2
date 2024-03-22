/*
** EPITECH PROJECT, 2024
** shell_run.c
** File description:
** shell_run.c
*/

#include "my.h"

int shell_run(shell_t *shell)
{
    char *input = NULL;
    size_t len = 0;

    shell_prompt(shell);
    for (; getline(&input, &len, stdin) != -1;) {
        shell_command(shell, input);
        shell_prompt(shell);
    }
    free(input);
    return 0;
}
