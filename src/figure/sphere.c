/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:40:53 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/27 20:32:04 by mkulikov         ###   ########.fr       */
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

t_figure	*get_sphere(t_ftype type, char **s)
{
	t_color		*color;
	t_vector	*coord;
	float		d;

	color = get_color(s[3]);
	if (!color)
		return (NULL);
	coord = get_vec(s[1], false);
	if (!coord)
	{
		free(color);
		return (NULL);
	}
	d = ft_atof(s[2]);
	return (new_figure((t_figure){type, NULL, coord, color, d, d}));
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
