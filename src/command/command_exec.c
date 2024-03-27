/*
** EPITECH PROJECT, 2024
** command_exec.c
** File description:
** command_exec.c
*/

#include "my.h"

static int do_child_process(command_t *command, shell_t *shell,
    command_t **remaining)
{
    int tmp = 0;

    if (command->in != SYS_IN)
        dup2(command->in, 0);
    if (command->out != SYS_OUT)
        dup2(command->out, 1);
    if (command_is_builtin(command)) {
        tmp = command_builtins(command, (void *)shell);
        if (command->out != 1)
            exit(tmp);
        return tmp;
    }
    if (execve(command->argv[0], command->argv, shell->env) == -1)
        return command_error(command, errno, shell);
    return 0;
}

static int do_parent_process(command_t *command, pid_t pid, shell_t *shell)
{
    int status = 0;

    waitpid(pid, &status, 0);
    if (command->in != SYS_IN)
        close(command->in);
    if (command->out != SYS_OUT)
        close(command->out);
    command_status(shell, status);
    return 0;
}

int command_exec(command_t *command, void *shell_ptr, command_t **remaining)
{
    pid_t pid = 0;
    bool is_builtin = false;

    command_path(command, shell_ptr);
    command_pipe(remaining);
    command_redirection(remaining);
    is_builtin = command_is_builtin(command);
    if (!is_builtin || command->out != 1)
        pid = fork();
    if (pid < 0) {
        perror("fork");
        return 84;
    }
    if (!pid)
        return do_child_process(command, shell_ptr, remaining);
    return do_parent_process(command, pid, shell_ptr);
}
