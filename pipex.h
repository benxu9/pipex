#ifndef PIPEX_H
# define PIPEX_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#include "libft/libft.h"

//passing the envp and getting the correct path for command
char    **parse_env(char **envp);
//char    **split_path(char *path);
int     open_file(char *file, int id);
void    errors();
char    *check_access(char *cmd, char **envp_paths);

#endif