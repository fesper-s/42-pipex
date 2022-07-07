/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 13:08:29 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/06 12:30:48 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	uc_c;
	unsigned char	*str;

	uc_c = (unsigned char) c;
	str = (unsigned char *) b;
	i = 0;
	while (len > 0)
	{
		str[i] = uc_c;
		i++;
		len--;
	}
	return (str);
}
