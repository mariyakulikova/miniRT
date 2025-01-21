/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:21:38 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 16:27:59 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_figure	*get_cylinder(t_ftype type, char **s)
{
	t_vector	*coord;
	t_vector	*nv3d;
	t_color		*color;
	float		d;
	float		h;

	coord = get_vec(s[1], false);
	if (!coord)
		return (NULL);
	nv3d = get_vec(s[2], true);
	if (!nv3d)
	{
		free(coord);
		return (NULL);
	}
	color = get_color(s[5]);
	if (!color)
	{
		free(coord);
		free(nv3d);
		return (NULL);
	}
	d = ft_atof(s[3]);
	h = ft_atof(s[4]);
	return (new_figure((t_figure){type, nv3d, coord, color, NULL, NULL, h, d}));
}

float	cylinder_base_intersect(t_vector *camera, t_vector *ray, \
									t_figure *cylinder, float *d_min)
{
	float		dist_disc[2];
	t_figure	plane_top;
	t_figure	plane_bottom;

	plane_bottom = *cylinder;
	plane_top = *cylinder;
	plane_top.coord = new_vec(cylinder->coord->x + \
		cylinder->norm_v3d->x * cylinder->hight,
			cylinder->coord->y + cylinder->norm_v3d->y * cylinder->hight,
			cylinder->coord->z + cylinder->norm_v3d->z * cylinder->hight);
	dist_disc[0] = base_intersect(camera, ray, \
	&plane_bottom, cylinder->diameter / 2);
	if (dist_disc[0] > 0 && dist_disc[0] < *d_min)
		*d_min = dist_disc[0];
	dist_disc[1] = base_intersect(camera, ray, \
	&plane_top, cylinder->diameter / 2);
	if (dist_disc[1] > 0 && dist_disc[1] < *d_min)
		*d_min = dist_disc[1];
	free(plane_top.coord);
	return (*d_min);
}
