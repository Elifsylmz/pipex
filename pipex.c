/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 01:01:16 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/11/21 04:57:48 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_pipex(t_pipex *pipex, char **argv, char **envp)
{
	pipex->argv = argv;
	pipex->envp = envp;
	pipex->cmd1_arg = NULL;
	pipex->cmd2_arg = NULL;
	pipex->cmd1_path = NULL;
	pipex->cmd2_path = NULL;
	pipex->paths = NULL;
}

int	ft_pipex(t_pipex *pipex)
{
	if (pipe(pipex->pipefd) == -1)
		msg_err("pipe");
	parse_args(pipex);
	pipex->pid1 = fork();
	if (pipex->pid1 < 0)
		msg_err("fork");
	if (pipex->pid1 == 0)
		child1(pipex);
	pipex->pid2 = fork();
	if (pipex->pid2 < 0)
		msg_err("fork");
	if (pipex->pid2 == 0)
		child2(pipex);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	free_parent(pipex);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc != 5)
	{
		write(2, "./pipex file1 cmd1 cmd2 file2\n", 31);
		return (1);
	}
	init_pipex(&pipex, argv, envp);
	ft_pipex(&pipex);
	return (0);
}
