/*
** EPITECH PROJECT, 2023
** my_strncmp.c
** File description:
** RETURN
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (size_t i = 0; i < n; i++) {
        if (s1[i] != s2[i])
            return (int)(unsigned char)s1[i] - (int)(unsigned char)s2[i];
    }
    return 0;
}
