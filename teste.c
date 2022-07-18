/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:08:21 by fesper-s          #+#    #+#             */
/*   Updated: 2022/07/18 14:50:59 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char	*cmd, char **envp)
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
		cmd_path = ft_strjoin(path[i], cmd);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (0);
}

char	**get_cmds(char **argv)
{
	char	**cmds;

	cmds = ft_split(argv[1], ' ');
	return (cmds);
}

int	main(int argc, char **argv, char **envp)
{
	char	**cmds;
	int		i;

	cmds = get_cmds(argv);
	while (cmds[i])
	{
		printf("%s\n", cmds[i]);
		i++;
	}
	return (0);
}
