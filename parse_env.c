/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bxu <bxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 20:52:36 by bxu               #+#    #+#             */
/*   Updated: 2022/08/15 20:53:45 by bxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_path(char *path)
{
	char	*tmp;
	char	**env_paths;
	int		i;

	tmp = (path + 5);
	env_paths = ft_split(tmp, ':');
	i = 0;
	while (env_paths[i])
	{
		tmp = env_paths[i];
		env_paths[i] = ft_strjoin(tmp, "/");
		i++;
	}
	return (env_paths);
}

char	**parse_env(char	**envp)
{
	int		i;
	char	*path;
	char	**env_paths;

	i = 0;
	while (envp[i] != NULL && ft_strncmp(envp[i], "PATH=", 5))
	{
		i++;
	}
	path = envp[i];
	env_paths = split_path(path);
	return (env_paths);
}

char	*check_access(char	*cmd, char	**envp_paths)
{
	char	*test_path;
	int		i;
	char	**cmd1;

	cmd1 = ft_split(cmd, ' ');
	i = 0;
	while (envp_paths[i])
	{
		test_path = ft_strjoin(envp_paths[i], cmd1[0]);
		if (access(test_path, F_OK | X_OK) == 0)
			return (test_path);
		i++;
	}
	return (NULL);
}
