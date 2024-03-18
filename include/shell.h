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
} shell_t;

shell_t *shell_create(void);
int shell_destroy(shell_t *);

#endif
