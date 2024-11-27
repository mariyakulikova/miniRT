/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:33:57 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/27 20:16:17 by mkulikov         ###   ########.fr       */
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
// TODO redo!!!!!!!!!!
static void	parse_scene_features(t_data *data, char **s)
{
	if (s[0][0] == 'A' && data->scene->a_light == NULL)
	{
		data->scene->a_light = get_a_light(s);
		if (!data->scene->a_light)
			print_error(-1, NULL, data);
	}
	else if (s[0][0] == 'C' && data->scene->camera == NULL)
	{
		data->scene->camera = get_camera(s);
		if (!data->scene->camera)
			print_error(-1, NULL, data);
	}
	else if (s[0][0] == 'L' && data->scene->light == NULL)
	{
		data->scene->light = get_light(s);
		if (!data->scene->light)
			print_error(-1, NULL, data);
	}
}

static void	parse_figures(t_data *data, char **s)
{
	t_figure	*figure;
	t_list		*node;
	t_ftype		type;

	type = get_ftype(s[0]);
	if (type == UNDEFINED)
		print_error(-1, NULL, data);
	if (type == SPHERE)
		figure = get_sphere(type, s);
	else if (type == PLANE)
		figure = get_plane(type, s);
	else if (type == CYLINDER)
		figure = get_cylinder(type, s);
	if (!figure)
		print_error(-1, NULL, data);
	node = ft_lstnew(figure);
	if (!node)
		print_error(-1, NULL, data);
	ft_lstadd_back(&data->scene->fugures, node);
}

static void	parse_line(char *line, t_data *data)
{
	char	*str;
	char	**s;

	str = ft_strtrim(line, " ");
	if (!str)
		print_error(-1, NULL, data);
	s = ft_split(str, ' ');
	if (!s)
	{
		free(str);
		print_error(-1, NULL, data);
	}
	if (is_upper(s[0][0]))
		parse_scene_features(data, s);
	else if (is_lower(s[0][0]))
		parse_figures(data, s);
	free(str);
	free_split(s);
}

void	read_file(char *file, t_data *data)
{
	int		fd;
	char	*line;

	check_empty_file(file);
	fd = open_file(file);
	data->scene = new_scene(WIDTH, HIGHT);
	if (!data->scene)
		print_error(-1, strerror(errno), data);
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] == '\n')
			continue ;
		parse_line(line, data);
		free(line);
	}
	close(fd);
}
