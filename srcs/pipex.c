/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:10:36 by fesper-s          #+#    #+#             */
/*   Updated: 2022/07/25 14:32:02 by fesper-s         ###   ########.fr       */
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

	i = -1;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
			env_path = ft_strnstr(envp[i], "PATH=", 5);
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
	perror(cmd[0]);
	return (0);
}

static char	**get_cmds(char *cmd)
{
	char	**cmds;
	char	**temp;
	char	**temp2;
	int		i;

	i = 0;
	if (ft_memchr(cmd, '/', 1))
	{
		temp = ft_split(cmd, ' ');
		if (access(temp[0], F_OK | X_OK) == 0)
		{
			temp2 = ft_split(cmd, '/');
			while (temp2[++i])
			cmds = ft_split(temp2[i], ' ');
		}
		else
			return (0);
	}
	else
		cmds = ft_split(cmd, ' ');
	return (cmds);
}

static int	child(int *fd, char **argv, char **envp)
{
	pid_t	pid;
	char	**cmds;
	char	*path;
	int		file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
		return (error(argv[1]));
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
		execve(path, cmds, envp);
		close(file);
	}
	return (pid);
}

static int	child2(int *fd, char **argv, char **envp)
{
	pid_t	pid2;
	char	**cmds;
	char	*path;
	int		file2;

	file2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file2 == -1)
		return (error(argv[4]));
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
		execve(path, cmds, envp);
		close(file2);
	}
	return (pid2);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid;
	pid_t	pid2;
	int		fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			return (1);
		pid = child(fd, argv, envp);
		pid2 = child2(fd, argv, envp);
		if (pid == 1)
			return (pid);
		if (pid2 == 1)
			return (pid2);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	return (0);
}
