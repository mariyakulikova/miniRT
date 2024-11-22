/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:33:57 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/22 17:43:44 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_empty_file(char *file)
{
	int		fd;
	char	*line;

	fd = open_file(file);
	line = get_next_line(fd);
	if (!line)
		print_error(-1, "Empty file\n", NULL);
	free(line);
}

void	read_file(char *file, t_data *data)
{
	int		fd;
	char	*line;

	check_empty_file(file);
	fd = open_file(file);
	data->scene = init_scene(WIDTH, HIGHT);
	if (!data->scene)
		print_error(-1, strerror(errno), data);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) == 0)
			continue ;
		parse_line(line, data);
		free(line);
	}
	close(fd);
}
