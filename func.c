/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eyilmaz <eyilmaz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 01:01:26 by eyilmaz           #+#    #+#             */
/*   Updated: 2025/11/21 03:21:47 by eyilmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**find_path(char **envp)
{
	char	*cmd_path;
	char	**paths;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			cmd_path = envp[i] + 5;
			paths = ft_split(cmd_path, ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}

char	*find_cmd_path(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*full_path;
	int		flag;
	
	flag = 0;
	if (!cmd || !paths)
		return (NULL);
	if (ft_strchr(cmd, '/') && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full_path, X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}

	return (NULL);
}

void	parse_args(t_pipex *pipex)
{
	pipex->paths = find_path(pipex->envp);
	pipex->cmd1_arg = ft_split(pipex->argv[2], ' ');
	pipex->cmd2_arg = ft_split(pipex->argv[3], ' ');
	if (!pipex->cmd1_arg || !pipex->cmd2_arg)
	{
		free_parent(pipex);
		msg_err("cmd split error");
	}
	pipex->cmd1_path = find_cmd_path(pipex->paths, pipex->cmd1_arg[0]);
	pipex->cmd2_path = find_cmd_path(pipex->paths, pipex->cmd2_arg[0]);
}
