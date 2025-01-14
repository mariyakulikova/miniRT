/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:47:38 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/14 15:38:39 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_key_hook_camera(int keycode, t_data *data)
{
	if (keycode == 0x73) //s
		data->scene->camera->direction->y += 0.1;
	if (keycode == 0x77) //w
		data->scene->camera->direction->y -= 0.1;
	if (keycode == 0x64) //d
		data->scene->camera->direction->x -= 0.1;
	if (keycode == 0x61) //a
		data->scene->camera->direction->x += 0.1;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		close_window(data);
	if (keycode == XK_Up)
		data->scene->camera->origin->y += 0.1;
	if (keycode == XK_Down)
		data->scene->camera->origin->y -= 0.1;
	if (keycode == XK_Right)
		data->scene->camera->origin->x += 0.1;
	if (keycode == XK_Left)
		data->scene->camera->origin->x -= 0.1;
	if (keycode == 0xffab) //+
		data->scene->camera->origin->z -= 1;
	if (keycode == 0xffad) //-
		data->scene->camera->origin->z += 1;
	ft_key_hook_camera(keycode, data);
	ray_tracing(data->win->mlx_ptr, data->win->win_ptr, data);
	return (0);
}