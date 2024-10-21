/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:40:53 by mkulikov          #+#    #+#             */
/*   Updated: 2024/10/21 16:56:03 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_sphere	*new_sphere(t_vector *c, float r)
{
	t_sphere	*s;

	s = (t_sphere *)malloc(sizeof(t_sphere));
	if (!s)
		return (NULL);
	s->center = c;
	s->radius = r;
	return (s);
}

int	sphere_intersec(t_camera *cam, t_vector *ray, t_sphere *sp)
{
	float		b;
	float		c;
	float		discr;
	float		dist1;
	float		dist2;
	t_vector	*cam_sphere;

	dist1 = 0;
	dist2 = 0;
	cam_sphere = vec_sub(cam->origin, sp->center);
	b = 2 * (vec_dot_prod(cam_sphere, ray));
	c = vec_dot_prod(cam_sphere, cam_sphere) - sp->radius * sp->radius;
	discr = (b * b) - (4  * c);
	if (discr < 0)
		return (0);

	free(cam_sphere);
}
