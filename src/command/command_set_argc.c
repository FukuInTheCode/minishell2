/*
** EPITECH PROJECT, 2024
** command_set_argc.c
** File description:
** command_set_argc.c
*/

#include "my.h"

int command_set_argc(command_t *cmd, int argc)
{
    cmd->argc = argc;
    return 0;
}
