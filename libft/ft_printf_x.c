/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 09:47:47 by fesper-s          #+#    #+#             */
/*   Updated: 2022/07/05 09:54:46 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_hex(unsigned long nbr)
{
	int	len;

	len = 0;
	if (!nbr)
		len++;
	while (nbr)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

int	ft_printf_x(unsigned long x)
{
	int	len;

	len = 0;
	len = len_hex(x);
	if (x >= 16)
	{
		ft_printf_x(x / 16);
		ft_printf_x(x % 16);
	}
	else if (x < 10)
		ft_printf_c(x + 48);
	else
		ft_printf_c(x - 10 + 97);
	return (len);
}
