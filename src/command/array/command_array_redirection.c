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
    if (!curr->argv || !*curr->argv || !path_readable(*curr->argv) ||
        curr->type != FILE_T)
        return 1;
    before->in = open(*curr->argv, O_RDONLY);
    if (before->in < 0)
        perror("open");
    return 0;
}

static int create_right_redirect(command_t *before, command_t *curr)
{
    if (!curr->argv || !*curr->argv || !path_writable(*curr->argv) ||
        curr->type != FILE_T)
        return 1;
    before->out = open(*curr->argv, O_CREAT | O_WRONLY);
    if (before->out < 0)
        perror("open");
    return 0;
}

static int create_dblright_redirect(command_t *before, command_t *curr)
{
    if (!curr->argv || !*curr->argv || !path_writable(*curr->argv) ||
        curr->type != FILE_T)
        return 1;
    before->out = open(*curr->argv, O_CREAT | O_WRONLY | O_APPEND);
    if (before->out < 0)
        perror("open");
    return 0;
}

static size_t find_before(command_t **arr, size_t i)
{
    for (; i != 0 && arr[i]->type != COMMAND; i--);
    return i;
}

int command_array_redirection(command_t **arr)
{
    for (size_t i = 0; arr[i]; i++) {
        if (arr[i]->type == LEFT_RED)
            create_left_redirect(arr[i - 1], arr[i + 1]);
        if (arr[i]->type == RIGHT_RED)
            create_right_redirect(arr[find_before(arr, i)], arr[i + 1]);
        if (arr[i]->type == RIGHT_DBLRED)
            create_dblright_redirect(arr[find_before(arr, i)], arr[i + 1]);
    }
    return 0;
}
