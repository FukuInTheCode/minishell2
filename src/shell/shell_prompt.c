/*
** EPITECH PROJECT, 2024
** shell_prompt.c
** File description:
** shell_prompt.c
*/

#include "my.h"

int shell_prompt(shell_t *shell)
{
    if (isatty(0) && shell && shell->prompt)
        my_dputs(1, shell->prompt);
    return 0;
}
