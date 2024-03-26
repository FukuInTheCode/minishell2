/*
** EPITECH PROJECT, 2024
** command_status.c
** File description:
** command_status.c
*/

#include "my.h"

int command_status(void *shell_ptr, int status)
{
    shell_set_code(shell_ptr, status);
    return 0;
}
