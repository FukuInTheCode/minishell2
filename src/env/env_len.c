/*
** EPITECH PROJECT, 2024
** env_len.c
** File description:
** env_len.c
*/

#include "my.h"

size_t env_len(char **env)
{
    size_t len = 0;

    if (!env)
        return len;
    for (; env[len]; len++);
    return len;
}
