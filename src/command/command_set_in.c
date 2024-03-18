/*
** EPITECH PROJECT, 2024
** command_set_in.c
** File description:
** command_set_in.c
*/

#include "my.h"

int command_set_in(command_t *cmd, int in)
{
    cmd->in = in;
    return 0;
}
