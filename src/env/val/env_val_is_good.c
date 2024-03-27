/*
** EPITECH PROJECT, 2024
** env_val_is_good.c
** File description:
** env_val_is_good.c
*/

#include "my.h"

static bool is_letter(char c)
{
    if ('a' <= c && c <= 'z')
        return true;
    if ('A' <= c && c <= 'Z')
        return true;
    if (c == '_')
        return true;
    return false;
}

static bool is_alphanum(char c)
{
    if (is_letter(c))
        return true;
    if ('0' <= c && c <= '9')
        return true;
    return false;
}

bool env_val_is_good(char const *var)
{
    if (!var || !is_letter(*var)) {
        my_dputs(2, "setenv: Variable name must begin with a letter.\n");
        return false;
    }
    for (int i = 1; var[i]; i++)
        if (!is_alphanum(var[i])) {
            my_dputs(2, "setenv: Variable name "
                "must contain alphanumeric characters.\n");
            return false;
        }
    return true;
}
