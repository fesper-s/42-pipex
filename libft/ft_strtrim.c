/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:07:28 by fesper-s          #+#    #+#             */
/*   Updated: 2022/07/29 15:11:37 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)

{
	size_t	size_cut;
	char	*result;

	if (!s1 || !set)
		return (0);
	if (*s1 && ft_strchr(set, *s1))
		s1++;
	size_cut = ft_strlen(s1) - 1;
	if (*s1 && ft_strchr(set, s1[size_cut]))
		size_cut--;
	result = ft_substr(s1, 0, size_cut + 1);
	return (result);
}
