/*
** EPITECH PROJECT, 2024
** path_is_executable.c
** File description:
** path_is_executable.c
*/

#include "my.h"

bool path_is_executable(char const *path)
{
    return !access(path, F_OK | X_OK);
}
