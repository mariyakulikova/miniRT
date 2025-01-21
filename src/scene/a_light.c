/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_light.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:54:30 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 10:54:35 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_a_light	*new_a_light(float ratio, t_color *color, t_color *a_color)
{
	t_a_light	*a_light;

	a_light = (t_a_light *)malloc(sizeof(t_a_light));
	if (!a_light)
		return (NULL);
	a_light->ratio = ratio;
	a_light->color = color;
	a_light->a_color = a_color;
	return (a_light);
}

t_a_light	*get_a_light(char **s)
{
	float		ratio;
	t_color		*color;
	t_color		*a_color;

	ratio = ft_atof(s[1]);
	if (!in_range_float(ratio, 0.0f, 1.0f))
		return (NULL);
	color = get_color(s[2]);
	a_color = color_by_scaler(color, ratio);
	if (!color || !a_color)
		return (NULL);
	return (new_a_light(ratio, color, a_color));
}
