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

#endif
