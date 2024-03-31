/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#pragma once
    #define MY_H

    #include <stddef.h>
    #include <signal.h>

    #include "error.h"

typedef enum type_e {
    COMMAND,
    PIPELINE,
    LEFT_RED,
    RIGHT_RED,
    DOUBLE_LEFT_RED,
    DOUBLE_RIGHT_RED,
    OTHER,
    END
} type_t;

typedef struct command_s {
    int argc;
    char **argv;
    type_t type;
    int out;
    int in;
    int err;
    bool do_wait;
    uint8_t status;
    pid_t pid;
    struct command_s *next;
    struct command_s *prev;
} command_t;

command_t *command_create(void);
int command_destroy(command_t *);

int command_set_argc(command_t *, int);
int command_set_argv(command_t *, char **);
int command_set_type(command_t *, type_t);
int command_set_out(command_t *, int);
int command_set_in(command_t *, int);
int command_set_err(command_t *, int);
int command_set_pid(command_t *, pid_t);
int command_set_next(command_t *, command_t *);
int command_set_prev(command_t *, command_t *);
int command_set_status(command_t *, uint8_t);
int command_set_wait(command_t *, bool);

int command_get_argc(command_t *);
char **command_get_argv(command_t *);
type_t command_get_type(command_t *);
int comand_get_out(command_t *);
int command_get_in(command_t *);
int command_get_err(command_t *);
uint8_t command_get_status(command_t *);
bool command_get_wait(command_t *);
command_t *command_get_next(command_t *);
command_t *command_get_prev(command_t *);

int command_add(command_t *, command_t *);
int command_exec(command_t *, void *);
int command_wait(command_t *, void *);
int command_process_exec_error(command_t *, void *);
int command_process_out(command_t *, void *);
int command_process_in(command_t *, void *);
int command_process_err(command_t *, void *);
int command_process_status(command_t *, void *);
int command_process_tokens(command_t *, void *);

static error_t const status_errors[] = {
    {"Segmentation fault (core dumped)\n", NULL},
    {"Segmentation fault\n", NULL},
    {NULL, NULL}
};
