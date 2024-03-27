/*
** EPITECH PROJECT, 2024
** command_builtins.c
** File description:
** command_builtins.c
*/

#include "my.h"

int command_builtins(command_t *command, void *shell_ptr)
{
    if (!my_strcmp("env", command->argv[0]))
        return builtin_env(shell_ptr, command->argc, command->argv);
    if (!my_strcmp("setenv", command->argv[0]))
        return builtin_setenv(shell_ptr, command->argc, command->argv);
    if (!my_strcmp("unsetenv", command->argv[0]))
        return builtin_unsetenv(shell_ptr, command->argc, command->argv);
    if (!my_strcmp("cd", command->argv[0]))
        return builtin_cd(shell_ptr, command->argc, command->argv);
    if (!my_strcmp("exit", command->argv[0]))
        return builtin_exit(shell_ptr, command->argc, command->argv);
    return 0;
}
