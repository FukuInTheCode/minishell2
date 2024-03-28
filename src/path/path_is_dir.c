/*
** EPITECH PROJECT, 2024
** path_is_dir.c
** File description:
** path_is_dir.c
*/

#include "my.h"


bool path_is_dir(const char *path)
{
    struct stat st;

    if (stat(path, &st) == -1)
        return false;
    return S_ISDIR(st.st_mode);
}
