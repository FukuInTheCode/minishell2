/*
** EPITECH PROJECT, 2024
** command_array_error.c
** File description:
** command_array_error.c
*/

#include "my.h"

int command_array_error(command_t **arr, void *shell)
{
    int error = 0;

    for (size_t i = 0; arr[i] && arr[i]->type != END; i++) {
        if (arr[i]->type == PIPE_T)
            error = command_check_pipe(arr[i], arr, i, shell);
        if (error)
            break;
    }
    return error;
}
