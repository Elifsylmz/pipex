#include "pipex.h"

void ft_free(char **arr)
{
	int i;

	if (!arr)
		return;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char    **find_path(char **envp)
{
    char *cmd_path;
    char **paths;
    int i;

    i = 0;
    while(envp[i])
    {
        if(ft_strncmp(envp[i], "PATH=", 5) == 0)
            break;
        i++;
    }
    if (!envp[i])
        return(NULL);
    cmd_path = envp[i] + 5;
    paths = ft_split(cmd_path, ':');
    return(paths);
}

char *find_cmd_path(char **paths, char *cmd)
{
    int i;
    char *tmp;
    char *full_path;
    
    i = 0;
    if(!cmd)
        return(NULL);
    if(ft_strchr(cmd, '/'))
    {
        if(access(cmd, X_OK) == 0)
            return(ft_strdup(cmd));
        else
            return(NULL);
    }
    if(!paths)
        return(NULL);
    while(paths[i])
    {
        tmp = ft_strjoin(paths[i], "/");
        if (!tmp)
            return(NULL);
        full_path = ft_strjoin(tmp, cmd);
        free(tmp);
        if (!full_path)
            return(NULL);
        if(access(full_path, X_OK) == 0)
            return (full_path);
        free(full_path);
        i++;
    }
    return(NULL);

}

void parse_cmds(char **argv, char **envp, char ***cmd1_arg, char ***cmd2_arg, char **cmd1_path, char **cmd2_path)
{
    char **paths;

    paths = find_path(envp);

    *cmd1_arg = ft_split(argv[2], ' ');
    *cmd2_arg = ft_split(argv[3], ' ');

    if (!*cmd1_arg || !*cmd2_arg)
    {
        perror("cmd split");
        ft_free(paths);
        ft_free(*cmd1_arg);
        ft_free(*cmd2_arg);
        exit(1);
    }

    *cmd1_path = find_cmd_path(paths, (*cmd1_arg)[0]);
    *cmd2_path = find_cmd_path(paths, (*cmd2_arg)[0]);

    ft_free(paths);
    if (!*cmd1_path)
    {
        write(2, "pipex: command not found: ", 26);
        write(2, (*cmd1_arg)[0], strlen((*cmd1_arg)[0]));
        write(2, "\n", 1);
        ft_free(*cmd1_arg);
        ft_free(*cmd2_arg);
        exit(127);
    }

    if (!*cmd2_path)
    {
        write(2, "pipex: command not found: ", 26);
        write(2, (*cmd2_arg)[0], strlen((*cmd2_arg)[0]));
        write(2, "\n", 1);
        ft_free(*cmd1_arg);
        ft_free(*cmd2_arg);
        exit(127);
    }
}

