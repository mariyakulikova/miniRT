/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:14:03 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/16 15:46:48 by mkulikov         ###   ########.fr       */
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
static void	dist_init(t_dist *dist, t_vector *camera, t_vector *ray, t_list *objects)
{
	dist->dot_light = malloc(sizeof(t_vector));  // Для хранения направления на источник света
	dist->near_obj = 0;  // Изначально нет ближайшего объекта
	dist->n_obj = NULL;  // Изначально нет объекта
	dist->min_dist = FLT_MAX;
	t_list *node = objects;  // Устанавливаем максимально возможное расстояние
	while (node)
	{
		t_figure *figure = (t_figure *)node->content;
		if (figure->type == SPHERE)
			dist->dist = sphere_intersect(camera, ray, figure);  // Пересечение с шаром
		else if (figure->type == PLANE)
			dist->dist = plane_intersect(camera, ray, figure);  // Пересечение с плоскостью
		else if (figure->type == CYLINDER)
			dist->dist = cylinder_intersect(camera, ray, figure);  // Пересечение с цилиндром
        // Если пересечение найдено и оно ближе, чем ранее найденное минимальное, обновляем
		if (dist->dist > EPSILON && dist->dist < dist->min_dist)
		{
			dist->min_dist = dist->dist;
			dist->near_obj = figure->type;  // Запоминаем тип ближайшей фигуры
			dist->n_obj = figure;  // Запоминаем указатель на ближайшую фигуру
		}
		node = node->next;
	}
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
t_figure	*find_closest_figure(t_list *list, t_vector *camera, t_vector *ray, float *closest_t)
{
	t_dist dist;  // Структура для нахождения ближайшего объекта

	*closest_t = FLT_MAX;  // Изначально нет ближайшего объекта
    // Инициализация и поиск ближайшего объекта
	dist_init(&dist, camera, ray, list);
    // Если нашли ближайший объект, возвращаем его
	if (dist.n_obj != NULL)
	{
		*closest_t = dist.min_dist;
		return dist.n_obj;  // Возвращаем ближайшую фигуру
	}
	return (NULL);  // Если фигуры нет, возвращаем NULL
}

bool is_shadowed(t_ray_tracing_params	*params, t_data *d, t_vector *p)
{
	t_figure	*f;
	t_vector	*l_ray;
	float		distance;

	l_ray = vec_sub(d->scene->light->coord, p);
	distance = vec_len(l_ray);
	vec_norm(l_ray);
	f = find_closest_figure(d->scene->fugures, p, l_ray, &params->closest_t);
	// if (f == NULL)
	// 	return (false);
	if (f && params->closest_t < distance)
		return (true);
	return (false);
}

void	ray_tracing(void *mlx, void *window, t_data *d)
{
	t_ray_tracing_params	params;
	int						color;

	params.vplane = get_view_port(d->scene->width, d->scene->hight, d->scene->camera->fov);
	params.mlx_y = 0;
	params.y_angle = (d->scene->hight / 2) + (d->scene->camera->direction->y * d->scene->hight / 2.0f);
	while (params.y_angle > ((d->scene->hight / 2) * (-1) + (d->scene->camera->direction->y * d->scene->hight / 2.0f)))
	{
		params.y_ray = params.y_angle * params.vplane->y_pixel;
		params.x_angle = (d->scene->width / 2) * (-1) + (d->scene->camera->direction->x * d->scene->hight / 2.0f);
		params.mlx_x = 0;
		while (params.x_angle < (d->scene->width / 2) + (d->scene->camera->direction->x * d->scene->hight / 2.0f))
		{
			params.x_ray = params.x_angle * params.vplane->x_pixel;
			params.ray = new_vec(params.x_ray, params.y_ray, d->scene->camera->direction->z);  // Направление луча
			vec_norm(params.ray);  // Нормализуем луч
			params.closest_figure = find_closest_figure(d->scene->fugures, d->scene->camera->origin, params.ray, &params.closest_t);
			if (params.closest_t < FLT_MAX)
			{
				p = get_p_point(d->scene->camera->origin, params.ray, params.closest_t, d); // Вычисляешь точку пересечения
				is_shadow = is_shadowed(&params, d, p);
				color = get_figure_color(is_shadow, params.closest_figure, p, d);// Получаем цвет фигуры
			// Я так понимаю, что тень должна считаться где-то в этом месте и если тень есть, то ты меняешь color
			/*
			1.Вычисляешь точку пересечения с объектом
			2.Направление от точки пересечения к источнику света + нормализуешь
			3.Рассчитываешь, есть ли тень на точке пересечения луча, и, если тень есть,
			она будет определять её цвет, исходя из положения объектов сцены и источника света.
			4.Если тень есть, то изменяешь цвет
			*/
			}
			else
			{
				// 	color = 8421376;
				color = 16777215;  // Цвет фона 16776960
				// is_shadow = is_shadowed(&params, d, p);
				// if (is_shadow)
				// 	color = 8421376;
			}
			// printf("is_shadow = %d\n", is_shadow);
			mlx_pixel_put(mlx, window, params.mlx_x, params.mlx_y, color);  // Рисуем пиксель
			free(params.ray);  // Освобождаем память
			params.x_angle++;
			params.mlx_x++;
		}
		params.y_angle--;
		params.mlx_y++;
	}
	free(params.vplane);
}


