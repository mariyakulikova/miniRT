/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:16:18 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/12 15:57:34 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	replace_tab(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == '\f' \
			|| *(s + i) == '\r' \
			|| *(s + i) == '\t' \
			|| *(s + i) == '\v')
			*(s + i) = ' ';
		i++;
	}
}

bool	is_lower(char i)
{
	return ((i >= 'a') && (i <= 'z'));
}

float	ft_atof(char *str)
{
	char	*point;
	int		len;
	float	integer_part;
	float	fractional_part;

	integer_part = (float)ft_atoi(str);
	point = ft_strchr(str, '.');
	if (!point)
		return (integer_part);
	fractional_part = (float)ft_atoi(++point);
	len = ft_strlen(point);
	while (len--)
		fractional_part /= 10;
	return (integer_part + fractional_part);
}

void	ft_free_split(char **s)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		free(*(s + i));
		i++;
	}
	free(s);
}
