/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:56:43 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 16:33:07 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	translate(t_vector *v, float tx, float ty, float tz)
{
	v->x += tx;
	v->y += ty;
	v->z += tz;
}

static void	handle_translation(int keycode, t_vector *coord, float tx, float ty)
{
	if (keycode == XK_i)
		translate(coord, 0, ty, 0);
	if (keycode == XK_k)
		translate(coord, 0, -ty, 0);
	if (keycode == XK_l)
		translate(coord, tx, 0, 0);
	if (keycode == XK_j)
		translate(coord, -tx, 0, 0);
}

int	ft_translate_hook(int keycode, t_data *data)
{
	float	tx;
	float	ty;

	tx = 0.1;
	ty = 0.1;
	if (data->m_dist.near_obj == SPHERE)
		handle_translation(keycode, data->m_dist.n_obj->coord, tx, ty);
	else if (data->m_dist.near_obj == PLANE)
		handle_translation(keycode, data->m_dist.n_obj->coord, tx, ty);
	else if (data->m_dist.near_obj == CYLINDER)
		handle_translation(keycode, data->m_dist.n_obj->coord, tx, ty);
	ray_tracing(data);
	return (0);
}
