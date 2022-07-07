/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:49:33 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/19 08:29:32 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	find;

	str = (char *) s;
	find = (char) c;
	while (*str != find)
	{
		if (*str == 0)
			return (0);
		str++;
	}
	return (str);
}
