/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:53:49 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/27 19:01:22 by mkulikov         ###   ########.fr       */
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
