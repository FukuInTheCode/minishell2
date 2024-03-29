/*
** EPITECH PROJECT, 2024
** command_error.c
** File description:
** command_error.c
*/

#include "my.h"

static int command_other_error(command_t *command, int err, shell_t *shell)
{
    if (err == ENOEXEC) {
        my_dputs(2, command->argv[0]);
        my_dputs(2, ": Exec format error. Wrong Architecture.\n");
        return shell_set_code(shell, 1);
    }
    return 0;
}

int command_error(command_t *command, int err, void *shell_ptr)
{
    shell_set_exit(shell_ptr, true);
    if (err == EACCES) {
        my_dputs(2, command->argv[0]);
        my_dputs(2, ": Permission denied.\n");
        return shell_set_code(shell_ptr, 1);
    }
    if (err == EISDIR) {
        my_dputs(2, command->argv[0]);
        my_dputs(2, ": Is a directory\n");
        return shell_set_code(shell_ptr, 1);
    }
    if (err == ENOENT || (**command->argv != '.'
        && **command->argv != '/')) {
        my_dputs(2, command->argv[0]);
        my_dputs(2, ": Command not found.\n");
        return shell_set_code(shell_ptr, 1);
    }
    return command_other_error(command, err, shell_ptr);
}
