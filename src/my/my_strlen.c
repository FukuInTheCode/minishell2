/*
** EPITECH PROJECT, 2024
** my_strlen.c
** File description:
** my_strlen.c
*/

#include "my.h"

size_t my_strlen(char const *s)
{
    size_t len = 0;

    if (!s)
        return 0;
    for (; s[len]; len++);
    return len;
}
