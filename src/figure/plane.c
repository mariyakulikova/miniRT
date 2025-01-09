/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:42:48 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/09 14:30:41 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_figure	*get_plane(t_ftype type, char **s)
{
	t_vector	*coord;
	t_vector	*nv3d;
	t_color		*color;

	coord = get_vec(s[1], false);
	if (!coord)
		return (NULL);
	nv3d = get_vec(s[2], true);
	if (!nv3d)
	{
		free(coord);
		return (NULL);
	}
	color = get_color(s[3]);
	if (!color)
	{
		free(coord);
		free(nv3d);
		return (NULL);
	}
	return (new_figure((t_figure){type, nv3d, coord, color, NULL, NULL, 0, 0}));
}
int plane_intersect(t_camera *camera, t_vector *ray, t_figure *plane)
{
	t_vector	*camera_to_plane;
	float		normal_dot_ray;
	float		normal_dot_dist;
	float		distance;

	normal_dot_ray = vec_dot_prod(plane->norm_v3d, ray);
	camera_to_plane = vec_sub(plane->coord, camera->origin);
	if (normal_dot_ray != 0)
	{
		normal_dot_dist = vec_dot_prod(camera_to_plane, plane->norm_v3d);
		distance = normal_dot_dist / normal_dot_ray;
		if (distance < 0)
			return (0);
		return (distance);
	}
	return 0;
}

void nearest_plane(t_data *data, t_dist *dist, t_vector *ray)
{
    int i;
    t_figure *figure;
    t_list *current;

    i = 0;
    current = data->scene->fugures;  // Начинаем с первого объекта в списке

    while (current != NULL)  // Пройдем по всем объектам в списке
    {
        figure = (t_figure *)current->content;  // Получаем фигуру из списка
        if (figure->type == PLANE)  // Если это плоскость
        {
            dist->dist = plane_intersect(data->scene->camera, ray, figure);  // Вызов пересечения для плоскости
            if (dist->dist > 0 && dist->dist < dist->min_dist)  // Если пересечение ближе
            {
                dist->min_dist = dist->dist;
                dist->near_obj = PLANE;  // Помечаем, что объект найден
                dist->n_obj = i;  // Сохраняем индекс объекта
            }
        }
        current = current->next;  // Переходим к следующему объекту
        i++;
    }
}
