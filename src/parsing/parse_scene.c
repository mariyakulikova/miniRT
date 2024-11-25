/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:25 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/25 21:59:40 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_scene_options(t_data *data, char *line, int i)
{
	t_scene	*scene;

	scene = data->scene;
	if (line[i] == 'A')
		if (scene->ambient)
			print_error(-1, NULL, data);
		else
			parse_and_set_ambient(data, line, i);
	if (line[i] == 'C')
		if (scene->camera)
			print_error(-1, NULL, data);
		else
			parse_and_set_camera(data, line, i);
	if (line[i] == 'L')
		if (scene->light)
			print_error(-1, NULL, data);
		else
			parse_and_set_light(data, line, i);
}




