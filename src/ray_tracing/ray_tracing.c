/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:14:03 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/03 15:19:36 by alvutina         ###   ########.fr       */
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
// void ray_tracing(void *mlx, void *window, t_scene *scene)
// {
//     int mlx_x, mlx_y;
//     int color;
//     float x_ray, y_ray;
//     t_vector *ray;
//     t_vport *vplane;
//     t_figure *sphere;

//     sphere = find_figure(scene->fugures, SPHERE); // Получаем сферу
//     vplane = get_view_port(scene->width, scene->hight); // Получаем информацию о виртуальной плоскости

//     mlx_y = 0;
//     // Начинаем итерацию по всем пикселям
//     while (mlx_y < scene->hight)
//     {
//         y_ray = (scene->hight / 2.0f - mlx_y) * vplane->y_pixel; // Высота на виртуальной плоскости
//         mlx_x = 0;
//         while (mlx_x < scene->width)
//         {
//             x_ray = (mlx_x - scene->width / 2.0f) * vplane->x_pixel; // Ширина на виртуальной плоскости

//             // Направление луча от камеры к точке на экране
//             ray = new_vec(x_ray, y_ray, -1); 
//             vec_norm(ray); // Нормализуем луч

//             // Проверка на пересечение с сферой
//             if (sphere_intersect(scene->camera, ray, sphere))
//                 color = 16766720; // Цвет, если пересечение с сферой
//             else
//                 color = 16777215; // Цвет фона

//             mlx_pixel_put(mlx, window, mlx_x, mlx_y, color); // Отображение пикселя
//             free(ray);
//             mlx_x++;
//         }
//         mlx_y++;
//     }
// }

// void	ray_tracing(void *mlx, void *window, t_scene *scene)
// {
// 	int			mlx_x;
// 	int			mlx_y;
// 	float		x_angle;
// 	float		y_angle;
// 	int			color;
// 	float		y_ray;
// 	float		x_ray;
// 	t_vector	*ray;
// 	t_vport		*vplane;
// 	t_figure	*sphere;

// 	sphere = find_figure(scene->fugures, SPHERE);
// 	vplane = get_view_port(scene->width, scene->hight);
// 	mlx_y = 0;
// 	y_angle = (scene->hight / 2);
// 	while (y_angle >= (scene->hight / 2) * (-1))
// 	{
// 		y_ray = y_angle * vplane->y_pixel;
// 		x_angle = (scene->width / 2) * (-1);
// 		mlx_x = 0;
// 		while (x_angle <= scene->width / 2)
// 		{
// 			x_ray = x_angle * vplane->x_pixel;
// 			ray = new_vec(x_ray, y_ray, -1);
// 			vec_norm(ray);
// 			if (sphere_intersect(scene->camera, ray, sphere))
// 				color = 16766720;
// 			else
// 				color = 16777215;
// 			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
// 			free(ray);
// 			x_angle++;
// 			mlx_x++;
// 		}
// 		y_angle--;
// 		mlx_y++;
// 	}
// }
