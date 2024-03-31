/*
** EPITECH PROJECT, 2024
** shell_process_commands.c
** File description:
** shell_process_commands.c
*/

#include "my.h"

#include <sys/wait.h>

static int wait_process(command_t *cmd, shell_t *shell)
{
    waitpid(command_get_pid(cmd), &cmd->status, 0);
    command_process_status(cmd, (void *)shell);
    return 0;
}

static int process_command(command_t *cmd, shell_t *shell)
{
    if (cmd->type != COMMAND)
        return 0;
    command_exec(cmd, (void *)shell);
    if (command_get_wait(cmd))
        wait_process(cmd, shell);
    return 0;
}

int shell_process_commands(shell_t *shell)
{
    command_t *cmd = shell_get_cmds(shell);

    for (; cmd && !shell_get_exit(shell); cmd = command_get_next(cmd)) {
        process_command(cmd, shell);
    }
    return 0;
}
