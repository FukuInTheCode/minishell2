/*
** EPITECH PROJECT, 2024
** command_array_redirection.c
** File description:
** command_array_redirection.c
*/

#include "command.h"
#include "my.h"

static int create_left_redirect(command_t *before, command_t *curr)
{
    before->in = open(*curr->argv, O_RDONLY);
    if (before->in < 0)
        perror("open");
    return 0;
}

static int create_right_redirect(command_t *before, command_t *curr)
{
    before->out = open(*curr->argv, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (before->out < 0)
        perror("open");
    return 0;
}

static int create_dblright_redirect(command_t *before, command_t *curr)
{
    before->out = open(*curr->argv, O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (before->out < 0)
        perror("open");
    return 0;
}

static int create_dblleft_redirect(command_t *before, command_t *curr)
{
    return command_dblleft_redirection(before, curr);
}

static size_t find_before(command_t **arr, size_t i)
{
    for (; i != 0 && arr[i]->type != COMMAND; i--);
    return i;
}

int command_redirection(command_t **arr)
{
    int error = 0;

    for (size_t i = 0; arr[i] &&
        arr[i]->type != PIPE_T && arr[i]->type != END; i++) {
        if (arr[i]->type == LEFT_RED)
            error = create_left_redirect(arr[i - 1], arr[i + 1]);
        if (arr[i]->type == RIGHT_RED)
            error = create_right_redirect(arr[find_before(arr, i)],
                arr[i + 1]);
        if (arr[i]->type == RIGHT_DBLRED)
            error = create_dblright_redirect(arr[find_before(arr, i)],
                arr[i + 1]);
        if (arr[i]->type == LEFT_DBLRED)
            error = create_dblleft_redirect(arr[find_before(arr, i)],
                arr[i + 1]);
        if (error)
            return error;
    }
    return 0;
}
