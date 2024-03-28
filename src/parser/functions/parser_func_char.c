/*
** EPITECH PROJECT, 2024
** parser_func_semicolon.c
** File description:
** parser_func_semicolon.c
*/

#include "my.h"
#include "parser.h"
#include <stdio.h>

static int add_remaining(parser_t *parser, char const *s, size_t n)
{
    char *dupped_remaining = my_strndup(s + my_strlen(s) - n, n);

    if (!dupped_remaining || parser_add(parser, dupped_remaining) == 84) {
        free(dupped_remaining);
        return 84;
    }
    return 0;
}

static int parse_string(parser_t *parser, char *s, char const *delim)
{
    bool inquote = false;
    size_t n = 0;
    int error = 0;

    for (size_t i = 0; s[i]; i++) {
        if (s[i] == '\"')
            inquote = !inquote;
        if (!inquote && !my_strncmp(delim, s + i, my_strlen(delim))) {
            error |= parser_add(parser, my_strndup(s + i - n, n));
            error |= parser_add(parser, my_strdup(delim));
            n = 0;
            i += my_strlen(delim) - 1;
        } else
            n += my_strncmp(delim, s + i, my_strlen(delim)) != 0;
    }
    if (!error)
        error |= add_remaining(parser, s, n);
    free(s);
    return error;
}

int parser_func_char(parser_t *parser, char const *delim)
{
    parser_t *tmp = parser_create();
    int error = 0;

    if (!tmp)
        return 84;
    for (size_t i = 0; parser->parsed_input[i]; i++)
        if (parse_string(tmp, parser->parsed_input[i], delim) == 84)
            error = 84;
    parser->parsed_input = tmp->parsed_input;
    parser->size = tmp->size;
    free(tmp);
    return error;
}
