/*
** EPITECH PROJECT, 2024
** parser_destroy.c
** File description:
** parser_destroy.c
*/

#include "my.h"

int parser_destroy(parser_t *parser)
{
    for (size_t i = 0; parser->parsed_input[i]; i++)
        free(parser->parsed_input[i]);
    free(parser->parsed_input);
    free(parser);
    return 0;
}
