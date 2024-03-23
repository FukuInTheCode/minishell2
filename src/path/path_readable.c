/*
** EPITECH PROJECT, 2024
** path_exist.c
** File description:
** path_exist.c
*/

#include "my.h"

bool path_readable(char const *path)
{
    return !access(path, F_OK | R_OK);
}
