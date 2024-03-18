/*
** EPITECH PROJECT, 2024
** my_str_to_word_array.c
** File description:
** my_str_to_word_array.c
*/

#include "my.h"

static size_t count_word(char *s, char const *delim)
{
    size_t count = 0;
    char *dupped = my_strdup(s);

    if (!dupped)
        return 0;
    for (char *t = my_strtok(dupped, delim); t; t = my_strtok(NULL, delim))
        count++;
    free(dupped);
    return count;
}

static char **fill_arr(char **arr, char *s, char const *delim)
{
    char *dupped = my_strdup(s);
    size_t i = 0;

    if (!dupped)
        return NULL;
    for (char *t = my_strtok(dupped, delim); t; t = my_strtok(NULL, delim)) {
        arr[i] = my_strdup(t);
        if (!arr[i])
            return NULL;
        i++;
    }
    return arr;
}

char **my_str_to_word_array(char *s, char const *delim)
{
    char **arr = NULL;
    size_t count = 0;

    if (!s || !delim)
        return NULL;
    count = count_word(s, delim);
    arr = malloc(sizeof(char *) * (count + 1));
    if (!arr)
        return NULL;
    my_memset((void *)arr, 0, sizeof(char *) * (count + 1));
    return fill_arr(arr, s, delim);
}
