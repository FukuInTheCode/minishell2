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
    int fildes[2];

    if (pipe(fildes)) {
        perror("pipe");
        return 84;
    }
    before->out = fildes[1];
    after->in = fildes[0];
    return 0;
}

int command_pipe(command_t **arr)
{
    command_t *cmd = *arr;

    for (size_t i = 0; arr[i] && arr[i]->type != END; i++)
        if (arr[i]->type == PIPE_T) {
            create_pipe(cmd, arr[i + 1]);
            break;
        }
    return 0;
}
