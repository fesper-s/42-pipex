/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 11:48:32 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/30 08:02:09 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*str_dst;
	const char	*str_src;

	if (!len || dst == src)
		return (dst);
	str_dst = (char *) dst;
	str_src = (const char *) src;
	if (dst > src)
	{
		while (len--)
			str_dst[len] = str_src[len];
	}
	else
	{
		str_dst = ft_memcpy(str_dst, str_src, len);
	}
	return (dst);
}
