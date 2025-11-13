#include "pipex.h"

int child1(char **argv, char **envp, int *pipefd, char **cmd1_arg, char *cmd1_path)
{
    ft_file1(argv[1]);
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);
    execve(cmd1_path, cmd1_arg, envp);
    perror("execve");
    exit(1);
}

int child2(char **argv, char **envp, int *pipefd, char **cmd2_arg, char *cmd2_path)
{
    dup2(pipefd[0], STDIN_FILENO);
    ft_file2(argv[4]);
    close(pipefd[0]);
    close(pipefd[1]);
    execve(cmd2_path, cmd2_arg, envp);
    perror("execve");
    exit(1);
}

int ft_pipex(char **argv, char **envp)
{
    pid_t pid1;
    pid_t pid2;
    int pipefd[2];
    
    if(pipe(pipefd) == -1)
    {
        perror("pipe");
        return(1);
    }
    pid1 = fork();
    if (pid < 0)
    {
        perror("fork");
        return(1);
    }
    if (pid1 == 0)
        child1(argv, envp, pipefd);
    pid2 = fork();
    if (pid2 < 0)
    {
        perror("fork");
        return(1);
    }
    if (pid2 == 0)
        child2(argv, envp, pipefd);

    close(pipefd[0]);
    close(pipefd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    return(0);
}