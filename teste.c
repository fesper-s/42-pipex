/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:08:21 by fesper-s          #+#    #+#             */
/*   Updated: 2022/07/19 14:05:49 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char	**cmd, char **envp)
{
	int		i;
	char	*env_path;
	char	**path;
	char	*cmd_path;
	char	*temp;

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
		temp = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		i++;
	}
	return (0);
}

char	**get_cmds(char *cmd)
{
	char	**cmds;

	cmds = ft_split(cmd, ' ');
	return (cmds);
}

int	main(int argc, char **argv, char **envp)
{
	char	**cmds;
	int		i;
	char	*path;
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		cmds = get_cmds(argv[2]);
		path = find_path(cmds, envp);
		ft_printf("comando: %s %s, path: %s\n", cmds[0], cmds[1], path);
		execve(path, cmds, envp);
	}
	pid2 = fork();
	if (pid2 == -1)
		return (1);
	if (pid2 == 0)
	{
		cmds = get_cmds(argv[3]);
		path = find_path(cmds, envp);
		ft_printf("comando: %s %s, path: %s\n", cmds[0], cmds[1], path);
		execve(path, cmds, envp);
	}
	return (0);
}
