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

    if (!parser || parser_parse(parser, input) == 84)
        return 84 + 0 * parser_destroy(parser);
    shell->cmds = parser_command(parser);
    if (!shell->cmds) {
        parser_destroy(parser);
        return 84;
    }
    if (command_array_error(shell->cmds, (void *)shell))
        return 1;
    if (command_array_pipe(shell->cmds) ||
        command_array_redirection(shell->cmds)) {
        shell_set_code(shell, 1);
        return 0;
    }
    parser_destroy(parser);
    return 0;
}
