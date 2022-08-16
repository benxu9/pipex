/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bxu <bxu@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:30:30 by bxu               #+#    #+#             */
/*   Updated: 2022/08/16 10:35:23 by bxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "libft/libft.h"

char	**parse_env(char **envp);
int		open_file(char *file, int id);
void	errors(void);
char	*check_access(char *cmd, char **envp_paths);
void	exec_cmd(char *cmd, char *args, char **env);

#endif