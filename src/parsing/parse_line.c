/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:25 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/22 17:52:15 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_scene_options(t_data *data, char *line, int i)
{
	t_scene	*scene;

	scene = data->scene;
	if (line[i] == 'A')
		if (scene->ambient)
			print_error(-1, NULL, data);
		else
			return (parse_and_set_ambient(data, line, i));
	if (line[i] == 'C')
		if (scene->camera)
			print_error(-1, NULL, data);
		else
			return (parse_and_set_camera(data, line, i));
	if (line[i] == 'L')
		if (scene->light)
			print_error(-1, NULL, data);
		else
			return (parse_and_set_light(data, line, i));
	return (i);
}

int	parse_figures(t_data *data, char *line, int i)
{
	return (i);
}

void	parse_line(char *line, t_data *data)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	while (i < len)
	{
		if (is_upper(line[i]))
			i = parse_scene_options(data, line, i);
		else if (is_lower(line[i]))
			i = parse_figures(data, line, i);
		else
			i++;
	}
}
