/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:27:32 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/20 15:27:32 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;

	ptrdst = (unsigned char *)dest;
	ptrsrc = (unsigned char *)src;
	if (!ptrdst && !ptrsrc)
		return (NULL);
	while (n > 0)
	{
		*ptrdst = *ptrsrc;
		ptrdst++;
		ptrsrc++;
		n--;
	}
	return (dest);
}
