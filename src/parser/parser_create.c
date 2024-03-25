/*
** EPITECH PROJECT, 2024
** parser_create.c
** File description:
** parser_create.c
*/

#include "my.h"

parser_t *parser_create(void)
{
    parser_t *parser = malloc(sizeof(parser_t));

    if (!parser)
        return NULL;
    parser->parsed_input = malloc(sizeof(char *));
    if (!parser->parsed_input) {
        free(parser);
        return NULL;
    }
    *parser->parsed_input = NULL;
    parser->step = 0;
    parser->size = 0;
    return parser;
}
