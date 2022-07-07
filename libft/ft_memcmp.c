/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 14:00:30 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/17 09:13:37 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const	void *s1, const void *s2, size_t n)
{
	unsigned char	*str_s1;
	unsigned char	*str_s2;

	str_s1 = (unsigned char *) s1;
	str_s2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*str_s1 != *str_s2)
			return (*str_s1 - *str_s2);
		str_s1++;
		str_s2++;
	}
	return (0);
}
