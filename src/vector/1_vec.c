/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_vec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:54:53 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/20 17:02:53 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	*vec_add(t_vector *v1, t_vector *v2)
{
	return (new_vec(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z));
}

t_vector	*vec_sub(t_vector *v1, t_vector *v2)
{
	return (new_vec(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z));
}

float	vec_len(t_vector *v)
{
	return (sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}

void	vec_norm(t_vector *v)
{
	float	length;

	length = vec_len(v);
	v->x /= length;
	v->y /= length;
	v->z /= length;
}

float	vec_dot_prod(t_vector *v1, t_vector *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}

