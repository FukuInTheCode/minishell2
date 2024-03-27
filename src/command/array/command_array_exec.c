/*
** EPITECH PROJECT, 2024
** command_array_exec.c
** File description:
** command_array_exec.c
*/

#include "my.h"

int command_array_exec(command_t **commands, void *shell_ptr)
{
    int error = 0;

    for (size_t i = 0; commands[i]; i++)
        if (commands[i]->type == COMMAND &&
            commands[i]->argv && commands[i]->argv[0])
            error |= command_exec(commands[i], shell_ptr, commands + i);
    return error;
}
