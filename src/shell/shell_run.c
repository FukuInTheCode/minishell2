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

    for (; getline(&input, &len, stdin) != -1;) {
        if (isatty(0))
            my_dputs(1, "$>");
        my_dputs(1, input);
    }
    return 0;
}
