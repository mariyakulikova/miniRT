/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:40:53 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/22 16:39:49 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*new_sphere(t_vector *center, float radius)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = center;
	sphere->radius = radius;
	return (sphere);
}

int	sphere_intersect(t_camera *camera, t_vector *ray, t_sphere *sphere)
{
	float		b;
	float		c;
	float		discr;
	float		dist_1;
	float		dist_2;
	t_vector	*camera_sphere;

	dist_1 = 0;
	dist_2 = 0;
	camera_sphere = vec_sub(camera->origin, sphere->center);
	b = 2 * (vec_dot_prod(camera_sphere, ray));
	c = vec_dot_prod(camera_sphere, camera_sphere) - (sqrtf(sphere->radius));
	discr = (b * b) - (4 * c);
	free(camera_sphere);
	if (discr < 0)
		return (0);
	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;
	dist_2 = ((b * (-1)) - sqrt(discr)) / 2;
	if (dist_1 > 0)
		return (1);
	return (0);
}
