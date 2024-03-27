/*
** EPITECH PROJECT, 2024
** command_array_exec.c
** File description:
** command_array_exec.c
*/

#include "my.h"

static int close_pipes(command_t **commands, size_t start, size_t end)
{
    for (; start < end; start++) {
        if (!commands[start] || commands[start]->type != COMMAND)
            continue;
        if (commands[start]->in != SYS_IN)
            close(commands[start]->in);
        if (commands[start]->out != SYS_OUT)
            close(commands[start]->out);
    }
    return 0;
}

static int wait_process(command_t *command, pid_t pid, shell_t *shell)
{
    int status = 0;

    if (!pid)
        return 0;
    printf("%d : %s\n", pid, command->argv[0]);
    waitpid(pid, &status, 0);
    command_status(shell, status);
    return 0;
}

static int wait_processes(command_t **commands, size_t start, size_t end,
    shell_t *shell)
{
    for (; start < end; start++)
        wait_process(commands[start], commands[start]->pid, shell);
    return 0;
}

static int execute_pipeline(command_t **commands, size_t *i,
    void *shell_ptr, bool *do_break)
{
    int error = 0;
    size_t save_i = *i;

    for (; !*do_break && commands[*i] && commands[*i]->type != END; (*i)++) {
        if (commands[*i]->type == COMMAND &&
            commands[*i]->argv && commands[*i]->argv[0])
            error |= command_exec(commands[*i], shell_ptr, commands, *i);
        if (((shell_t *)shell_ptr)->do_exit)
            *do_break = true;
    }
    close_pipes(commands, save_i, *i);
    wait_processes(commands, save_i, *i, shell_ptr);
    if (!commands[*i])
        *do_break = true;
    return error;
}

int command_array_exec(command_t **commands, void *shell_ptr)
{
    bool do_break = false;
    int error = 0;

    for (size_t i = 0; !do_break && commands[i]; i++) {
        error |= execute_pipeline(commands, &i, shell_ptr, &do_break);
        if (error)
            break;
    }
    return error;
}
