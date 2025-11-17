#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

#include "libft/libft.h"

int ft_pipex(char **argv, char **envp);
void    ft_file1(char *file1);
void    ft_file2(char *file2);

char **find_path(char **envp);
char *find_cmd_path(char **paths, char *cmd);
void parse_cmds(char **argv, char **envp, char ***cmd1_arg, char ***cmd2_arg, char **cmd1_path, char **cmd2_path);

int child1(char **argv, char **envp, int *pipefd, char *cmd1_path, char **cmd1_arg);
int child2(char **argv, char **envp, int *pipefd, char *cmd2_path, char **cmd2_arg);
#endif