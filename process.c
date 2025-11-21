/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 01:01:23 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/11/21 03:17:35 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(t_pipex *pipex)
{
	open_infile(pipex);
	if (dup2(pipex->pipefd[1], STDOUT_FILENO) == -1)
	{
		perror("dup2 pipe write");
		free_child(pipex);
		exit(1);
	}
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	if (pipex->cmd1_path)
	{
		execve(pipex->cmd1_path, pipex->cmd1_arg, pipex->envp);
		perror("execve cmd1");
	}
	else
	{
		write(2, "pipex: command not found: ", 26);
		write(2, pipex->cmd1_arg[0], ft_strlen(pipex->cmd1_arg[0]));
		write(2, "\n", 1);
		exit(127);
	}
	free_child(pipex);
	exit(1);
}

void	child2(t_pipex *pipex)
{
	open_outfile(pipex);
	if (dup2(pipex->pipefd[0], STDIN_FILENO) == -1)
	{
		perror("dup2 pipe read");
		free_child(pipex);
		exit(1);
	}
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	if (pipex->cmd2_path)
	{
		execve(pipex->cmd2_path, pipex->cmd2_arg, pipex->envp);
		perror("execve cmd2");
	}
	else
	{
		write(2, "pipex: command not found: ", 26);
		write(2, pipex->cmd2_arg[0], ft_strlen(pipex->cmd2_arg[0]));
		write(2, "\n", 1);
		exit(127);
	}
	free_child(pipex);
	exit(1);
}
