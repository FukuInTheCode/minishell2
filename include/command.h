/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef COMMAND_H
    #define COMMAND_H

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
int command_destroy(command_t *cmd);

#endif
