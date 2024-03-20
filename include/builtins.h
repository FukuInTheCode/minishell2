/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef BUILTINS_H
    #define BUILTINS_H

    #include "shell.h"


int builtin_setenv(shell_t *, int, char **);
int builtin_env(shell_t *, int, char **);
int builtin_unsetenv(shell_t *, int, char **);

#endif
