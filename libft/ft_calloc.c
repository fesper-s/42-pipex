/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:43:04 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/26 08:03:31 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if ((count * size) / count != size)
		return (0);
	ptr = malloc(count * size);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, count * size);
	return (ptr);
}
