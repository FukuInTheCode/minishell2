/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef SHELL_H
    #define SHELL_H

    #include "command.h"

typedef struct shell_s {
    int return_code;
    char *user_input;
    command_t **cmds;
    char **env;
    char *oldpwd;
    char *prompt;
} shell_t;

shell_t *shell_create(void);
int shell_destroy(shell_t *);
int shell_set_code(shell_t *, int);
int shell_set_cmds(shell_t *, command_t **);
int shell_set_input(shell_t *, char *);
int shell_set_oldpwd(shell_t *, char const *);
int shell_run(shell_t *);

#endif
