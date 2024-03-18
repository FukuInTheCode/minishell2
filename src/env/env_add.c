/*
** EPITECH PROJECT, 2024
** env_add.c
** File description:
** env_add.c
*/

#include "my.h"

char **env_add(char **env, char const *new)
{
    char **new_env = NULL;
    size_t len = 0;

    if (!env || !new)
        return env;
    len = env_len(env);
    new_env = malloc(sizeof(char *) * (len + 2));
    if (!new_env)
        return env;
    my_memset((void *)new_env, 0, sizeof(char *) * (len + 2));
    for (size_t i = 0; i < len; i++)
        new_env[i] = my_strdup(env[i]);
    new_env[len] = my_strdup(new);
    return new_env;
}
