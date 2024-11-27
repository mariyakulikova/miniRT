/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_vec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:33:36 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/27 18:54:18 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*get_vec(char *str, bool need_check)
{
	char		**s;
	float		x;
	float		y;
	float		z;

	s = ft_split(str, ',');
	if (!s)
		return (NULL);
	x = ft_atof(s[0]);
	y = ft_atof(s[1]);
	z = ft_atof(s[2]);
	free_split(s);
	if (need_check)
	{
		if (in_range_float(x, 0.0f, 1.0f) \
			&& in_range_float(y, 0.0f, 1.0f) \
			&& in_range_float(z, 0.0f, 1.0f))
			return (new_vec(x, y, z));
		else
			return (NULL);
	}
	return (new_vec(x, y, z));
}
