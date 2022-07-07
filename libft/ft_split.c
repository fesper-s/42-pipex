/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 08:33:43 by fesper-s          #+#    #+#             */
/*   Updated: 2022/05/30 07:57:36 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	wordnbr;

	i = 0;
	wordnbr = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			wordnbr++;
		i++;
	}
	return (wordnbr);
}

static size_t	ft_lencount(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	str = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s[i] && j < ft_wordcount(s, c))
	{
		while (s[i] == c)
			i++;
		str[j] = ft_substr(&s[i], 0, ft_lencount(&s[i], c));
		i += ft_lencount(&s[i], c);
		j++;
	}
	str[j] = 0;
	return (str);
}
