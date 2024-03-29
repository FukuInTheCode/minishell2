/*
** EPITECH PROJECT, 2024
** command_exec.c
** File description:
** command_exec.c
*/

#include "my.h"

static int handle_pipes(command_t **arr, size_t i)
{
    if (arr[i]->in != SYS_IN && !command_is_builtin(arr[i]))
        dup2(arr[i]->in, 0);
    if (arr[i]->out != SYS_OUT)
        dup2(arr[i]->out, 1);
    for (size_t j = 0; arr[j]; j++) {
        if (j == i || arr[j]->type != COMMAND)
            continue;
        if (arr[j]->out != SYS_OUT)
            close(arr[j]->out);
        if (arr[j]->in != SYS_IN)
            close(arr[j]->in);
    }
    return 0;
}

static int do_child_process(command_t *command, shell_t *shell,
    command_t **arr, size_t i)
{
    int tmp = 0;

    handle_pipes(arr, i);
    if (command_is_builtin(command)) {
        tmp = command_builtins(command, (void *)shell);
        if (command->out != SYS_OUT) {
            close(command->out);
            shell_set_exit(shell, true);
        }
        if (command->in != SYS_IN)
            close(command->in);
        return tmp;
    }
    if ((**command->argv != '/' &&
        **command->argv != '.') ||
        execve(command->argv[0], command->argv, shell->env) == -1)
        return command_error(command, errno, shell);
    return 0;
}

static int close_pipe(command_t *command)
{
    if (command->out != SYS_OUT)
        close(command->out);
    if (command->in != SYS_IN)
        close(command->in);
    return 0;
}

int command_exec(command_t *command, void *shell_ptr,
    command_t **arr, size_t i)
{
    pid_t pid = 0;
    bool is_builtin = false;

    command_path(command, shell_ptr);
    command_pipe(arr + i);
    command_redirection(arr + i);
    is_builtin = command_is_builtin(command);
    if (!is_builtin || command->out != 1)
        pid = fork();
    command->pid = pid;
    if (pid < 0) {
        perror("fork");
        return 84;
    }
    if (!pid)
        return do_child_process(command, shell_ptr, arr, i);
    return close_pipe(command);
}
