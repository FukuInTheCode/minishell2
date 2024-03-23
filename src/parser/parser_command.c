/*
** EPITECH PROJECT, 2024
** parser_command.c
** File description:
** parser_command.c
*/

#include "my.h"

static bool add_to_arr(command_t ***arr, type_t t, char **input, size_t *i)
{
    command_t *command = command_create();

    command_set_type(command, t);
    *arr = command_array_add(*arr, command);
    if (t != PIPE_T && t != END) {
        *i += 1;
        command = command_create();
        command_set_type(command, FILE_T);
        command_set_argv(command, my_str_to_word_array(input[*i], " \t\n"));
        *arr = command_array_add(*arr, command);
    }
    return false;
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
    command_set_argv(command, my_str_to_word_array(input, " \t\n"));
    command_set_argc(command, my_len_word_array(command->argv));
    *arr = command_array_add(*arr, command);
    return 0;
}

command_t **parser_command(parser_t *parser)
{
    command_t **arr = command_array_create();
    bool is_base = true;

    for (size_t i = 0; parser->parsed_input[i]; i++) {
        if (!my_strcmp(parser->parsed_input[i], SEMICOLON))
            is_base = add_to_arr(&arr, END, parser->parsed_input, &i);
        if (!my_strcmp(parser->parsed_input[i], PIPE))
            is_base = add_to_arr(&arr, PIPE_T, parser->parsed_input, &i);
        if (!my_strcmp(parser->parsed_input[i], DOUBLE_RIGHT))
            is_base = add_to_arr(&arr, RIGHT_DBLRED, parser->parsed_input, &i);
        if (!my_strcmp(parser->parsed_input[i], DOUBLE_LEFT))
            is_base = add_to_arr(&arr, LEFT_DBLRED, parser->parsed_input, &i);
        if (!my_strcmp(parser->parsed_input[i], SINGLE_RIGHT))
            is_base = add_to_arr(&arr, RIGHT_RED, parser->parsed_input, &i);
        if (!my_strcmp(parser->parsed_input[i], SINGLE_LEFT))
            is_base = add_to_arr(&arr, LEFT_RED, parser->parsed_input, &i);
        setup_basic(&is_base, &arr, parser->parsed_input[i]);
    }
    return arr;
}
