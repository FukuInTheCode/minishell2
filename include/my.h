/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <math.h>
    #include <stdlib.h>
    #include <signal.h>
    #include <stdbool.h>
    #include <string.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <fcntl.h>

    #include "command.h"
    #include "shell.h"
    #include "env.h"
    #include "path.h"
    #include "builtins.h"
    #include "parser.h"

    #define SYS_OUT 1
    #define SYS_IN 0

char *my_strdup(char const *);
char *my_strtok(char *, char const *);
size_t my_strlen(char const *);
void *my_memset(char *, char, size_t);
char **my_str_to_word_array(char *, char const *);
int my_free_word_array(char **);
size_t my_len_word_array(char **);
int my_dputs(int, char const *);
char *my_strcat(char *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strndup(char const *, size_t);
int my_strcmp(char const *, char const *);

#endif
