/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:42:48 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/23 17:14:18 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_figure	*get_plane(t_ftype type, char **s)
{
	t_vector	*coord;
	t_vector	*nv3d;
	t_color		*color;

	coord = get_vec(s[1], false);
	if (!coord)
		return (NULL);
	nv3d = get_vec(s[2], true);
	if (!nv3d)
	{
		free(coord);
		return (NULL);
	}
	color = get_color(s[3]);
	if (!color)
	{
		free(coord);
		free(nv3d);
		return (NULL);
	}
	return (new_figure((t_figure){type, nv3d, coord, color, 0, 0}));
}
int plane_intersect(t_camera *camera, t_vector *ray, t_figure *plane)
{
	t_vector	*camera_to_plane;
	float		normal_dot_ray;
	float		normal_dot_dist; 
	float		distance;

	normal_dot_ray = vec_dot_prod(plane->norm_v3d, ray);
	camera_to_plane = vec_sub(plane->coord, camera->origin);
	if (normal_dot_ray != 0)
	{
		normal_dot_dist = vec_dot_prod(camera_to_plane, plane->norm_v3d);
		distance = normal_dot_dist / normal_dot_ray;
		if (distance < 0)
			return (0);
		return (distance);
	}
	return 0;
}