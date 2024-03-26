/*
** EPITECH PROJECT, 2024
** my_strtok.c
** File description:
** my_strtok.c
*/

#include "my.h"
static bool is_delim(char c, char const *delim)
{
    for (int i = 0; delim[i]; i++)
        if (c == delim[i])
            return true;
    return false;
}

static int change_str_save(char **save, int i)
{
    if (!(*save)[i]) {
        *save = NULL;
        return 0;
    }
    (*save)[i] = 0;
    (*save) = *save + i + 1;
    return 0;
}

char *my_strtok(char *s, char const *delim)
{
    static char *s_ptr_save = NULL;
    int i = 0;
    char *ret = NULL;

    if (s)
        s_ptr_save = s;
    else if (!s_ptr_save)
            return NULL;
    for (; s_ptr_save[i] && is_delim(s_ptr_save[i], delim); i++);
    if (!s_ptr_save[i])
        return NULL;
    ret = s_ptr_save + i;
    for (; s_ptr_save[i] && !is_delim(s_ptr_save[i], delim); i++);
    change_str_save(&s_ptr_save, i);
    return ret;
}
