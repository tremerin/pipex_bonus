/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgalan-r <fgalan-r@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:45:55 by fgalan-r          #+#    #+#             */
/*   Updated: 2024/01/30 03:58:18 by fgalan-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>


int main(int argc, char **argv, char **envp)
{
    int     pid;
    int     pipefd[2];
    int     status;
    char    **paths;
    char    *temp;
    int i = 0;
    while (envp[i])
    {
        //printf("envp[%d]: %s\n", i, envp[i]);
        if (ft_strnstr(envp[i], "PATH=", 5))
            paths = ft_split(ft_strdup(envp[i] + 5), ':');
        i++;
    }
    i = 0;
    while (paths[i])
    {
        temp = ft_strjoin(paths[i], "/");
        free(paths[i]);
        paths[i] = ft_strdup(temp);
        free(temp);
        i++;
    }
    pipe(pipefd);
    int cmds = 0;
    while (cmds < argc -1)
    {
        pid = fork();
        if (!pid)
        {
            if (cmds == 0 && argc -1 != 1)
            {
                dup2(pipefd[1], 1);
            }
            else if (cmds == argc -2)
            {
                dup2(pipefd[0], 0);
            }
            else
            {
                dup2(pipefd[1], 1);
                dup2(pipefd[0], 0);
            }
            close(pipefd[0]);
            close(pipefd[1]);
            char *cmd_path;
            char **cmd_split = ft_split(argv[cmds + 1], ' ');
            i = 0;
            while (paths[i])
            {
                //printf("path[%d]: %s \n", i, paths[i]);
                cmd_path = ft_strjoin(paths[i], cmd_split[0]);
                if (access(cmd_path, 0) == 0)
                    execve(cmd_path, cmd_split, envp);
                i++;
            }
        }
        cmds++;
        if (cmds == argc -1)
        {
            close(pipefd[0]);
            close(pipefd[1]);
        }
        waitpid(pid, &status, 0);
    }

    /* pid = fork();
    if (!pid)
    {
        dup2(pipefd[0], 0);
        close(pipefd[0]);
        close(pipefd[1]);
        char *cmd_path;
        char **cmd_split = ft_split(argv[2], ' ');
        i = 0;
        while (paths[i])
        {
            //printf("path[%d]: %s \n", i, paths[i]);
            cmd_path = ft_strjoin(paths[i], cmd_split[0]);
            if (access(cmd_path, 0) == 0)
                execve(cmd_path, cmd_split, envp);
            i++;
        }
    } */
    printf("fin\n");
    /* close(pipefd[0]);
    close(pipefd[1]);
    waitpid(pid, &status, 0); */
    return (0);
}