/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 11:22:57 by bxu               #+#    #+#             */
/*   Updated: 2021/12/01 12:42:12 by bxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(const char *str, char c)
{
	size_t	count;

	if (!*str)
		return (0);
	count = 0;
	while (*str)
	{
		while (*str == c)
				str++;
		if (*str)
				count++;
		while (*str != c && *str)
					str++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	word_len;
	char	**split;

	split = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			split[i++] = ft_substr(s, 0, word_len);
			s += word_len;
		}
	}
	split[i] = NULL;
	return (split);
}