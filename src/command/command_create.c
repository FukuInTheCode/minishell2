/*
** EPITECH PROJECT, 2024
** command_create.c
** File description:
** command_create.c
*/

#include "my.h"

command_t *command_create(void)
{
    command_t *cmd = malloc(sizeof(command_t));

    cmd->in = SYS_IN;
    cmd->out = SYS_OUT;
    cmd->argc = 0;
    cmd->argv = NULL;
    cmd->type = END;
    cmd->in_is_used = false;
    cmd->out_is_used = false;
    cmd->pid = 0;
    return cmd;
}
