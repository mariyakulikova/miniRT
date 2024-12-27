/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:42:52 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/27 16:12:32 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	*color_add(t_color *c1, t_color *c2)
{
	float	r;
	float	g;
	float	b;

	r = c1->r + c2->r;
	if (r > 1.0f)
		r = 1.0f;
	g = c1->g + c2->g;
	if (g > 1.0f)
		g = 1.0f;
	b = c1->b + c2->b;
	if (b > 1.0f)
		b = 1.0f;
	return (new_color(r, g, b));
}

t_color	*color_multi(t_color *c1, t_color *c2)
{
	return (new_color(c1->r * c2->r, c1->g * c2->g, c1->b * c2->b));
}

int	color_to_int(t_color *c)
{
	int	r;
	int	g;
	int	b;

	r = (int)(c->r * 255);
	g = (int)(c->g * 255);
	b = (int)(c->b * 255);
	return (r << 16 | g << 8 | b);
}

t_color	*color_by_scaler(t_color *c, float scaler)
{
	return (new_color(c->r * scaler, c->g * scaler, c->b * scaler));
}
