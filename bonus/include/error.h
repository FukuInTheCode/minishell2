/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#pragma once
    #define ERROR_H


typedef int(*err_func)();

typedef struct error_s {
    char const *err;
    err_func f;
} error_t;

int error_put(error_t *);
