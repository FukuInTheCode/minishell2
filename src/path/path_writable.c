/*
** EPITECH PROJECT, 2024
** path_exist.c
** File description:
** path_exist.c
*/

#include "my.h"

bool path_writable(char const *path)
{
    if (path_exist(path))
        return !access(path, W_OK);
    return true;
}
