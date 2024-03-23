/*
** EPITECH PROJECT, 2024
** command_check_empty.c
** File description:
** command_check_empty.c
*/

#include "my.h"

bool command_is_empty(command_t *command)
{
    if (!my_strlen(command->argv[0]))
        return true;
    return false;
}
