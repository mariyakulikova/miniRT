/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:33:57 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/23 12:14:17 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	parse_scene_features(t_data *data, char **s)
{
	if (ft_strcmp(*s, "A") == 0)
	{
		if (data->scene->a_light)
			return (1);
		data->scene->a_light = get_a_light(s);
		if (!data->scene->a_light)
			return (1);
	}
	else if (ft_strcmp(*s, "C") == 0)
	{
		if (data->scene->camera)
			return (1);
		data->scene->camera = get_camera(s);
		if (!data->scene->camera)
			return (1);
	}
	else if (ft_strcmp(*s, "L") == 0)
	{
		if (data->scene->light)
			return (1);
		data->scene->light = get_light(s);
		if (!data->scene->light)
			return (1);
	}
	return (0);
}

static void	free_helper(char **s, char *l1, char *l2)
{
	if (s)
		ft_free_split(s);
	if (l1)
		free(l1);
	if (l2)
		free(l2);
}

static int	parse_figures(t_data *data, char **s)
{
	t_figure	*figure;
	t_list		*node;
	t_ftype		type;

	figure = NULL;
	type = get_ftype(s[0]);
	if (type == SPHERE)
		figure = get_sphere(type, s);
	else if (type == PLANE)
		figure = get_plane(type, s);
	else if (type == CYLINDER)
		figure = get_cylinder(type, s);
	if (!figure)
		return (1);
	node = ft_lstnew(figure);
	if (!node)
		return (1);
	ft_lstadd_back(&data->scene->fugures, node);
	return (0);
}

static int	parse_line(char *line, t_data *data)
{
	char	*str;
	char	**s;

	str = ft_strtrim(line, " ");
	if (!str)
		return (1);
	s = ft_split(str, ' ');
	if (!s)
	{
		free(str);
		return (1);
	}
	if (is_upper(s[0][0]) && parse_scene_features(data, s))
	{
		free_helper(s, str, line);
		return (1);
	}
	else if (is_lower(s[0][0]) && parse_figures(data, s))
	{
		free_helper(s, str, line);
		return (1);
	}
	free_helper(s, str, line);
	return (0);
}

void	read_lines(int fd, t_data *data)
{
	int		len;
	char	*line;

	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (len == 0)
		{
			free(line);
			break ;
		}
		if (len && (line[0] == '\n'))
		{
			free(line);
			continue ;
		}
		replace_tab(line);
		if (parse_line(line, data))
			read_lines_on_error(fd, data);
	}
}
