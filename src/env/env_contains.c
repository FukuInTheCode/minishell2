/*
** EPITECH PROJECT, 2024
** env_contains.c
** File description:
** env_contains.c
*/

#include "my.h"

bool env_contains(char **env, char const *var)
{
    for (size_t i = 0; env[i]; i++)
        if (!my_strncmp(env[i], var, my_strlen(var)) &&
            env[i][my_strlen(var)] == '=')
            return true;
    return false;
}
