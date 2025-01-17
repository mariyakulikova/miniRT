/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   sphere.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mkulikov <mkulikov@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/21 11:40:53 by mkulikov		  #+#	#+#			 */
/*   Updated: 2024/12/28 21:08:13 by mkulikov		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minirt.h"


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
	return (new_figure((t_figure){type, NULL, coord, color, NULL, NULL, d, d}));
}

// Функция вычисления пересечения с сферой
float	sphere_intersect(t_camera *camera, t_vector *ray, t_figure *sphere)
{
	t_sphere_intersect	si;
	t_vector			*camera_sphere;


	camera_sphere = vec_sub(camera->origin, sphere->coord);
	si.dist_squared = vec_dot_prod(camera_sphere, camera_sphere);
	si.radius_squared = powf(sphere->diameter / 2.0f, 2.0f);
	if (si.dist_squared < si.radius_squared)
	{
		free(camera_sphere);
		return (0);
	}
	si.b = 2.0f * vec_dot_prod(camera_sphere, ray);
	si.c = si.dist_squared - si.radius_squared;
	si.discr = powf(si.b, 2.0f) - 4.0f * si.c;
	free(camera_sphere);
	if (si.discr < 0)
		return (0);
	si.dist_1 = (-si.b - sqrtf(si.discr)) / 2.0f;
	if (si.dist_1 > 0)
		return (si.dist_1);
	return (0);
}

