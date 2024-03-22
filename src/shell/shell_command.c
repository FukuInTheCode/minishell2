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

    parser_parse(parser, input);
    for (size_t i = 0; parser->parsed_input[i]; i++)
        printf("%s\n", parser->parsed_input[i]);
    parser_destroy(parser);
    return 0;
}
