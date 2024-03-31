/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#pragma once
    #define SHELL_H

    #include <stdint.h>
    #include <stdbool.h>

    #include "command.h"

typedef struct shell_s {
    bool is_subshell;
    uint8_t exit_code;
    command_t *cmds;
    char **env;
    bool do_exit;
    int out;
    int in;
    int err;
} shell_t;

shell_t *shell_create(void);
int shell_destroy(shell_t *);

int shell_set_code(shell_t *, uint8_t);
int shell_set_cmds(shell_t *, command_t *);
int shell_set_env(shell_t *, char **);
int shell_set_exit(shell_t *, bool);
int shell_set_in(shell_t *, int);
int shell_set_out(shell_t *, int);
int shell_set_err(shell_t *, int);
int shell_set_subshell(shell_t *, bool);

uint8_t shell_get_code(shell_t *);
command_t *shell_get_cmds(shell_t *);
char **shell_get_env(shell_t *);
bool shell_get_exit(shell_t *);
int shell_get_in(shell_t *);
int shell_get_out(shell_t *);
int shell_get_err(shell_t *);
int shell_get_subshell(shell_t *);

int shell_handle_prompt(shell_t *);
int shell_run(shell_t *);
int shell_process_input(shell_t *, char const *);
char **shell_parse_input(shell_t *, char const *);
int shell_process_commands(shell_t *);
int shell_add_command(shell_t *, command_t *);
