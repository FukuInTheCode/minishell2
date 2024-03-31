/*
** EPITECH PROJECT, 2024
** shell_set_run.c
** File description:
** shell_set_run.c
*/

#include "my.h"
#include <stdio.h>

int shell_run(shell_t *shell)
{
    char *line = NULL;
    size_t len = 0;

    shell_handle_prompt(shell);
    for (; getline(&line, &len, stdin) != -1;) {
        shell_process_input(shell, line);
        shell_clean(shell);
        shell_handle_prompt(shell);
    }
    return 0;
}
