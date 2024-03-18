/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** function that allocates memory and copies the string given as argument in it
*/

#include "my.h"

char *my_strdup(char const *src)
{
    int length = 0;
    char *dest;
    int i = 0;

    if (src == NULL)
        return NULL;
    length = my_strlen(src);
    dest = malloc(sizeof(char) * (length + 1));
    for (i = 0; i < length; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return (dest);
}
