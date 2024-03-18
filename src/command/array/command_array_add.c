/*
** EPITECH PROJECT, 2024
** command_array_add.c
** File description:
** command_array_add.c
*/

#include "my.h"

command_t **command_array_add(command_t **arr, command_t *cmd)
{
    size_t arr_len = 0;
    command_t **new_arr = NULL;

    if (!arr || !cmd)
        return arr;
    arr_len = command_array_len(arr);
    new_arr = malloc(sizeof(command_t *) * (arr_len + 2));
    if (!new_arr)
        return arr;
    my_memset((void *)new_arr, 0, sizeof(command_t *) * (arr_len + 2));
    for (size_t i = 0; i < arr_len; i++)
        new_arr[i] = arr[i];
    new_arr[arr_len] = cmd;
    free(arr);
    return new_arr;
}
