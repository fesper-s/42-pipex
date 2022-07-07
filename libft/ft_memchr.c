/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 13:59:33 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/17 09:38:54 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc_c;
	unsigned char	*str_s;

	uc_c = (unsigned char) c;
	str_s = (unsigned char *) s;
	while (n--)
	{
		if (uc_c == *str_s)
			return (&*str_s);
		str_s++;
	}
	return (0);
}
