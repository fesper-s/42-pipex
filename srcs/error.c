/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 13:17:13 by fesper-s          #+#    #+#             */
/*   Updated: 2022/07/21 14:17:07 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	file_error(void)
{
	ft_putendl_fd(strerror(errno), 2);
	exit(EXIT_FAILURE);
	return (1);
}

int	cmd_error(void)
{
	ft_putendl_fd(strerror(errno), 2);
	exit(EXIT_FAILURE);
	return (1);
}
