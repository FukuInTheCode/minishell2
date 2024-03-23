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
    for (size_t i = 0; arr[i]; i++) {
        if (arr[i]->type != COMMAND && arr[i]->type != FILE_T)
            continue;
        for (size_t j = 0; arr[i]->argv[j]; j++)
            printf("%s ", arr[i]->argv[j]);
        printf("\n");
        printf("in %d - out %d\n", arr[i]->in, arr[i]->out);
    }

    parser_destroy(parser);
    return 0;
}
