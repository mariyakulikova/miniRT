/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:47:38 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/09 14:35:03 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_hook(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		return (close_window(data));
		// Управление камерой
	if (keysym == XK_Up)
		data->scene->camera->origin->y += 0.1;
	if (keysym == XK_Down)
		data->scene->camera->origin->y -= 0.1;
	if (keysym == XK_Left)
		data->scene->camera->origin->x -= 0.1;
	if (keysym == XK_Right)
		data->scene->camera->origin->x += 0.1;

	// Пример изменения FOV
	if (keysym == XK_plus)
		data->scene->camera->fov += 5;
	if (keysym == XK_minus)
		data->scene->camera->fov -= 5;

	// Перерисовка сцены
	ray_tracing(data);
	return (0);
}

int	ft_mouse(int button, int x, int y, t_data *data)
{
	if (button == Button1) // Левая кнопка мыши
	{
		printf("Mouse clicked at (%d, %d)\n", x, y);
		// Пример: Изменение радиуса первого объекта
		if (data->scene->sphere)
			data->scene->sphere->radius += 0.1;
	}
	// Перерисовка сцены
	ray_tracing(data);
	return (0);
}
