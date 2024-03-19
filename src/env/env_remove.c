/*
** EPITECH PROJECT, 2024
** env_remove.c
** File description:
** env_remove.c
*/

#include "my.h"

char **env_remove(char **env, char const *var)
{
    char **new_env = NULL;
    size_t len = 0;
    size_t j = 0;

    if (!env || !var)
        return env;
    len = env_len(env);
    new_env = malloc(sizeof(char *) * len);
    if (!new_env)
        return env;
    my_memset((void *)new_env, 0, sizeof(char *) * len);
    for (size_t i = 0; i < len; i++) {
        if (!my_strncmp(var, env[i], my_strlen(var)) &&
            env[i][my_strlen(var)] == '=')
            continue;
        new_env[j] = my_strdup(env[i]);
        j++;
    }
    return new_env;
}
