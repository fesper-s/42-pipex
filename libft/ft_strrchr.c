/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:46:33 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/30 07:53:35 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	find;
	size_t	len_str;

	str = (char *) s;
	find = (char) c;
	len_str = ft_strlen(str) + 1;
	while (len_str--)
	{
		if (str[len_str] == find)
			return (&str[len_str]);
	}
	return (0);
}
