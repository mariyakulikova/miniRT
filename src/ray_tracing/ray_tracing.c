/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:14:03 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/12 17:26:17 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	preset_ray_tracing(t_data *d)
{
	t_list		*node;
	t_figure	*f;

	node = d->scene->fugures;
	while (node)
	{
		f = (t_figure *)node->content;
		f->a_color = color_multi(f->color, d->scene->a_light->a_color);
		f->l_color = color_multi(f->color, d->scene->light->l_color);
		if (!f->a_color || !f->l_color)
			print_error(1, "malloc error\n", d);
		node = node->next;
	}
}

float intersect(t_camera *camera, t_vector *ray, t_figure *figure)
{
	if (figure->type == SPHERE)
		return sphere_intersect(camera, ray, figure);
	else if (figure->type == PLANE)
		return plane_intersect(camera, ray, figure);
	else if (figure->type == CYLINDER)
		return cylinder_intersect(camera, ray, figure);
	return -1; // Нет пересечения
}
t_figure *find_closest_figure(t_list *list, t_camera *camera, t_vector *ray, float *closest_t)
{
	t_list *node = list;
	t_figure *closest = NULL;
	*closest_t = FLT_MAX;

	while (node) {
		t_figure *figure = (t_figure *)node->content;
		float t = intersect(camera, ray, figure);
		if (t > EPSILON && t < *closest_t) {
			*closest_t = t;
			closest = figure;
		}
		node = node->next;
	}
	return closest;
}

// Функция трассировки лучей
void ray_tracing(void *mlx, void *window, t_data *d)
{
	int mlx_x, mlx_y;
	float x_angle, y_angle, y_ray, x_ray;
	int color;
	t_vector *ray;
	t_vport *vplane;
	float closest_t;

	vplane = get_view_port(d->scene->width, d->scene->hight, d->scene->camera->fov);

	mlx_y = 0;
	y_angle = (d->scene->hight / 2);

	while (y_angle >= (d->scene->hight / 2) * (-1)) {
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (d->scene->width / 2) * (-1);
		mlx_x = 0;

		while (x_angle <= d->scene->width / 2) {
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vec(x_ray, y_ray, -1);  // Направление луча
			vec_norm(ray);  // Нормализуем луч

			t_figure *closest_figure = find_closest_figure(d->scene->fugures, d->scene->camera, ray, &closest_t);
			if (closest_t < FLT_MAX) {
				color = get_figure_color(closest_figure, ray, closest_t, d); // Получаем цвет фигуры
			} else {
				color = 16777215;  // Цвет фона 16776960
			}
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);  // Рисуем пиксель
			free(ray);  // Освобождаем память
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
	free(vplane);
}
