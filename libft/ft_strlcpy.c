/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:28:57 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/20 15:28:57 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen + 1 < destsize)
		ft_memcpy(dest, src, srclen + 1);
	else if (destsize != 0)
	{
		ft_memcpy(dest, src, destsize - 1);
		*(dest + destsize - 1) = '\0';
	}
	return (srclen);
}
