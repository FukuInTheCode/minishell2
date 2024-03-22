/*
** EPITECH PROJECT, 2024
** parser_func_semicolon.c
** File description:
** parser_func_semicolon.c
*/

#include "my.h"
#include "parser.h"
#include <stdio.h>

static int parse_string(parser_t *parser, char *s, char const *delim)
{
    bool inside_string = false;
    size_t n = 0;

    for (size_t i = 0; s[i]; i++) {
        if (s[i] == '\"')
            inside_string = !inside_string;
        if (!inside_string && !my_strncmp(delim, s + i, my_strlen(delim))
            && n) {
            parser_add(parser, my_strndup(s + i - n, n));
            parser_add(parser, my_strdup(delim));
            n = 0;
            continue;
        }
        n += my_strncmp(delim, s + i, my_strlen(delim)) != 0;
    }
    if (n)
        parser_add(parser, my_strndup(s + my_strlen(s) - n, n));
    free(s);
    return 0;
}

int parser_func_char(parser_t *parser, char const *delim)
{
    parser_t *tmp = parser_create();

    for (size_t i = 0; parser->parsed_input[i]; i++)
        parse_string(tmp, parser->parsed_input[i], delim);
    parser->parsed_input = tmp->parsed_input;
    parser->size = tmp->size;
    free(tmp);
    return 0;
}
