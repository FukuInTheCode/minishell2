/*
** EPITECH PROJECT, 2024
** command_double_left_redirection.c
** File description:
** command_double_left_redirection.c
*/

#include "my.h"

static char **add_arg(char **env, char const *var)
{
    char **new_env = NULL;
    size_t len = 0;

    if (!env || !var)
        return env;
    len = env_len(env);
    new_env = malloc(sizeof(char *) * (len + 2));
    if (!new_env)
        return env;
    my_memset((void *)new_env, 0, sizeof(char *) * (len + 2));
    for (size_t i = 0; i < len; i++)
        new_env[i] = my_strdup(env[i]);
    new_env[len] = my_strdup(var);
    return new_env;
}

static int add_argv(command_t *curr, char *line)
{
    char **tmp = curr->argv;

    curr->argv = add_arg(curr->argv, line);
    for (size_t i = 0; tmp[i]; i++)
        free(tmp[i]);
    free(tmp);
    return 0;
}

int command_dblleft_redirection(command_t *before, command_t *curr)
{
    char *eof = NULL;
    char *line = NULL;
    size_t len = 0;

    if (curr->type != EOF_T || !curr->argv || !*curr->argv)
        return 1;
    eof = my_strdup(curr->argv[0]);
    for (; getline(&line, &len, stdin) != - 1;) {
        line[my_strlen(line) - 1] = 0;
        if (!my_strcmp(line, eof))
            break;
        add_argv(curr, line);
    }
    return 0;
}
