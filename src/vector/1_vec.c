/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_vec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:54:53 by mkulikov          #+#    #+#             */
/*   Updated: 2024/10/18 12:48:18 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vector	*new_vec(double x, double y, double z)
{
	t_vector	*v;

	v = (t_vector *)malloc(sizeof(t_vector));
	if (!v)
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vector	*vec_sub(t_vector *v1, t_vector *v2)
{
	double		x;
	double		y;
	double		z;
	t_vector	*v;

	x = v1->x - v2->x;
	y = v1->y - v2->y;
	z = v1->z - v2->z;
	v = new_vec(x, y, z);
	return (v);
}

double	vec_len(t_vector *v)
{
	double	len;

	len = sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	return (len);
}

void		vec_norm(t_vector *v)
{
	double	len;

	len = vec_len(v);
	v->x /= len;
	v->y /= len;
	v->z /= len;
}

double	vec_dot_prod(t_vector *v1, t_vector *v2)
{
	double	dot_prod;

	dot_prod = (v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z);
	return (dot_prod);
}
