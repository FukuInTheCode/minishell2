/*
** EPITECH PROJECT, 2024
** shell_command.c
** File description:
** shell_command.c
*/

#include "my.h"

int shell_command(shell_t *shell, char const *input)
{
    parser_t *parser = parser_create();
    command_t **arr = NULL;

    parser_parse(parser, input);
    arr = parser_command(parser);
    command_array_pipe(arr);
    parser_destroy(parser);
    return 0;
}
