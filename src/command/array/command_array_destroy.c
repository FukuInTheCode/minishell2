/*
** EPITECH PROJECT, 2024
** command_array_destroy.c
** File description:
** command_array_destroy.c
*/

#include "my.h"

int command_array_destroy(command_t **arr)
{
    if (!arr)
        return 0;
    for (size_t i = 0; arr[i]; i++)
        command_destroy(arr[i]);
    free(arr);
    return 0;
}
