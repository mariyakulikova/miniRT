/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:14:03 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/27 17:14:35 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_figure	*find_figure(t_list *list, t_ftype type)
// {
// 	t_list		*node;
// 	t_figure	*res;

// 	node = list;
// 	while (node)
// 	{
// 		res = (t_figure *)node->content;
// 		if (res->type == type)
// 			return (res);
// 		node = node->next;
// 	}
// 	return (NULL);
// }

void	prep_rt(t_data *d)
{
	set_figure_a_color(d);
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
void ray_tracing(void *mlx, void *window, t_scene *scene)
{
	int mlx_x, mlx_y;
	float x_angle, y_angle, y_ray, x_ray;
	int color;
	t_vector *ray;
	t_vport *vplane;
	float closest_t;

	vplane = get_view_port(scene->width, scene->hight, scene->camera->fov);

	mlx_y = 0;
	y_angle = (scene->hight / 2);

	while (y_angle >= (scene->hight / 2) * (-1)) {
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (scene->width / 2) * (-1);
		mlx_x = 0;

		while (x_angle <= scene->width / 2) {
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vec(x_ray, y_ray, -1);  // Направление луча
			vec_norm(ray);  // Нормализуем луч

			t_figure *closest_figure = find_closest_figure(scene->fugures, scene->camera, ray, &closest_t);
			if (closest_t < FLT_MAX) {
				color = get_figure_color(closest_figure); // Получаем цвет фигуры
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
}
