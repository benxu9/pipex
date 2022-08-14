#include "pipex.h"


typedef struct data_1 {
	char **path;
} data_1;

void	errors(void)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	exit(EXIT_FAILURE);
}

void	pipe_f(char *cmd, char **args, char **env)
{
	int fd[2];
	pid_t pid;

	pipe(fd);
	printf("before the fork man");
	pid = fork();
	if (pid < 0)
		errors();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		execve(cmd, args, env);
		perror("deomomefsdf");
	}
	else
	{
		int status;
		waitpid(pid, &status, WNOHANG);
		printf("finished with child");
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
	printf("yoyoyo");
}


int	main(int argc, char **argv, char **envp)
{
	//data_1 data;
	char 	**env_paths;
	char 	*cmd1;
	char	*cmd2;
	char	**args1;
	char	**args2;
	int		file1_fd;
	int		file2_fd;

	if (argc == 5) {
		// printf("4 args    ");
		 ft_putstr_fd(argv[3], 1);
		 char **split = ft_split(argv[3], ' ');
		 ft_putstr_fd(split[1], 1);
	}
	//open file1 and file2
	file1_fd = open_file(argv[1], 1);
	file2_fd = open_file(argv[4], 2);
	if (file1_fd < 0 || file2_fd < 0)
	{
		errors();
	}

	env_paths = parse_env(envp);
	//check acess of the env_path with the commands
	cmd1 = check_access(argv[2], env_paths);
	args1 = ft_split(cmd1, ' ');
	ft_putstr_fd(args1[0], 1);
	cmd2 = check_access(argv[3], env_paths);
	if (cmd2 == NULL)
	{
		ft_putstr_fd("wtf", 1);
	}
	args2 = ft_split(argv[3], ' ');
	//ft_putstr_fd(args2[1], 1);

	dup2(file1_fd, STDIN_FILENO);
	dup2(file2_fd, STDOUT_FILENO);
	
	//char * const argv3[] = {"/bin/wc", "-l", NULL};
	//pipe first arg into second
	pipe_f(cmd1, args1, envp);
	execve(cmd2, args2, envp);
	
	return (1);
}
