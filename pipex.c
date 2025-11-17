#include "pipex.h"

int child1(char **argv, char **envp, int *pipefd, char *cmd1_path, char **cmd1_arg)
{
    ft_file1(argv[1]);
    if (dup2(pipefd[1], STDOUT_FILENO) == -1)
    {
        perror("dup2 pipe write");
        exit(1);
    }
    close(pipefd[0]);
    close(pipefd[1]);
    execve(cmd1_path, cmd1_arg, envp);
    perror("execve");
    exit(1);
}

int child2(char **argv, char **envp, int *pipefd, char *cmd2_path, char **cmd2_arg)
{
    if((dup2(pipefd[0], STDIN_FILENO)) == -1)
    {
        perror("dup2 pipe read");
        exit(1);
    }
    ft_file2(argv[4]);
    close(pipefd[0]);
    close(pipefd[1]);
    execve(cmd2_path, cmd2_arg, envp);
    perror("execve");
    exit(1);
}

int	ft_pipex(char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		pipefd[2];
	char	**cmd1_arg;
	char	**cmd2_arg;
	char	*cmd1_path;
	char	*cmd2_path;

	parse_cmds(argv, envp, &cmd1_arg, &cmd2_arg, &cmd1_path, &cmd2_path);
	if (pipe(pipefd) == -1)
	{
		perror("pipe");
		exit(1);
	}
	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid1 == 0)
		child1(argv, envp, pipefd, cmd1_path, cmd1_arg);
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork");
		exit(1);
	}
	if (pid2 == 0)
		child2(argv, envp, pipefd, cmd2_path, cmd2_arg);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
    free(cmd1_path);
	free(cmd2_path);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 5)
	{
		write(1, "./pipex file1 cmd1 cmd2 file2\n", 31);
		return (1);
	}
	return (ft_pipex(argv, envp));
}
