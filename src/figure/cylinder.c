/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:32:36 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/23 14:24:33 by alvutina         ###   ########.fr       */
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
	return (new_figure((t_figure){type, nv3d, coord, color, h, d}));
}
int cylinder_intersect(t_camera *camera, t_vector *ray, t_figure *cylinder)
{
	(void)camera;
	(void)ray;
	(void)cylinder;
	printf("hello cylinder");
	return 0;
}