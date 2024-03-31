/*
** EPITECH PROJECT, 2024
** shell_process_input.c
** File description:
** shell_process_input.c
*/

#include "my.h"
#include <stdio.h>

int shell_process_input(shell_t *shell, char const *input)
{
    print(input);
    shell_parse_input(shell, input);
    shell_process_commands(shell);
    return 0;
}
