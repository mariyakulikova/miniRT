/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:56:23 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/22 12:41:26 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	ft_key_hook_camera(int keycode, t_data *data)
{
	if (keycode == XK_s)
		rotate_x(data->scene->camera->origin, 10.0);
	if (keycode == XK_w)
		rotate_x(data->scene->camera->origin, -10.0);
	if (keycode == XK_d)
		rotate_y(data->scene->camera->origin, 10.0);
	if (keycode == XK_a)
		rotate_y(data->scene->camera->origin, -10.0);
	if (keycode == XK_e)
		rotate_z(data->scene->camera->origin, 10.0);
	if (keycode == XK_f)
		rotate_z(data->scene->camera->origin, -10.0);
}

static void	ft_key_hook_objects(int keycode, t_data *data)
{
	if (data->selected_object && data->selected_object->type)
	{
		if (keycode == XK_i || keycode == XK_k || \
			keycode == XK_j || keycode == XK_l || \
			keycode == XK_u || keycode == XK_h)
			ft_translate_hook(keycode, data);
		else if (keycode == XK_x || keycode == XK_y || keycode == XK_z)
			ft_rotate_hook(keycode, data);
		else if (keycode == XK_KP_0 || keycode == XK_KP_1)
			ft_resize_hook(keycode, data);
	}
}

static void	ft_key_hook_light(int keycode, t_data *data)
{
	if (keycode == XK_m)
		data->scene->light->coord->x += 1;
	if (keycode == XK_n)
		data->scene->light->coord->x -= 1;
	if (keycode == XK_o)
		data->scene->light->coord->y += 1;
	if (keycode == XK_p)
		data->scene->light->coord->y -= 1;
	if (keycode == XK_b)
		data->scene->light->coord->z += 1;
	if (keycode == XK_c)
		data->scene->light->coord->z -= 1;
	if (keycode == XK_KP_7)
		rotate_x(data->scene->light->coord, 10.0);
	if (keycode == XK_KP_8)
		rotate_y(data->scene->light->coord, 10.0);
	if (keycode == XK_KP_9)
		rotate_z(data->scene->light->coord, 10.0);
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
	if (keycode == XK_KP_Add)
		data->scene->camera->origin->z -= 0.1;
	if (keycode == XK_KP_Subtract)
		data->scene->camera->origin->z += 0.1;
	ft_key_hook_camera(keycode, data);
	ft_key_hook_light(keycode, data);
	ft_key_hook_objects(keycode, data);
	ray_tracing(data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	t_vector	*ray_dir;

	if (button == 1)
	{
		ray_dir = calculate_ray_direction(x, y, data);
		data->m_dist.min_dist = FLT_MAX;
		dist_init(&data->m_dist, data->scene->camera->origin, \
						ray_dir, data->scene->fugures);
		if (data->m_dist.n_obj)
			data->selected_object = data->m_dist.n_obj;
		else
			data->selected_object = NULL;
		free(ray_dir);
	}
	else if (button == 3)
		data->selected_object = NULL;
	return (0);
}
