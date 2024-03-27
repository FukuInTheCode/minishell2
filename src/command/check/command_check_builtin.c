/*
** EPITECH PROJECT, 2024
** command_check_builtin.c
** File description:
** command_check_builtin.c
*/

#include "my.h"

bool command_is_builtin(command_t *command)
{
    if (!my_strcmp("env", command->argv[0]))
        return true;
    if (!my_strcmp("setenv", command->argv[0]))
        return true;
    if (!my_strcmp("unsetenv", command->argv[0]))
        return true;
    if (!my_strcmp("cd", command->argv[0]))
        return true;
    if (!my_strcmp("exit", command->argv[0]))
        return true;
    return false;
}
