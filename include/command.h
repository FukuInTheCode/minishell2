/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef COMMAND_H
    #define COMMAND_H
    #include <stddef.h>
    #include <stdbool.h>

typedef enum type_e {
    COMMAND,
    PIPE_T,
    LEFT_RED,
    LEFT_DBLRED,
    RIGHT_RED,
    RIGHT_DBLRED,
    FILE_T,
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
int command_destroy(command_t *);
int command_set_argc(command_t *, int);
int command_set_argv(command_t *, char **);
int command_set_type(command_t *, type_t);
int command_set_in(command_t *, int);
int command_path(command_t *, void *);
int command_exec(command_t *, void *);
int command_error(command_t *, int, void *);
int command_status(void *, int);

command_t **command_array_create(void);
int command_array_destroy(command_t **);
size_t command_array_len(command_t **);
command_t **command_array_add(command_t **, command_t *);
int command_array_pipe(command_t **);
int command_array_redirection(command_t **);
int command_array_error(command_t **, void *);
int command_array_exec(command_t **, void *);

bool command_is_empty(command_t *);
int command_check_pipe(command_t *, command_t **, size_t, void *);

#endif
