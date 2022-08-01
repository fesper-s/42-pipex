/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fesper-s <fesper-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 08:33:43 by fesper-s          #+#    #+#             */
/*   Updated: 2022/08/01 10:28:35 by fesper-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	wordnbr;

	i = -1;
	wordnbr = 1;
	while (*s && *s == c)
		s++;
	while (s[++i])
	{
		if (s[i] != c && (s[i - 1] == c || i == 0))
			wordnbr++;
		if (s[i] == '"')
		{
			i++;
			while (s[i] != '"')
				i++;
		}
		if (s[i] == 39)
		{
			i++;
			while (s[i] != 39)
				i++;
		}
	}
	return (wordnbr);
}

static size_t	ft_lencount(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		if (s[i] == '"')
		{
			i++;
			while (s[i] != '"')
				i++;
		}
		if (s[i] == 39)
		{
			i++;
			while (s[i] != 39)
				i++;
		}
		i++;
	}
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
