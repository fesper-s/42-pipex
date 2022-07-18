/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:08:21 by fesper-s          #+#    #+#             */
/*   Updated: 2022/07/18 09:15:52 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char **argv, char **envp)
{
	int		i;
	char	*env_path;
	char	**path;
	char	*cmd_path;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
			env_path = ft_strnstr(envp[i], "PATH=", 5);
		i++;
	}
	env_path = ft_strtrim(env_path, "PATH=");
	path = ft_split(env_path, ':');
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(path[i], argv[1]);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	char	*path;

	(void) argc;
	(void) argv;
	path = find_path(argv, envp);
	if (!path)
	{
		perror(path);
		return (-1);
	}
	execve(path, &argv[1], envp);
	free(path);
	return (0);
}
