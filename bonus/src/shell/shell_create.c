/*
** EPITECH PROJECT, 2024
** shell_create.c
** File description:
** shell_create.c
*/

#include "my.h"

shell_t *shell_create(void)
{
    shell_t *shell = calloc(1, sizeof(shell_t));

    if (!shell)
        return NULL;
    return shell;
}
