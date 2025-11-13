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
    if (dup2(infile, STDIN_FILENO) == -1)
    {
        perror("dup2 infile");
        close(infile);
        exit(1);
    }
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

    if (dup2(outfile, STDOUT_FILENO) == -1)
    {
        perror("dup2 outfile");
        close(outfile);
        exit(1);
    }
    close(outfile);
}