#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    if(argc != 5)
    {
        write(1, "./pipex file1 cmd1 cmd2 file2", 29);
        return(1);
    }
    else
    {
         return ft_pipex(argv, envp);
    }
}