/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:08 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/22 11:32:16 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_empty_file(char *file)
{
	int		fd;
	char	*line;

	fd = open_file(file);
	line = get_next_line(fd);
	if (!*line)
		print_error(-1, "Empty file\n", NULL);
	free(line);
}

static void	check_scene(t_data *d)
{
	if (!d->scene->a_light)
		print_error(-1, "no ambient light\n", d);
	if (!d->scene->light)
		print_error(-1, "no light\n", d);
	if (!d->scene->camera)
		print_error(-1, "no camera\n", d);

}

void	read_file(char *file, t_data *data)
{
	int	fd;

	check_empty_file(file);
	fd = open_file(file);
	data->scene = new_scene(WIDTH, HIGHT);
	if (!data->scene)
		print_error(-1, "malloc", data);
	read_lines(fd, data);
	check_scene(data);
	close(fd);
}
