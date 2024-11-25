/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_figure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:19:38 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/25 22:03:08 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// TODO check parsed value diapason range

static t_vector	*get_vec(char str)
{
	char		**s;
	t_vector	*vec;

	s= ft_split(str, ',');
	if (!s)
		return (NULL);
	vec = new_vec(ft_atof(s[0]), ft_atof(s[0]), ft_atof(s[0]));
	free(s);
	if (!vec)
		return (NULL);
	return (vec);
}
// TODO new_col and what does referto t_color
static t_color	*get_col(char str)
{
	char	**s;
	t_color	*clr;

	s = ft_split(str, ',');
	if (!s)
		return (NULL);
	clr = new_color(ft_atoi(s[0]), ft_atoi(s[1]), ft_atoi(s[2]));
	free(s);
	if (!clr)
		return (NULL);
	return (clr);
}
// TODO pass right args to new_figure function regarding figure type, implement ft_atof
static t_figure	*get_fig(char *str)
{
	char		**s;
	t_figure	*f;

	s = ft_split(str, ' ');
	if (!s)
		return (NULL);
	if (ft_strcmp(s[0], "sp") == 0)
		f = new_figure(s[0], NULL, get_vec(s[1]), ft_atof(s[2]), ft_atof(s[2]), get_col(s[2]));
	if (ft_strcmp(s[0], "pl") == 0)
		f = new_figure(s[0], NULL, get_vec(s[1]), ft_atof(s[2]), ft_atof(s[2]), get_col(s[2]));
	if (ft_strcmp(s[0], "cy") == 0)
		f = new_figure(s[0], NULL, get_vec(s[1]), ft_atof(s[2]), ft_atof(s[2]), get_col(s[2]));
	free(s);
	if (!f)
		return (NULL);
	return (f);
}

void	parse_figures(t_data *data, char *str)
{

	t_figure	*figure;
	t_list		*node;

	figure = get_fig(str);
	if (!figure)
		print_error(-1, NULL, data);
	node = ft_lstnew(figure);
	if (!node)
		print_error(-1, NULL, data);
	ft_lstadd_back(&data->scene->fugures, node);
}
