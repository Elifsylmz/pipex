#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int ft_pipex(char **argv, char **envp);

void    ft_file1(char *file1);
void    ft_file2(char *file2);

char **find_path(char **envp);
char *find_cmd_path(char **paths, char *cmd);

#endif