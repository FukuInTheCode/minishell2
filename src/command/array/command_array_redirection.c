/*
** EPITECH PROJECT, 2024
** command_array_redirection.c
** File description:
** command_array_redirection.c
*/

#include "command.h"
#include "my.h"

static int handle_file_error(command_t *cmd, bool check_r, bool check_w)
{
    if (cmd->type != FILE_T) {
        my_dputs(2, "Missing name for redirect.\n");
        return 0;
    }
    if (!path_exist(cmd->argv[0])) {
        my_dputs(2, cmd->argv[0]);
        my_dputs(2, ": No such file or directory.\n");
        return 0;
    }
    if (check_r && !path_readable(cmd->argv[0])) {
        my_dputs(2, cmd->argv[0]);
        my_dputs(2, ": Permission denied.\n");
    }
    if (check_w && !path_writable(cmd->argv[0])) {
        my_dputs(2, cmd->argv[0]);
        my_dputs(2, ": Permission denied.\n");
    }
    return 0;
}

static int create_left_redirect(command_t *before, command_t *curr)
{
    if (!curr->argv || !*curr->argv || !path_readable(*curr->argv) ||
        curr->type != FILE_T) {
        handle_file_error(curr, 1, 0);
        return 1;
    }
    if (before->in != SYS_IN) {
        my_dputs(2, "Ambiguous input redirect.\n");
        return 1;
    }
    before->in = open(*curr->argv, O_RDONLY);
    if (before->in < 0)
        perror("open");
    return 0;
}

static int create_right_redirect(command_t *before, command_t *curr)
{
    if (!curr->argv || !*curr->argv || !path_writable(*curr->argv) ||
        curr->type != FILE_T) {
        handle_file_error(curr, 0, 1);
        return 1;
    }
    if (before->out != SYS_OUT) {
        my_dputs(2, "Ambiguous output redirect.\n");
        return 1;
    }
    before->out = open(*curr->argv, O_CREAT | O_WRONLY | O_TRUNC);
    if (before->out < 0)
        perror("open");
    return 0;
}

static int create_dblright_redirect(command_t *before, command_t *curr)
{
    if (!curr->argv || !*curr->argv || !path_writable(*curr->argv) ||
        curr->type != FILE_T) {
        handle_file_error(curr, 0, 1);
        return 1;
    }
    if (before->out != SYS_OUT) {
        my_dputs(2, "Ambiguous output redirect.\n");
        return 1;
    }
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
    int error = 0;

    for (size_t i = 0; arr[i]; i++) {
        if (arr[i]->type == LEFT_RED)
            error = create_left_redirect(arr[i - 1], arr[i + 1]);
        if (arr[i]->type == RIGHT_RED)
            error = create_right_redirect(arr[find_before(arr, i)],
                arr[i + 1]);
        if (arr[i]->type == RIGHT_DBLRED)
            error = create_dblright_redirect(arr[find_before(arr, i)],
                arr[i + 1]);
        if (error)
            return error;
    }
    return 0;
}
