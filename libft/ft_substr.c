/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 13:01:58 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/26 08:29:01 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (0);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start >= len)
		substr = malloc((len + 1) * sizeof(char));
	else
		substr = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (!substr)
		return (0);
	ft_strlcpy(substr, &s[start], len + 1);
	return (substr);
}
