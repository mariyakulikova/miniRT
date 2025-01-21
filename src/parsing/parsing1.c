/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:29:08 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 17:11:37 by alvutina         ###   ########.fr       */
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
