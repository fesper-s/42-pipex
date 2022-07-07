/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 12:04:05 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/26 08:39:59 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		len_s;
	int		i;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	str = malloc(len_s + 1 * sizeof(char));
	if (str == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}
