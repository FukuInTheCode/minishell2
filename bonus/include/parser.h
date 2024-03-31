/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#pragma once
    #define PARSER_H

    #include <stddef.h>

    #include "command.h"
    #include "separator.h"

typedef struct parser_s {
    char **tokens;
    size_t i;
} parser_t;

parser_t *parser_create(void);
int parse_destroy(parser_t *);

int parser_set_tokens(parser_t *, char **);

int parser_parse(parser_t *, char const *);
command_t *parser_to_command(parser_t *);

int parser_command_end(parser_t *);
int parser_command_pipe(parser_t *);
int parser_command_left(parser_t *);
int parser_command_right(parser_t *);
int parser_command_double_left(parser_t *);
int parser_command_double_right(parser_t *);
int parser_command_command(parser_t *);

static separator_t const separators[] = {
    {";", "", parser_command_end},
    {"|", "|", parser_command_pipe},
    {">", ">", parser_command_right},
    {">>", "", parser_command_double_right},
    {"<", "<", parser_command_left},
    {"<<", "", parser_command_double_left},
    {NULL, NULL, NULL}
};
