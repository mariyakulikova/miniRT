/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 11:37:13 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 14:41:11 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include "../minilibx-linux/mlx.h"

static void	handle_resize(int keycode, t_figure *figure)
{
	if (figure->type == SPHERE)
	{
		if (keycode == XK_KP_Add)
			figure->diameter += 1;
		if (keycode == XK_KP_F1)
			figure->diameter -= 1;
	}
	else if (figure->type == CYLINDER)
	{
		if (keycode == XK_KP_0)
		{
			figure->diameter += 0.1;
			figure->hight += 0.1;
		}
		if (keycode == XK_KP_1)
		{
			figure->diameter -= 0.1;
			figure->hight -= 0.1;
		}
	}
}

int	ft_resize_hook(int keycode, t_data *data)
{
	printf("Hi from resize!\n");
	if (data->m_dist.near_obj == SPHERE || data->m_dist.near_obj == CYLINDER)
		handle_resize(keycode, data->m_dist.n_obj);
	// ray_tracing(data->win->mlx_ptr, data->win->win_ptr, data);
	return (0);
}
