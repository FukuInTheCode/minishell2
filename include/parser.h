/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef PARSER_H
    #define PARSER_H

    #include <stddef.h>

typedef int (*parsing_func)();

typedef struct parse_s {
    size_t size;
    char **parsed_input;
    size_t step;
} parser_t;

parser_t *parser_create(void);
int parser_destroy(parser_t *);
int parser_add(parser_t *, char *);

int parser_func_char(parser_t *, char);
int parser_func_semicolon(parser_t *);

static parsing_func const parsings_functions[] = {
    parser_func_semicolon,
    NULL,
};

#endif
