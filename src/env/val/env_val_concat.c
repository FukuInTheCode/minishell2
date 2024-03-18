/*
** EPITECH PROJECT, 2024
** env_val_concat.c
** File description:
** env_val_concat.c
*/

#include "my.h"

char *env_val_concat(char const *var, char const *val)
{
    char *catted = NULL;
    size_t len = 0;

    if (!var)
        return NULL;
    len += my_strlen(var) + 1;
    len += my_strlen(val);
    catted = malloc(len + 1);
    if (!catted)
        return NULL;
    my_memset((void *)catted, 0, len + 1);
    my_strcat(catted, var);
    my_strcat(catted, "=");
    my_strcat(catted, val);
    return catted;
}
