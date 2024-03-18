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

    #define SYS_OUT 1
    #define SYS_IN 0

typedef enum type_e {
    COMMAND,
    PIPE,
    LEFT_RED,
    LEFT_DBLRED,
    RIGHT_RED,
    RIGHT_DBLRED,
    END
} type_t;

typedef struct command_s {
    int argc;
    char **argv;
    type_t type;
    int out;
    int in;
} command_t;


command_t *command_create(void);

#endif
