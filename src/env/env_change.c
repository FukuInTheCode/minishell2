/*
** EPITECH PROJECT, 2024
** env_remove.c
** File description:
** env_remove.c
*/

#include "my.h"

char **env_change(char **env, char const *var, char const *val)
{
    char **new_env = NULL;
    size_t len = 0;

    if (!env || !var)
        return env;
    len = env_len(env);
    new_env = malloc(sizeof(char *) * (len + 1));
    if (!new_env)
        return env;
    my_memset((void *)new_env, 0, sizeof(char *) * (len + 1));
    for (size_t i = 0; i < len; i++) {
        if (!my_strncmp(var, env[i], my_strlen(var)) &&
            env[i][my_strlen(var)] == '=')
            new_env[i] = env_val_concat(var, val);
        else
            new_env[i] = my_strdup(env[i]);
    }
    return new_env;
}
