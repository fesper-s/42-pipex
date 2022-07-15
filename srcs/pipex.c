/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:10:36 by fesper-s          #+#    #+#             */
/*   Updated: 2022/07/15 14:51:24 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != '\0')
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			break ;
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	char	**path;

	if (argc != 5)
		return (1);
	path = ft_path(enpv);
	execve(path, argv, envp);
	return (0);
}
