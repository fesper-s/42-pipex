/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:17:13 by fesper-s          #+#    #+#             */
/*   Updated: 2022/07/28 13:20:11 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *arg)
{
	perror(arg);
	exit(EXIT_FAILURE);
}

void	cmd_error(char *cmd)
{
	ft_putstr_fd("command not found: ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

void	fork_error(void)
{
	ft_putstr_fd(strerror(10), 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}

int		pipe_error(void)
{
	ft_putstr_fd(strerror(32), 2);
	ft_putchar_fd('\n', 2);
	return (0);
}
