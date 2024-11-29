/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:54:44 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/29 12:09:05 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_light	*new_light(t_vector *vector, float ratio, t_color *color)
{
	t_light	*l;

	l = (t_light *)malloc(sizeof(t_light));
	if (!l)
		return (NULL);
	l->coord = vector;
	l->ratio = ratio;
	l->color = color;
	return (l);
}

t_light	*get_light(char **s)
{
	float		ratio;
	t_vector	*vector;
	t_color		*color;

	ratio = ft_atof(s[2]);
	if (!in_range_float(ratio, 0.0f, 1.0f))
		return (NULL);
	vector = get_vec(s[1], false);
	if (!vector)
		return (NULL);
	color = get_color(s[3]);
	if (!color)
	{
		free(vector);
		return (NULL);
	}
	return (new_light(vector, ratio, color));
}
