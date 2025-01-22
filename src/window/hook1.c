/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:56:43 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/22 12:33:45 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	translate(t_vector *v, float tx, float ty, float tz)
{
	v->x += tx;
	v->y += ty;
	v->z += tz;
}

static void	handle_translation(int keycode, t_vector *coord, \
									t_translation *trans)
{
	if (keycode == XK_i)
		translate(coord, 0, trans->ty, 0);
	if (keycode == XK_k)
		translate(coord, 0, -trans->ty, 0);
	if (keycode == XK_l)
		translate(coord, trans->tx, 0, 0);
	if (keycode == XK_j)
		translate(coord, -trans->tx, 0, 0);
	if (keycode == XK_u)
		translate(coord, 0, 0, trans->tz);
	if (keycode == XK_h)
		translate(coord, 0, 0, -trans->tz);
}

void	ft_translate_hook(int keycode, t_data *data)
{
	t_translation	trans;

	trans.tx = 0.1;
	trans.ty = 0.1;
	trans.tz = 0.1;
	if (data->m_dist.near_obj == SPHERE)
		handle_translation(keycode, data->m_dist.n_obj->coord, &trans);
	else if (data->m_dist.near_obj == PLANE)
		handle_translation(keycode, data->m_dist.n_obj->coord, &trans);
	else if (data->m_dist.near_obj == CYLINDER)
		handle_translation(keycode, data->m_dist.n_obj->coord, &trans);
}
