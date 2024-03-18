/*
** EPITECH PROJECT, 2024
** command_set_type.c
** File description:
** command_set_type.c
*/

#include "my.h"

int command_set_type(command_t *cmd, type_t type)
{
    cmd->type = type;
    return 0;
}
