/*
** EPITECH PROJECT, 2024
** my_dputs.c
** File description:
** my_dputs.c
*/

#include "my.h"

int my_dputs(int fd, char const *s)
{
    return write(fd, s, my_strlen(s));
}
