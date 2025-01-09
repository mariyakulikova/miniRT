/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_vec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:54:53 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/09 13:20:37 by cmarguer         ###   ########.fr       */
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

void	vec_multiply(t_vector *v, float t)
{
	v->x *= t;
	v->y *= t;
	v->z *= t;
}

t_vector	*vector_addition(t_vector *a, t_vector *b)
{
	t_vector	*sum;

	sum = malloc(sizeof(t_vector));
	if (!sum)
		return (NULL);
	sum->x = a->x + b->x;
	sum->y = a->y + b->y;
	sum->z = a->z + b->z;
	return (sum);
}


