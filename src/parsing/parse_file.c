/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:33:57 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/22 14:48:59 by mkulikov         ###   ########.fr       */
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



void	parse_file(char *file, t_minirt *minirt)
{
	int		fd;
	char	*line;

	check_empty_file(file);
	fd = open_file(file);
	init_scene(&minirt->scene);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strlen(line) == 0)
			continue ;
		parse_line(line, minirt->scene);
		free(line);
	}
	close(fd);
}
