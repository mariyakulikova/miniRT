/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:56:23 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 12:43:10 by alvutina         ###   ########.fr       */
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

static void	ft_key_hook_objects(int keycode, t_data *data)
{
	if (data->selected_object)
	{
		if (keycode == XK_i || keycode == XK_k || \
			keycode == XK_j || keycode == XK_l)
			ft_translate_hook(keycode, data);
		if (keycode == XK_r || keycode == XK_t || keycode == XK_y)
			ft_rotate_hook(keycode, data);
		if (keycode == 0xffb0 || keycode == 0xffb1)
			ft_resize_hook(keycode, data);
	}
	else
		printf("No object selected to manipulate.\n");
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
	ft_key_hook_objects(keycode, data);
	ray_tracing(data->win->mlx_ptr, data->win->win_ptr, data);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *data)
{
	t_vector *ray_dir;

    if (button == 1) // Left mouse button
    {
        ray_dir = calculate_ray_direction(x, y, data);
        data->m_dist.min_dist = FLT_MAX;
        dist_init(&data->m_dist, data->scene->camera->origin, ray_dir, data->scene->fugures);

        if (data->m_dist.n_obj) // If an object is found
        {
            data->selected_object = data->m_dist.n_obj; // Save selected object
            printf("Selected object type: %d\n", data->m_dist.near_obj);
            printf("Selected object address: %p\n", (void *)data->selected_object);
        }
        else
        {
            data->selected_object = NULL; // Clear selection if no object is found
            printf("No object selected.\n");
        }

        free(ray_dir);
    }
    else if (button == 3) // Right mouse button
    {
        data->selected_object = NULL; // Clear selection
        printf("Selection cleared.\n");
    }

    return (0);
}
