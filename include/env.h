/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef ENV_H
    #define ENV_H

    #include <stdbool.h>
    #include <stddef.h>

char *env_val_concat(char const *, char const *);
bool env_val_is_good(char const *);
char **env_add(char **, char const *);
bool env_contains(char **, char const *);
char **env_remove(char **, char const *);
char **env_copy(char **);
int env_destroy(char **);
size_t env_len(char **);
char **env_change(char **, char const *, char const *);

#endif
