/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 01:01:28 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/11/21 04:57:56 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	msg_err(char *err)
{
	perror(err);
	exit(1);
}

void	ft_free(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_parent(t_pipex *pipex)
{
	if (pipex->cmd1_path)
		free(pipex->cmd1_path);
	if (pipex->cmd2_path)
		free(pipex->cmd2_path);
	if (pipex->cmd1_arg)
		ft_free(pipex->cmd1_arg);
	if (pipex->cmd2_arg)
		ft_free(pipex->cmd2_arg);
	if (pipex->paths)
		ft_free(pipex->paths);
}

void	free_child(t_pipex *pipex)
{
	free_parent(pipex);
	close(pipex->pipefd[0]);
	close(pipex->pipefd[1]);
}
