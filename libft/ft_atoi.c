/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 08:08:03 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/13 19:57:07 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

static int	ft_overflow(int sign)
{
	if (sign > 0)
		return (-1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	long	nbr;
	long	temp;
	int		sign;

	nbr = 0;
	temp = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
		if (*nptr == '-' || *nptr == '+')
			return (0);
	}
	while (ft_isdigit(*nptr))
	{
		temp = nbr;
		nbr = (nbr * 10) + *nptr++ - 48;
		if (temp > nbr)
			return (ft_overflow(sign));
	}
	return (sign * nbr);
}
