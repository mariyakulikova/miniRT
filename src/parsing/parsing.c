/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:33:57 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/12 17:47:41 by mkulikov         ###   ########.fr       */
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
	if (s[0][0] == 'A')
	{
		if (data->scene->a_light)
			print_error(-1, "already exist", data);
		data->scene->a_light = get_a_light(s);
		if (!data->scene->a_light)
			print_error(-1, "get_a_light", data);
	}
	else if (s[0][0] == 'C')
	{
		if (data->scene->camera)
			print_error(-1, "already exist", data);
		data->scene->camera = get_camera(s);
		if (!data->scene->camera)
			print_error(-1, "get_camera", data);
	}
	else if (s[0][0] == 'L')
	{
		if (data->scene->light)
			print_error(-1, "already exist", data);
		data->scene->light = get_light(s);
		if (!data->scene->light)
			print_error(-1, "get_light", data);
	}
}

static void	parse_figures(t_data *data, char **s)
{
	t_figure	*figure = NULL;
	t_list		*node;
	t_ftype		type;

	type = get_ftype(s[0]);
	if (type == UNDEFINED)
		print_error(-1, "undefined figure type", data);
	if (type == SPHERE)
		figure = get_sphere(type, s);
	else if (type == PLANE)
		figure = get_plane(type, s);
	else if (type == CYLINDER)
		figure = get_cylinder(type, s);
	if (!figure)
		print_error(-1, "malloc", data);
	node = ft_lstnew(figure);
	if (!node)
		print_error(-1, "malloc", data);
	ft_lstadd_back(&data->scene->fugures, node);
}

static void	parse_line(char *line, t_data *data)
{
	char	*str;
	char	**s;

	str = ft_strtrim(line, " ");
	if (!str)
		print_error(-1, "malloc trim", data);
	s = ft_split(str, ' ');
	if (!s)
	{
		free(str);
		print_error(-1, "malloc split", data);
	}
	if (is_upper(s[0][0]))
		parse_scene_features(data, s);
	else if (is_lower(s[0][0]))
		parse_figures(data, s);
	free(str);
	ft_free_split(s);
}

void	read_file(char *file, t_data *data)
{
	int		fd;
	int		len;
	char	*line;

	check_empty_file(file);
	fd = open_file(file);
	data->scene = new_scene(WIDTH, HIGHT);
	if (!data->scene)
		print_error(-1, "malloc", data);
	while (true)
	{
		line = get_next_line(fd);
		len = ft_strlen(line);
		if (len == 0)
			break ;
		if (len && (line[0] == '\n'))
		{
			free(line);
			continue ;
		}
		replace_tab(line);
		parse_line(line, data);
		free(line);
	}
	free(line);
	close(fd);
}
