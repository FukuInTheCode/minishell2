/*
** EPITECH PROJECT, 2024
** command_status.c
** File description:
** command_status.c
*/

#include "my.h"

static int do_core_dump(int status)
{
    if (WCOREDUMP(status))
        my_dputs(2, "(core dump)");
    my_dputs(2, "\n");
    return 0;
}

int command_status(void *shell_ptr, int status)
{
    if (WIFEXITED(status))
        return shell_set_code(shell_ptr, WEXITSTATUS(status));
    if (WTERMSIG(status) == SIGSEGV) {
        my_dputs(2, "Segmentation fault ");
        do_core_dump(status);
    }
    if (WTERMSIG(status) == SIGILL) {
        my_dputs(2, "Illegal instruction ");
        do_core_dump(status);
    }
    if (WTERMSIG(status) == SIGTRAP) {
        my_dputs(2, "Trace/BPT trap ");
        do_core_dump(status);
    }
    shell_set_code(shell_ptr, WTERMSIG(status) + 128);
    return 0;
}
