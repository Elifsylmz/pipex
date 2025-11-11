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
    //dosya başarıyla açıldıysa;
    //read() veya dup2() çağrılarını yap
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

    //yine dup2() kullanılabilir
    close(outfile);
}

int ft_pipex(char **argv, char **envp)
{

}

int main(int argc, char **argv, char **envp)
{
    if(argc == 5)
    {
        ft_pipex(argv, envp);
    }
    else
    {
        write("error?")
    }
}