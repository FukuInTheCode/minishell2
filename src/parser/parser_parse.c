/*
** EPITECH PROJECT, 2024
** parser_parse.c
** File description:
** parser_parse.c
*/

#include "my.h"

int parser_parse(parser_t *parser, char const *input)
{
    parser_add(parser, my_strdup(input));
    for (size_t i = 0; parsings_functions[i]; i++)
        parsings_functions[i](parser);
    return 0;
}
