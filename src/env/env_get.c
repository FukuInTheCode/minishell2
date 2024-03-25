/*
** EPITECH PROJECT, 2024
** env_get.c
** File description:
** env_get.c
*/

#include "my.h"

char *env_get(char **env, char const *var)
{
    if (!env || !var)
        return NULL;
    for (size_t i = 0; env[i]; i++) {
        if (!my_strncmp(env[i], var, my_strlen(var)) &&
            env[i][my_strlen(var)] == '=')
            return env[i] + my_strlen(var) + 1;
    }
    return NULL;
}
