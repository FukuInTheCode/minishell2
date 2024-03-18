/*
** EPITECH PROJECT, 2024
** command_array_create.c
** File description:
** command_array_create.c
*/

#include "my.h"

command_t **command_array_create(void)
{
    command_t **arr = malloc(sizeof(command_t *));

    if (arr)
        *arr = NULL;
    return arr;
}
