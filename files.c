/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 01:01:31 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/11/21 03:17:57 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_infile(t_pipex *pipex)
{
	pipex->infile = open(pipex->argv[1], O_RDONLY);
	if (pipex->infile == -1)
	{
		perror(pipex->argv[1]);
		free_child(pipex);
		exit(1);
	}
	if (dup2(pipex->infile, STDIN_FILENO) == -1)
	{
		perror("dup2 infile");
		close(pipex->infile);
		free_child(pipex);
		exit(1);
	}
	close(pipex->infile);
}

void	open_outfile(t_pipex *pipex)
{
	pipex->outfile = open(pipex->argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->outfile == -1)
	{
		perror(pipex->argv[4]);
		free_child(pipex);
		exit(1);
	}
	if (dup2(pipex->outfile, STDOUT_FILENO) == -1)
	{
		perror("dup2 outfile");
		close(pipex->outfile);
		free_child(pipex);
		exit(1);
	}
	close(pipex->outfile);
}
