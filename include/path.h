/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef PATH_H
    #define PATH_H

    #include <stdbool.h>

char *path_concat(char const *, char const *);
bool path_is_executable(char const *);
bool path_is_dir(char const *);
bool path_exist(char const *);
bool path_writable(char const *);

#endif
