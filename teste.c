/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:08:21 by fesper-s          #+#    #+#             */
/*   Updated: 2022/07/20 14:49:57 by fesper-s         ###   ########.fr       */
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
	path = ft_split(env_path + 5, ':');
	i = -1;
	while (path[++i])
	{
		temp = ft_strjoin(path[i], "/");
		cmd_path = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
	}
	return (0);
}

static char	**get_cmds(char *cmd)
{
	char	**cmds;

	cmds = ft_split(cmd, ' ');
	return (cmds);
}

static int	child(pid_t pid, int *fd, char **argv, char **envp)
{
	char	**cmds;
	char	*path;
	int		file;

	file = open(argv[1], O_RDONLY);
	pid = fork();
	if (pid == -1)
		return (2);
	if (pid == 0)
	{
		dup2(file, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		cmds = get_cmds(argv[2]);
		path = find_path(cmds, envp);
		execve(path, cmds, NULL);
		close(file);
	}
	return (pid);
}

static int	child2(pid_t pid2, int *fd, char **argv, char **envp)
{
	char	**cmds;
	char	*path;
	int		file2;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	pid2 = fork();
	if (pid2 == -1)
		return (2);
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(file2, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		cmds = get_cmds(argv[3]);
		path = find_path(cmds, envp);
		execve(path, cmds, NULL);
		close(file2);
	}
	return (pid2);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];

	if (pipe(fd) == -1)
		return (1);
	pid = 0;
	pid2 = 0;
	(void) argc;
	pid = child(pid, fd, argv, envp);
	pid2 = child2(pid2, fd, argv, envp);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
