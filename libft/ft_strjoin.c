/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:53:28 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/26 08:35:10 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (new_str == 0)
		return (0);
	ft_strlcpy(new_str, s1, len_s1 + 1);
	ft_strlcat(new_str, s2, len_s1 + len_s2 + 1);
	return (new_str);
}
