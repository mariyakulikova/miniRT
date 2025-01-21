/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:37:13 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 11:45:11 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	handle_resize(int keycode, t_figure *figure)
{
	if (figure->type == SPHERE)
	{
		if (keycode == 0xffb0)
			figure->diameter += 0.1;
		if (keycode == 0xffb1)
			figure->diameter -= 0.1;
	}
	else if (figure->type == CYLINDER)
	{
		if (keycode == 0xffb0)
		{
			figure->diameter += 0.1;
			figure->hight += 0.1;
		}
		if (keycode == 0xffb1)
		{
			figure->diameter -= 0.1;
			figure->hight -= 0.1;
		}
	}
}

int	ft_resize_hook(int keycode, t_data *data)
{
	if (data->m_dist.near_obj == SPHERE || data->m_dist.near_obj == CYLINDER)
		handle_resize(keycode, data->m_dist.n_obj);
	ray_tracing(data->win->mlx_ptr, data->win->win_ptr, data);
	return (0);
}