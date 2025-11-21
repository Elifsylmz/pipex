/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 01:01:21 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/11/21 04:58:05 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "libft/libft.h"

typedef struct s_pipex
{
	int		pipefd[2];
	int		infile;
	int		outfile;
	pid_t	pid1;
	pid_t	pid2;
	char	**cmd1_arg;
	char	**cmd2_arg;
	char	*cmd1_path;
	char	*cmd2_path;
	char	**paths;
	char	**argv;
	char	**envp;
}	t_pipex;

int		ft_pipex(t_pipex *pipex);

void	open_infile(t_pipex *pipex);
void	open_outfile(t_pipex *pipex);

char	**find_path(char **envp);
char	*find_cmd_path(char **paths, char *cmd);
void	parse_args(t_pipex *pipex);

void	child1(t_pipex *pipex);
void	child2(t_pipex *pipex);

void	msg_err(char *err);
void	ft_free(char **arr);
void	free_parent(t_pipex *pipex);
void	free_child(t_pipex *pipex);
#endif