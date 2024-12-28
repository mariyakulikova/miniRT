/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 18:42:52 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/28 17:43:54 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	*color_add(t_color *c1, t_color *c2)
{
	float	r;
	float	g;
	float	b;

	r = fmin(c1->r + c2->r, 1.0f);
	g = fmin(c1->g + c2->g, 1.0f);
	b = fmin(c1->b + c2->b, 1.0f);
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
