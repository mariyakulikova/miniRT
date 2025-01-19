/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_vec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:33:36 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/17 19:18:45 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*new_vec(float x, float y, float z)
{
	t_vector	*vector;

	vector = malloc(sizeof(t_vector));
	if (!vector)
		return (NULL);
	vector->x = x;
	vector->y = y;
	vector->z = z;
	return (vector);
}

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
	ft_free_split(s);
	if (need_check)
	{
		if (in_range_float(x, -1.0f, 1.0f) \
			&& in_range_float(y, -1.0f, 1.0f) \
			&& in_range_float(z, -1.0f, 1.0f))
			return (new_vec(x, y, z));
		else
			return (NULL);
	}
	return (new_vec(x, y, z));
}

t_vector	*vec_by_scaler(t_vector *v, float scaler)
{
	return (new_vec(v->x * scaler, v->y * scaler, v->z * scaler));
}
