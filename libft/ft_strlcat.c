/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 16:00:15 by bxu               #+#    #+#             */
/*   Updated: 2021/11/19 16:03:33 by bxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[k] && (i + k + 1) < dstsize)
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i < dstsize)
		dst[i + k] = '\0';
	return (i + ft_strlen(src));
}
