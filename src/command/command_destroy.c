/*
** EPITECH PROJECT, 2024
** command_destroy.c
** File description:
** command_destroy.c
*/

#include "my.h"

int command_destroy(command_t *cmd)
{
    if (!cmd)
        return 0;
    free(cmd);
    return 0;
}
