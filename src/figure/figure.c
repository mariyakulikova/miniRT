/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:50:01 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/27 17:07:59 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ftype	get_ftype(char *id)
{
	if (ft_strcmp(id, "sp") == 0)
		return (SPHERE);
	if (ft_strcmp(id, "pl") == 0)
		return (PLANE);
	if (ft_strcmp(id, "cy") == 0)
		return (CYLINDER);
	return (UNDEFINED);
}

t_figure	*new_figure(t_figure args)
{
	t_figure	*figure;

	figure = (t_figure *)malloc(sizeof(t_figure));
	if (!figure)
		return (NULL);
	figure->type = args.type;
	figure->norm_v3d = args.norm_v3d;
	figure->coord = args.coord;
	figure->color = args.color;
	figure->hight = args.hight;
	figure->diameter = args.diameter;
	return (figure);
}

void	set_figure_a_color(t_data *d)
{
	t_list		*node;
	t_figure	*f;

	node = d->scene->fugures;
	while (node)
	{
		f = (t_figure *)node->content;
		f->a_color = color_multi(f->color, d->scene->a_light->a_color);
		if (!f->a_color)
			print_error(1, "malloc error\n", d);
		node = node->next;
	}
}

int get_figure_color(t_figure *figure)
{
	return (color_to_int(figure->a_color));
}
