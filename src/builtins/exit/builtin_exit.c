/*
** EPITECH PROJECT, 2024
** builtin_exit.c
** File description:
** builtin_exit.c
*/

#include "my.h"

static bool is_number(char const *s)
{
    for (size_t i = *s == '-' || *s == '+'; s[i]; i++)
        if (!('0' <= s[i] && s[i] <= '9'))
            return false;
    return true;
}

int builtin_exit(shell_t *shell, int argc, char **argv)
{
    if (argc > 2 || (argc == 2 && !is_number(argv[1]))) {
        my_dputs(2, "exit: Expression Syntax.\n");
        shell_set_code(shell, 1);
        return 0;
    }
    if (argc == 2)
        shell_set_code(shell, my_atoi(argv[1]));
    shell_set_exit(shell, true);
    return 0;
}
