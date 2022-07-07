/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:04:02 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/19 08:11:20 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*str_dst;
	const char	*str_src;

	if (!dst && !src)
		return (0);
	str_dst = (char *) dst;
	str_src = (const char *) src;
	i = 0;
	while (i < n)
	{
		str_dst[i] = str_src[i];
		i++;
	}
	return (dst);
}
