/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:54:40 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 10:54:46 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_camera	*new_camera(t_vector *origin, t_vector *direction, float fov)
{
	t_camera	*camera;

	camera = malloc(sizeof(t_camera));
	if (!camera)
		return (NULL);
	camera->origin = origin;
	camera->direction = direction;
	camera->fov = fov;
	return (camera);
}

t_camera	*get_camera(char **s)
{
	t_vector	*origin;
	t_vector	*direction;
	int			fov;

	fov = ft_atoi(s[3]);
	if (!in_range_int(fov, 0, 180))
		return (NULL);
	origin = get_vec(s[1], false);
	if (!origin)
		return (NULL);
	direction = get_vec(s[2], true);
	if (!direction)
	{
		free(origin);
		return (NULL);
	}
	return (new_camera(origin, direction, fov));
}
