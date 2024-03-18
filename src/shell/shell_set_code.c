/*
** EPITECH PROJECT, 2024
** shell_set_code.c
** File description:
** shell_set_code.c
*/

#include "my.h"

int shell_set_code(shell_t *shell, int code)
{
    shell->return_code = code;
    return 0;
}
