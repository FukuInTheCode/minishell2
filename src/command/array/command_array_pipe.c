/*
** EPITECH PROJECT, 2024
** command_array_pipe.c
** File description:
** command_array_pipe.c
*/

#include "command.h"
#include "my.h"

static int create_pipe(command_t *before, command_t *after)
{
    before->out_is_used = true;
    after->in_is_used = true;
    return 0;
}

static size_t find_before(command_t **arr, size_t i)
{
    for (; i != 0 && arr[i]->type != COMMAND; i--);
    return i;
}

int command_array_pipe(command_t **arr)
{
    size_t before_i = 0;

    for (size_t i = 0; arr[i]; i++)
        if (arr[i]->type == PIPE_T) {
            before_i = find_before(arr, i);
            create_pipe(arr[before_i], arr[i + 1]);
        }
    return 0;
}
