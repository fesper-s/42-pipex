/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 13:25:19 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/19 11:54:49 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int i, long nbr)
{
	if (nbr == 0)
		i++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static char	*ft_putstr(int i, long nbr, char *str)
{
	str[i] = 0;
	if (nbr == 0)
		str[--i] = nbr + 48;
	while (nbr > 0)
	{
		str[--i] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (&*str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	long	nbr;

	i = 0;
	i = ft_count(i, n);
	nbr = (long) n;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		str = malloc((++i + 1) * sizeof(char));
		if (str == 0)
			return (0);
		str[0] = '-';
	}
	else
	{
		str = malloc((i + 1) * sizeof(char));
		if (str == 0)
			return (0);
	}
	str = ft_putstr(i, nbr, str);
	return (str);
}
