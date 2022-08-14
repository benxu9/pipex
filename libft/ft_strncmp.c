/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:01:07 by bxu               #+#    #+#             */
/*   Updated: 2021/11/19 16:01:09 by bxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	if (n == 0)
		return (0);
	index = 0;
	while (index < n)
	{
		if (s1[index] && (s1[index] == s2[index]))
		{
			while (s1[index] && (s1[index] == s2[index])
				&& index < n)
			{
				index++;
			}
		}
		else
		{
			return ((unsigned char)s1[index] - (unsigned char)s2[index]);
		}
	}
	return (0);
}
