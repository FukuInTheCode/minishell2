/*
** EPITECH PROJECT, 2024
** command_path.c
** File description:
** command_path.c
*/

#include "my.h"
#include "path.h"

static bool command_is_builtins(command_t *command)
{
    if (!my_strcmp(command->argv[0], "env"))
        return true;
    if (!my_strcmp(command->argv[0], "cd"))
        return true;
    if (!my_strcmp(command->argv[0], "unsetenv"))
        return true;
    if (!my_strcmp(command->argv[0], "setenv"))
        return true;
    if (!my_strcmp(command->argv[0], "exit"))
        return true;
    return false;
}

static int command_find_path(command_t *command, shell_t *shell)
{
    char *path_val = env_get(shell->env, "PATH");
    char **path_arr = my_str_to_word_array(path_val, ":");
    char *path_tmp = NULL;

    if (!path_val || !path_arr)
        return 0;
    for (size_t i = 0; path_arr[i]; i++) {
        path_tmp = path_concat(path_arr[i], command->argv[0]);
        if (path_exist(path_tmp)) {
            free(command->argv[0]);
            command->argv[0] = path_tmp;
            break;
        }
        free(path_tmp);
    }
    my_free_word_array(path_arr);
    return 0;
}

int command_path(command_t *command, void *shell_ptr)
{
    if (command->type != COMMAND)
        return 0;
    if (command_is_builtins(command))
        return 0;
    if (path_exist(command->argv[0]))
        return 0;
    return command_find_path(command, shell_ptr);
}
