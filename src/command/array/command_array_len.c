/*
** EPITECH PROJECT, 2024
** command_array_len.c
** File description:
** command_array_len.c
*/

#include "my.h"

size_t command_array_len(command_t **arr)
{
    size_t len = 0;

    for (; arr[len]; len++);
    return len;
}
