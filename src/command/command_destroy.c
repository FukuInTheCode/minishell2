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
    if (cmd->argv)
        my_free_word_array(cmd->argv);
    free(cmd);
    return 0;
}
