/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:05:15 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/27 17:53:15 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*new_scene(int w, int h)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	ft_memset(scene, 0, sizeof(t_scene));
	scene->width = w;
	scene->hight = h;
	return (scene);
}

// t_scene	*new_scene(t_camera *camera, t_sphere *sphere)
// {
// 	t_scene	*scene;

// 	scene = malloc(sizeof(t_scene));
// 	// if (!scene)
// 	// 	print_error(-1);
// 	scene->camera = camera;
// 	scene->sphere = sphere;
// 	scene->width = 0;
// 	scene->hight = 0;
// 	return (scene);
// }
