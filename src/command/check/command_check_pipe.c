/*
** EPITECH PROJECT, 2024
** command_check_pipe.c
** File description:
** command_check_pipe.c
*/

#include "my.h"

static int do_pipe_error(shell_t *shell)
{
    shell_set_code(shell, 1);
    my_dputs(2, "Invalid null command.\n");
    return 1;
}

int command_check_pipe(command_t *command, command_t **arr,
    size_t i, void *shell)
{
    if (!i || command_is_empty(arr[i + 1]))
        return do_pipe_error(shell);
    for (; i && arr[i]->type != COMMAND; i--);
    if (command_is_empty(arr[i]))
        return do_pipe_error(shell);
    return 0;
}
