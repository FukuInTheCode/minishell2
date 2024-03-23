/*
** EPITECH PROJECT, 2024
** parser_parse.c
** File description:
** parser_parse.c
*/

#include "my.h"

int parser_parse(parser_t *parser, char const *input)
{
    if (parser_add(parser, my_strdup(input)) == 84)
        return 84;
    for (size_t i = 0; parsings_functions[i]; i++)
        if (parsings_functions[i](parser) == 84)
            return 84;
    return 0;
}
