/*
** EPITECH PROJECT, 2024
** path_concat.c
** File description:
** path_concat.c
*/

#include "my.h"

static char *create_path(char const *former, char const *latter,
    bool has_slash)
{
    char *path = malloc(my_strlen(former) + my_strlen(latter) + 1 + has_slash);

    if (!path)
        return NULL;
    my_memset(path, 0, my_strlen(former) + my_strlen(latter) + 1 + has_slash);
    my_strcat(path, former);
    if (has_slash)
        my_strcat(path, "/");
    my_strcat(path, latter);
    return path;
}

char *path_concat(char const *former, char const *latter)
{
    bool has_slash = false;

    if (!former && !latter)
        return NULL;
    if (!former)
        return my_strdup(latter);
    if (!latter)
        return my_strdup(former);
    if (former[my_strlen(former) - 1] == '/' || *latter == '/')
        has_slash = true;
    return create_path(former, latter, !has_slash);
}
