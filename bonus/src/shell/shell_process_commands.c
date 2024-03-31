/*
** EPITECH PROJECT, 2024
** shell_process_commands.c
** File description:
** shell_process_commands.c
*/

#include "my.h"

int shell_process_commands(shell_t *shell)
{
    command_t *cmd = shell_get_cmds(shell);

    for (; cmd && !shell_get_exit(shell); cmd = command_get_next(cmd)) {
        continue;
    }
    return 0;
}
