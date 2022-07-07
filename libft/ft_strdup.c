/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:04:32 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/19 08:01:29 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_str;
	int		len_s;
	int		i;

	len_s = ft_strlen(s);
	new_str = malloc((len_s + 1) * sizeof(char));
	if (new_str == 0)
		return (0);
	i = 0;
	while (i < len_s)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}
