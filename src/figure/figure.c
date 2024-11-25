/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:50:01 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/25 21:29:42 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_ftype	get_ftype(char *id)
{
	if (ft_strcmp(id, "sp") == 0)
		return (SPHERE);
	if (ft_strcmp(id, "pl") == 0)
		return (PLANE);
	if (ft_strcmp(id, "pl") == 0)
		return (CYLINDER);
	return (UNDEFINED);
}

t_figure	*new_figure(char *id, t_vector *norm_v3d, t_vector *coord,\
						 float hight, float diameter, t_color *color)
{
	t_figure	*figure;

	figure = (t_figure *)malloc(sizeof(t_figure));
	if(!figure)
		return (NULL);
	figure->type = get_ftype(id);
	figure->norm_v3d = norm_v3d;
	figure->coord = coord;
	figure->color = color;
	figure->hight = hight;
	figure->diameter = diameter;
	return (figure);
}
