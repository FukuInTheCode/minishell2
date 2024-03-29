/*
** EPITECH PROJECT, 2024
** builtin_cd.c
** File description:
** builtin_cd.c
*/

#include "my.h"

static bool cd_args_is_good(shell_t *shell, int argc, char **argv)
{
    if (argc > 2) {
        shell_set_code(shell, 1);
        my_dputs(2, "cd: Too many arguments.\n");
        return false;
    }
    return true;
}

static bool cd_new_pwd_is_good(shell_t *shell, char const *new_pwd)
{
    if (!new_pwd || !path_exist(new_pwd)) {
        my_dputs(2, new_pwd);
        my_dputs(2, ": No such file or directory.\n");
        shell_set_code(shell, 1);
        return false;
    }
    if (!path_is_dir(new_pwd)) {
        shell_set_code(shell, 1);
        my_dputs(2, new_pwd);
        my_dputs(2, ": Not a directory.\n");
        return false;
    }
    return true;
}

static int cd_change_wd(shell_t *shell, char const *new_pwd)
{
    char pwd[1001];

    my_memset(pwd, 0, 1001);
    if (!cd_new_pwd_is_good(shell, new_pwd))
        return 0;
    shell_set_oldpwd(shell, env_get(shell->env, "PWD"));
    if (chdir(new_pwd) == -1)
        perror("chdir");
    getcwd(pwd, 1000);
    shell_set_env(shell, env_change(shell->env, "PWD", pwd));
    return 0;
}

int builtin_cd(shell_t *shell, int argc, char **argv)
{
    if (!cd_args_is_good(shell, argc, argv))
        return 0;
    if (argc == 1 || !my_strncmp(argv[1], "~", 2))
        return cd_change_wd(shell, env_get(shell->env, "HOME"));
    if (!my_strncmp(argv[1], "-", 2))
        return cd_change_wd(shell, shell->oldpwd);
    return cd_change_wd(shell, argv[1]);
}
