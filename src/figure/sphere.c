/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:40:53 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/23 11:12:12 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_sphere	*new_sphere(t_vector *center, float diameter)
// {
// 	t_sphere	*sphere;

// 	sphere = malloc(sizeof(t_sphere));
// 	if (!sphere)
// 		return (NULL);
// 	sphere->center = center;
// 	sphere->radius = radius;
// 	return (sphere);
// }

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
	return (new_figure((t_figure){type, NULL, coord, color, d, d}));
}

// Функция вычисления пересечения с сферой
int sphere_intersect(t_camera *camera, t_vector *ray, t_figure *sphere)
{
    float  b, c, discr, dist_1, dist_squared, radius_squared;
    t_vector *camera_sphere;

    // Вектор от камеры к центру сферы
    camera_sphere = vec_sub(camera->origin, sphere->coord);  

    // Расстояние между камерой и центром сферы
    dist_squared = vec_dot_prod(camera_sphere, camera_sphere);
    radius_squared = powf(sphere->diameter / 2.0, 2.0);

    // Выводим информацию для отладки
    printf("Camera-Sphere Vector: (%f, %f, %f)\n", camera_sphere->x, camera_sphere->y, camera_sphere->z);
    printf("Distance squared: %f\n", dist_squared);
    printf("Radius squared: %f\n", radius_squared);

    // Проверка, если камера внутри сферы
    if (dist_squared < radius_squared) {
        printf("Camera is inside the sphere!\n");
        free(camera_sphere);
        return 0;  // Нет пересечения, так как камера внутри сферы
    }

    // Дискриминант для квадратичного уравнения
    b = 2 * vec_dot_prod(camera_sphere, ray);  // Удваиваем скалярное произведение
    c = dist_squared - radius_squared;  // Вычисление c

    // Выводим промежуточные значения для отладки
    printf("b: %f\n", b);
    printf("c: %f\n", c);

    discr = (b * b) - 4 * c;  // Вычисление дискриминанта
    printf("Discriminant: %f\n", discr);

    free(camera_sphere);

    // Если дискриминант отрицателен, нет пересечений
    if (discr < 0) {
        return 0;
    }

    dist_1 = (-b - sqrt(discr)) / 2;  // Первый корень

    // Выводим корень для отладки
    printf("dist_1: %f\n", dist_1);

    // Если первый корень положительный, есть пересечение
    if (dist_1 > 0) {
        return 1;
    }

    return 0;  // Нет пересечений
}

// int sphere_intersect(t_camera *camera, t_vector *ray, t_figure *sphere)
// {
//     float b, c, discr, dist_1;
//     t_vector *camera_sphere;

//     dist_1 = 0;
//     camera_sphere = vec_sub(camera->origin, sphere->coord);  // Вектор от камеры к центру сферы
//  float dist_squared = vec_dot_prod(camera_sphere, camera_sphere);  // Это квадрат расстояния
//     float radius_squared = (sphere->diameter * sphere->diameter) / 4.0f;  // Квадрат радиуса

//     // Выводим отладочные значения
//     printf("dist_squared: %f\n", dist_squared);
//     printf("radius_squared: %f\n", radius_squared);
//     // Дискриминант для квадратичного уравнения
//     b = 2 * vec_dot_prod(camera_sphere, ray);  // Удваиваем скалярное произведение
//     c = vec_dot_prod(camera_sphere, camera_sphere) - (sphere->diameter * sphere->diameter) / 4.0f;  // Используем диаметр

//     discr = (b * b) - (4 * c);  // Вычисление дискриминанта
//     free(camera_sphere);
	
//     printf("b: %f\n", b);
//     printf("c: %f\n", c);
//     printf("discriminant: %f\n", discr);


//     if (discr < 0)  // Если дискриминант отрицательный, нет пересечений
//         return 0;

//     dist_1 = (-b - sqrt(discr)) / 2;  // Первый корень
//     //dist_2 = (-b + sqrt(discr)) / 2;  // Второй корень

// 	/*printf("dist_1: %f\n", dist_1);
//     printf("dist_2: %f\n", dist_2);*/

//     if (dist_1 > 0)  // Если первый корень положительный, есть пересечение
//         return 1;
//     return 0;  // Если пересечения нет
// }

// int	sphere_intersect(t_camera *camera, t_vector *ray, t_figure *sphere)
// {
// 	float		b;
// 	float		c;
// 	float		discr;
// 	float		dist_1;
// 	float		dist_2;
// 	t_vector	*camera_sphere;

// 	dist_1 = 0;
// 	dist_2 = 0;
// 	camera_sphere = vec_sub(camera->origin, sphere->coord);
// 	b = 2 * (vec_dot_prod(camera_sphere, ray));
// 	c = vec_dot_prod(camera_sphere, camera_sphere) - (sqrtf(sphere->diameter / 2));
// 	discr = (b * b) - (4 * c);
// 	free(camera_sphere);
// 	if (discr < 0)
// 		return (0);
// 	dist_1 = ((b * (-1)) - sqrt(discr)) / 2;
// 	dist_2 = ((b * (-1)) - sqrt(discr)) / 2;
// 	if (dist_1 > 0)
// 		return (1);
// 	return (0);
// }
