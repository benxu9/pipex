#include "pipex.h"

int    open_file(char *file, int id)
{
    if (id == 1)
    {
        if (!(access(file, F_OK | X_OK)))
        {
            errors();
        }
        return(open(file,O_RDONLY));
    }
    else
    {
        return (open(file, O_RDWR | O_CREAT | O_TRUNC, 0644));
    }
}