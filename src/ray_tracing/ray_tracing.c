/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:14:03 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/23 11:34:27 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_figure	*find_figure(t_list *list, t_ftype type)
{
	t_list		*node;
	t_figure	*res;

	node = list;
	while (node)
	{
		res = (t_figure *)node->content;
		if (res->type == type)
			return (res);
		node = node->next;
	}
	return (NULL);
}

// Функция трассировки лучей
void ray_tracing(void *mlx, void *window, t_scene *scene)
{
    int mlx_x, mlx_y;
    float x_angle, y_angle, y_ray, x_ray;
    int color;
    t_vector *ray;
    t_vport *vplane;
    t_figure *sphere;

    // Находим сферу в сцене
    sphere = find_figure(scene->fugures, SPHERE);
    vplane = get_view_port(scene->width, scene->hight);

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

            // Проверка на пересечение с сферой
            if (sphere_intersect(scene->camera, ray, sphere)) {
                color = 16766720;  // Цвет при пересечении
            } else {
                color = 16777215;  // Цвет фона
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
