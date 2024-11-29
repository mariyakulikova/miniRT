/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_light.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:55:03 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/29 14:11:56 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_a_light	*new_a_light(float ratio, t_color *color)
{
	t_a_light	*a_light;

	a_light = (t_a_light *)malloc(sizeof(t_a_light));
	if (!a_light)
		return (NULL);
	a_light->ratio = ratio;
	a_light->color = color;
	return (a_light);
}

t_a_light	*get_a_light(char **s)
{
	float		ratio;
	t_color		*color;

	ratio = ft_atof(s[1]);
	printf("\nget_a_light ratio %f\n", ratio);
	if (!in_range_float(ratio, 0.0f, 1.0f))
	{
		printf("TUT\n");
		return (NULL);
	}
	color = get_color(s[2]);
	if (!color)
		return (NULL);
	return (new_a_light(ratio, color));
}
