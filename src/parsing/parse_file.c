/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:33:57 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/20 17:37:24 by mkulikov         ###   ########.fr       */
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
		print_error(-1, "Empty file\n", NULL, NULL);
	free(line);
}

void	parse_file(char *file, t_scene **scene)
{
	int		fd;
	char	*line;

	check_empty_file(file);
	fd = open_file(file);
	init_scene(scene);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		parse_line(line, *scene);
		free(line);
	}
	close(fd);
}
