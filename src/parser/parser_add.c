/*
** EPITECH PROJECT, 2024
** parser_add.c
** File description:
** parser_add.c
*/

#include "my.h"

int parser_add(parser_t *parser, char *to_add)
{
    char **new = malloc(sizeof(char *) * (parser->size + 2));

    if (!new || !to_add) {
        free(new);
        return 84;
    }
    my_memset((void *)new, 0, sizeof(char *) * (parser->size + 2));
    for (size_t i = 0; parser->parsed_input[i]; i++)
        new[i] = parser->parsed_input[i];
    new[parser->size] = to_add;
    parser->size += 1;
    free(parser->parsed_input);
    parser->parsed_input = new;
    return 0;
}
