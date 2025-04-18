/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:54:50 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 10:55:27 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_light	*new_light(t_vector *vector, float ratio, \
							t_color *color, t_color *l_color)
{
	t_light	*l;

	l = (t_light *)malloc(sizeof(t_light));
	if (!l)
		return (NULL);
	l->coord = vector;
	l->ratio = ratio;
	l->color = color;
	l->l_color = l_color;
	return (l);
}

t_light	*get_light(char **s)
{
	float		ratio;
	t_vector	*vector;
	t_color		*color;
	t_color		*l_color;

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
	l_color = color_by_scaler(color, ratio);
	if (!l_color)
	{
		free(vector);
		free(color);
		return (NULL);
	}
	return (new_light(vector, ratio, color, l_color));
}
