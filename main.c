#include "pipex.h"

void    ft_file1(char *file1)
{
    int infile;

    infile = open(file1, O_RDONLY);

    if (infile == -1)
    {
        perror("open");
        exit(1);
    }

    dup2(infile, STDIN_FILENO);

    close(infile);
}

void   ft_file2(char *file2)
{
    int outfile;

    outfile = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (outfile == -1)
    {
        perror("open");
        exit(1);
    }

    dup2(outfile, STDOUT_FILENO);

    close(outfile);
}

int find_path(char **argv, char **envp)
{
    char *cmd_path;
    char *cmd1_path;
    char *cmd2_path;
    int i = 0;

    while(envp[i])
    {
        if((ft_strncmp(envp[i], "PATH=", 5) == 0))  // aradığımız ' PATH= '   
            break;
        i++;
    }
    cmd_path = envp[i] + 5;
    ft_split(cmd_path, ':');


    char **cmd1_arg;
    char **cmd2_arg;
    
    cmd1_arg = ft_split(argv[2], ' ');
    cmd2_arg = ft_split(argv[3], ' ');
}

int idk(char **argv, char **envp)
{
    int pipefd[2];
    pipe(pipefd);
    pid_t pid1;
    pid_t pid2;

    pid1 = fork();
    if(pid1 == 0) // child 1
    {
        ft_file1(argv[1]);
        dup2(pipefd[1], STDOUT_FILENO); // pipe yazma ucu oluyor
        close(pipefd[0]);
        close(pipefd[1]);
        execve(cmd1_path, cmd1_arg, envp);
        // path alıcak
        // split edip komutu ve komut argümanlarını vericek
    }

    pid2 = fork();
    if (pid2 == 0) // child 2
    {
        dup2(pipefd[0], STDIN_FILENO); // pipe okuma ucu
        ft_file2(argv[4]);
        close(pipefd[0]);
        close(pipefd[1]);
        execve();
    }

}


int main(int argc, char **argv, char **envp)
{
    if(argc == 5)
    {
        idk(argv, envp);
    }
    else
    {
        write("error?")
    }
}