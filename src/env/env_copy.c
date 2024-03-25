/*
** EPITECH PROJECT, 2024
** env_copy.c
** File description:
** env_copy.c
*/

#include "my.h"

char **env_copy(char **env)
{
    char **new_env = NULL;
    size_t len = 0;

    if (!env)
        return NULL;
    len = env_len(env);
    new_env = malloc(sizeof(char *) * (len + 1));
    if (!new_env)
        return NULL;
    my_memset((void *)new_env, 0, sizeof(char *) * (len + 1));
    for (size_t i = 0; i < len; i++)
        new_env[i] = my_strdup(env[i]);
    return new_env;
}
