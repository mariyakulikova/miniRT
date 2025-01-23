/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:08 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/23 11:57:35 by mkulikov         ###   ########.fr       */
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

void	read_file(char *file, t_data *data)
{
	int	fd;

	check_empty_file(file);
	fd = open_file(file);
	data->scene = new_scene(WIDTH, HIGHT);
	if (!data->scene)
		print_error(-1, "malloc", data);
	read_lines(fd, data);
	close(fd);
}

void	read_lines_on_error(int fd, t_data *d)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!*line)
			break ;
		free(line);
	}
	free(line);
	print_error(-1, "parse_line\n", d);
}
