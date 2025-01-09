/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:40:53 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/09 14:30:14 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


t_figure	*get_sphere(t_ftype type, char **s)
{
	t_color		*color;
	t_vector	*coord;
	float		d;

	color = get_color(s[3]);
	if (!color)
		return (NULL);
	coord = get_vec(s[1], false);
	if (!coord)
	{
		free(color);
		return (NULL);
	}
	d = ft_atof(s[2]);
	return (new_figure((t_figure){type, NULL, coord, color, NULL, NULL, d, d}));
}

// Функция вычисления пересечения с сферой
float sphere_intersect(t_camera *camera, t_vector *ray, t_figure *sphere)
{
	float  b, c, discr, dist_1, dist_squared, radius_squared;
	t_vector *camera_sphere;

	// Вектор от камеры к центру сферы
	camera_sphere = vec_sub(camera->origin, sphere->coord);

	// Расстояние между камерой и центром сферы
	dist_squared = vec_dot_prod(camera_sphere, camera_sphere);
	radius_squared = powf(sphere->diameter / 2.0f, 2.0f);

	// Проверка, если камера внутри сферы
	if (dist_squared < radius_squared) {
		free(camera_sphere);
		return 0;  // Нет пересечения, так как камера внутри сферы
	}
	// Дискриминант для квадратичного уравнения
	b = 2.0f * vec_dot_prod(camera_sphere, ray);  // Удваиваем скалярное произведение
	c = dist_squared - radius_squared;  // Вычисление c
	discr = powf(b, 2.0f) - 4.0f * c;  // Вычисление дискриминанта
	free(camera_sphere);
	// Если дискриминант отрицателен, нет пересечений
	if (discr < 0) {
		return 0;
	}
	dist_1 = (-b - sqrtf(discr)) / 2.0f;  // Первый корень
	// Если первый корень положительный, есть пересечение
	if (dist_1 > 0) {
		return dist_1;
	}
	return 0;  // Нет пересечений
}

void nearest_sphere(t_data *data, t_dist *dist, t_vector *ray)
{
    int i;
    t_figure *figure;
    t_list *current;

    i = 0;
    current = data->scene->fugures;  // Начинаем с первого объекта в списке

    while (current != NULL)  // Пройдем по всем объектам в списке
    {
        figure = (t_figure *)current->content;  // Получаем фигуру из списка
        if (figure->type == SPHERE)  // Если это сфера
        {
            dist->dist = sphere_intersect(data->scene->camera, ray, figure);  // Вызов пересечения для сферы
            if (dist->dist > 0 && dist->dist < dist->min_dist)  // Если пересечение ближе
            {
                dist->min_dist = dist->dist;
                dist->near_obj = SPHERE;  // Помечаем, что объект найден
                dist->n_obj = i;  // Сохраняем индекс объекта
            }
        }
        current = current->next;  // Переходим к следующему объекту
        i++;
    }
}

