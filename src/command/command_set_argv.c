/*
** EPITECH PROJECT, 2024
** command_set_argv.c
** File description:
** command_set_argv.c
*/

#include "my.h"

int command_set_argv(command_t *cmd, char **argv)
{
    cmd->argv = argv;
    return 0;
}
