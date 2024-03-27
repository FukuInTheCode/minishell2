/*
** EPITECH PROJECT, 2024
** command_array_exec.c
** File description:
** command_array_exec.c
*/

#include "my.h"

static int execute_pipeline(command_t **commands, size_t *i,
    void *shell_ptr, bool *do_break)
{
    int error = 0;

    for (; commands[*i] && commands[*i]->type != END; (*i)++) {
        if (commands[*i]->type == COMMAND &&
            commands[*i]->argv && commands[*i]->argv[0])
            error |= command_exec(commands[*i], shell_ptr, commands + *i);
        if (((shell_t *)shell_ptr)->do_exit)
            break;
    }
    if (!commands[*i])
        *do_break = true;
    return error;
}

int command_array_exec(command_t **commands, void *shell_ptr)
{
    bool do_break = false;
    int error = 0;

    for (size_t i = 0; !do_break && commands[i]; i++) {
        error |= execute_pipeline(commands, &i, shell_ptr, &do_break);
        if (error)
            break;
    }
    return error;
}
