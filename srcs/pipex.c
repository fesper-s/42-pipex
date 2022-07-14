/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:10:36 by fesper-s          #+#    #+#             */
/*   Updated: 2022/07/13 13:16:20 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	char	**cmds;
	char	*path;

	if (argc != 5)
		return (1);
	cmds[0] = argv[2];
	cmds[1] = argv[3];
	path = ft_path(**envp, **cmds);
	return (0);
}
