/*
** EPITECH PROJECT, 2024
** command_array_pipe.c
** File description:
** command_array_pipe.c
*/

#include "my.h"

static int create_pipe(command_t *before, command_t *after)
{
    int fildes[2];

    if (pipe(fildes)) {
        perror("pipe");
        return 84;
    }
    before->out = fildes[1];
    after->in = fildes[0];
    return 0;
}

int command_array_pipe(command_t **arr)
{
    for (size_t i = 0; arr[i]; i++)
        if (arr[i]->type == PIPE_T)
            create_pipe(arr[i - 1], arr[i + 1]);
    return 0;
}
