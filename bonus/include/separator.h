/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#pragma once
    #define SEPARATOR_H

typedef int(*sep_func)();

typedef struct separator_s {
    char const *separator;
    char const *banned;
    sep_func f;
} separator_t;

bool separator_cmp(separator_t *, char const *);
