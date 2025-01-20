/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:28:47 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/20 15:28:48 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	destlen;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (!dest && !destsize)
		return (srclen);
	destlen = ft_strlen(dest);
	if (destlen >= destsize)
		return (srclen + destsize);
	else
		destsize -= destlen;
	ft_strlcpy(dest + destlen, src, destsize);
	return (destlen + srclen);
}
