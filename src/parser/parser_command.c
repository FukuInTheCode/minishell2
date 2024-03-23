/*
** EPITECH PROJECT, 2024
** parser_command.c
** File description:
** parser_command.c
*/

#include "my.h"

static int add_to_arr(command_t ***arr, type_t t, bool *is_basic,
    char const *input)
{
    command_t *command = command_create();

    command_set_type(command, t);
    *arr = command_array_add(*arr, command);
    *is_basic = false;
    return 0;
}

static int setup_basic(bool *is_basic, command_t ***arr, char *input)
{
    command_t *command = NULL;

    if (!*is_basic) {
        *is_basic = true;
        return 0;
    }
    command = command_create();
    command_set_type(command, COMMAND);
    command_set_argv(command, my_str_to_word_array(input, " \t"));
    command_set_argc(command, my_len_word_array(command->argv));
    *arr = command_array_add(*arr, command);
    return 0;
}

command_t **parser_command(parser_t *parser)
{
    command_t **arr = command_array_create();
    bool is_basic = true;

    for (size_t i = 0; parser->parsed_input[i]; i++) {
        if (!my_strcmp(parser->parsed_input[i], SEMICOLON))
            add_to_arr(&arr, END, &is_basic, parser->parsed_input[i]);
        if (!my_strcmp(parser->parsed_input[i], PIPE))
            add_to_arr(&arr, PIPE_T, &is_basic, parser->parsed_input[i]);
        if (!my_strcmp(parser->parsed_input[i], DOUBLE_RIGHT))
            add_to_arr(&arr, RIGHT_DBLRED, &is_basic, parser->parsed_input[i]);
        if (!my_strcmp(parser->parsed_input[i], DOUBLE_LEFT))
            add_to_arr(&arr, LEFT_DBLRED, &is_basic, parser->parsed_input[i]);
        if (!my_strcmp(parser->parsed_input[i], SINGLE_RIGHT))
            add_to_arr(&arr, RIGHT_RED, &is_basic, parser->parsed_input[i]);
        if (!my_strcmp(parser->parsed_input[i], SINGLE_RIGHT))
            add_to_arr(&arr, LEFT_RED, &is_basic, parser->parsed_input[i]);
        setup_basic(&is_basic, &arr, parser->parsed_input[i]);
    }
    return arr;
}
