/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 12:57:21 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/18 08:08:50 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t			len_src;
	size_t			i;
	unsigned char	*str_src;

	str_src = (unsigned char *) src;
	len_src = ft_strlen(src);
	if (!dstsize)
		return (len_src);
	i = 0;
	while (str_src[i] != 0 && i < dstsize - 1)
	{
		dst[i] = str_src[i];
		i++;
	}
	dst[i] = 0;
	return (len_src);
}
