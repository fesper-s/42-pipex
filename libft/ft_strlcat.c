/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:45:19 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/17 14:25:56 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	init_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	init_dst = ft_strlen(dst);
	len_src = ft_strlen((char *) src);
	i = 0;
	if (init_dst + 1 < dstsize && dstsize > 0)
	{
		while (src[i] && init_dst + i < dstsize - 1)
		{
			dst[len_dst] = src[i];
			len_dst++;
			i++;
		}
	}
	dst[len_dst] = 0;
	if (dstsize > init_dst)
		return (init_dst + len_src);
	return (len_src + dstsize);
}
