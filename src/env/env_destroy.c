/*
** EPITECH PROJECT, 2024
** env_destroy.c
** File description:
** env_destroy.c
*/

#include "my.h"

int env_destroy(char **env)
{
    for (size_t i = 0; env[i]; i++)
        free(env[i]);
    free(env);
    return 0;
}
