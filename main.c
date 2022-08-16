/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bxu <bxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:39:53 by bxu               #+#    #+#             */
/*   Updated: 2022/08/15 20:40:09 by bxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	errors(void)
{
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	exit(EXIT_FAILURE);
}

void	exec_cmd(char *cmd, char *args, char **env)
{
	char	**split;

	split = ft_split(args, ' ');
	execve(cmd, split, env);
}

void	pipe_f(char *cmd, char *args, char **env)
{
	int		fd[2];
	pid_t	pid;
	int		status;

	pipe(fd);
	pid = fork();
	if (pid < 0)
		errors();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		exec_cmd(cmd, args, env);
		perror("deomomefsdf");
	}
	else
	{
		waitpid(pid, &status, WNOHANG);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
}

int	main(int argc, char **argv, char **envp)
{
	char	**env_paths;
	char	*cmd1;
	char	*cmd2;
	int		file1_fd;
	int		file2_fd;

	if (argc < 5)
	{
		errors();
	}
	file1_fd = open_file(argv[1], 1);
	file2_fd = open_file(argv[4], 2);
	if (file1_fd < 0 || file2_fd < 0)
	{
		errors();
	}
	env_paths = parse_env(envp);
	cmd1 = check_access(argv[2], env_paths);
	ft_putstr_fd(cmd1, 1);
	cmd2 = check_access(argv[3], env_paths);
	dup2(file1_fd, STDIN_FILENO);
	dup2(file2_fd, STDOUT_FILENO);
	pipe_f(cmd1, argv[2], envp);
	exec_cmd(cmd2, argv[3], envp);
	return (1);
}
