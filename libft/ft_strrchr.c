/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 15:29:23 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/20 15:29:24 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	*ptr;

	ptr = (char *)s;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (*(ptr + len) == (char)c)
			return (ptr + len);
		len--;
	}
	return (NULL);
}
