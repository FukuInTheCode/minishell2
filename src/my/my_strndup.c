/*
** EPITECH PROJECT, 2024
** my_strndup.c
** File description:
** my_strndup.c
*/

#include "my.h"

char *my_strndup(char const *s, size_t n)
{
    char *dupped = NULL;

    if (n > my_strlen(s))
        n = my_strlen(s);
    dupped = malloc(n + 1);
    if (!dupped)
        return NULL;
    my_memset((void *)dupped, 0, n + 1);
    for (size_t i = 0; i < n; i++)
        dupped[i] = s[i];
    return dupped;
}
