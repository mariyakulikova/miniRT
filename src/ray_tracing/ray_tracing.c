/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:14:03 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/09 14:42:18 by cmarguer         ###   ########.fr       */
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

static void dist_init(t_dist *dist, t_data *data, t_vector *ray)
{
   // Выделяем память для точки освещения
	dist->dot_light = malloc(sizeof(t_vector));  // Теперь это t_vector, а не t_coord
	dist->near_obj = -1;  // По умолчанию объект не найден
	dist->n_obj = -1;    // Инициализируем идентификатор объекта
	dist->min_dist = 2147483647;  // Минимальное расстояние для поиска ближайшего объекта
	nearest_sphere(data, dist, ray);
	nearest_plane(data, dist, ray);
	nearest_cylinder(data, dist, ray);
}

static void draw_objects(t_data *data, t_vector *ray, int *color, int i)
{
	t_dist		*dist;
	t_figure	*figure;
	t_vector	*intersection_point;
	t_list       *current_figure;

	dist = malloc(sizeof(t_dist));
	dist_init(dist, data, ray);
	vec_multiply(ray, dist->min_dist);
	intersection_point = vector_addition(ray, data->scene->camera->origin);
	if (dist->near_obj == -1)
		*color = 16777215;
	else
	{
        current_figure = data->scene->fugures;  // Начинаем с головы списка
        while (current_figure != NULL && i < dist->n_obj)
        {
            current_figure = current_figure->next;  // Переходим к следующему элементу
            i++;
        }
        if (current_figure != NULL)
        {
            figure = (t_figure *)current_figure->content;  // Получаем фигуру из содержимого
            *color = get_figure_color(figure, intersection_point, dist->min_dist, data);  // Рассчитываем цвет
        }
    }
	free(dist->dot_light);
	free(dist);
}

static void	ray_tracing_2(t_data *data, t_draw *draw)
{
	draw->x_ray = draw->x_angle * data->scene->camera->fov \
	+ data->scene->camera->origin->x;
	draw->y_ray = draw->y_angle * data->scene->camera->fov \
	+ data->scene->camera->origin->y;
	draw->ray = new_vec(draw->x_ray, draw->y_ray, \
	data->scene->camera->direction->z);
	vec_norm(draw->ray);
	draw_objects(data, draw->ray, &draw->color, 0);
	mlx_pixel_put(data->win->mlx_ptr, data->win->win_ptr, \
	draw->mlx_x, draw->mlx_y, draw->color);
	draw->x_angle++;
	draw->mlx_x++;
}

void	ray_tracing(t_data *data)
{
	t_draw	*draw;

	draw = malloc(sizeof(t_draw));
	draw->mlx_y = 0;
	draw->y_angle = data->scene->hight / 2
		+ (data->scene->camera->direction->y * data->scene->hight / 2.0f);
	while (draw->y_angle > (-1 * data->scene->hight / 2
			+ (data->scene->camera->direction->y * data->scene->hight / 2.0f)))
	{
		draw->y_ray = draw->y_angle * data->scene->camera->fov
			+ data->scene->camera->origin->y;
		draw->x_angle = -1 * data->scene->width / 2
			+ (data->scene->camera->direction->x * data->scene->width / 2.0f);
		draw->mlx_x = 0;
		while (draw->x_angle < data->scene->width / 2
			+ (data->scene->camera->direction->x * data->scene->width / 2.0f))
		{
			draw->ray = malloc(sizeof(t_vector));
			ray_tracing_2(data, draw);
			free(draw->ray);
		}
		draw->y_angle--;
		draw->mlx_y++;
	}
	free(draw);
}

// float intersect(t_camera *camera, t_vector *ray, t_figure *figure)
// {
// 	if (figure->type == SPHERE)
// 		return sphere_intersect(camera, ray, figure);
// 	else if (figure->type == PLANE)
// 		return plane_intersect(camera, ray, figure);
// 	else if (figure->type == CYLINDER)
// 		return cylinder_intersect(camera, ray, figure);
// 	return -1; // Нет пересечения
// }
// t_figure *find_closest_figure(t_list *list, t_camera *camera, t_vector *ray, float *closest_t)
// {
// 	t_list *node = list;
// 	t_figure *closest = NULL;
// 	*closest_t = FLT_MAX;

// 	while (node) {
// 		t_figure *figure = (t_figure *)node->content;
// 		float t = intersect(camera, ray, figure);
// 		if (t > EPSILON && t < *closest_t) {
// 			*closest_t = t;
// 			closest = figure;
// 		}
// 		node = node->next;
// 	}
// 	return closest;
// }

// // Функция трассировки лучей
// void ray_tracing(void *mlx, void *window, t_data *d)
// {
// 	int mlx_x, mlx_y;
// 	float x_angle, y_angle, y_ray, x_ray;
// 	int color;
// 	t_vector *ray;
// 	t_vport *vplane;
// 	float closest_t;

// 	vplane = get_view_port(d->scene->width, d->scene->hight, d->scene->camera->fov);

// 	mlx_y = 0;
// 	y_angle = (d->scene->hight / 2);

// 	while (y_angle >= (d->scene->hight / 2) * (-1)) {
// 		y_ray = y_angle * vplane->y_pixel;
// 		x_angle = (d->scene->width / 2) * (-1);
// 		mlx_x = 0;

// 		while (x_angle <= d->scene->width / 2) {
// 			x_ray = x_angle * vplane->x_pixel;
// 			ray = new_vec(x_ray, y_ray, -1);  // Направление луча
// 			vec_norm(ray);  // Нормализуем луч

// 			t_figure *closest_figure = find_closest_figure(d->scene->fugures, d->scene->camera, ray, &closest_t);
// 			if (closest_t < FLT_MAX) {
// 				color = get_figure_color(closest_figure, ray, closest_t, d); // Получаем цвет фигуры
// 			} else {
// 				color = 16777215;  // Цвет фона 16776960
// 			}
// 			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);  // Рисуем пиксель
// 			free(ray);  // Освобождаем память
// 			x_angle++;
// 			mlx_x++;
// 		}
// 		y_angle--;
// 		mlx_y++;
// 	}
// }
