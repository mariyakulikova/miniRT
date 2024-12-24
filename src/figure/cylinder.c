/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 20:32:36 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/24 13:56:11 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_figure	*get_cylinder(t_ftype type, char **s)
{
	t_vector	*coord;
	t_vector	*nv3d;
	t_color		*color;
	float		d;
	float		h;

	coord = get_vec(s[1], false);
	if (!coord)
		return (NULL);
	nv3d = get_vec(s[2], true);
	if (!nv3d)
	{
		free(coord);
		return (NULL);
	}
	color = get_color(s[5]);
	if (!color)
	{
		free(coord);
		free(nv3d);
		return (NULL);
	}
	d = ft_atof(s[3]);
	h = ft_atof(s[4]);
	return (new_figure((t_figure){type, nv3d, coord, color, h, d}));
}
/* int cylinder_intersect(t_camera *camera, t_vector *ray, t_figure *cylinder) {
    t_vector *oc = vec_sub(camera->origin, cylinder->coord);
    float a = vec_dot_prod(ray, ray) - pow(vec_dot_prod(ray, cylinder->norm_v3d), 2);
    float b = 2 * (vec_dot_prod(ray, oc) - vec_dot_prod(ray, cylinder->norm_v3d) * vec_dot_prod(oc, cylinder->norm_v3d));
    float c = vec_dot_prod(oc, oc) - pow(vec_dot_prod(oc, cylinder->norm_v3d), 2) - pow(cylinder->diameter / 2, 2);

    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
        return -1; // No intersection

    float t1 = (-b - sqrt(discriminant)) / (2 * a);
    float t2 = (-b + sqrt(discriminant)) / (2 * a);

    // Check cylinder caps
    float cap_t[2];
    for (int i = 0; i < 2; i++) {
        t_vector *cap_center = new_vec(
            cylinder->coord->x + i * cylinder->hight * cylinder->norm_v3d->x,
            cylinder->coord->y + i * cylinder->hight * cylinder->norm_v3d->y,
            cylinder->coord->z + i * cylinder->hight * cylinder->norm_v3d->z
        );
        float denom = vec_dot_prod(ray, cylinder->norm_v3d);
        if (fabs(denom) > 1e-6) {
            float t = vec_dot_prod(vec_sub(cap_center, camera->origin), cylinder->norm_v3d) / denom;
            t_vector *p = new_vec(
                camera->origin->x + t * ray->x,
                camera->origin->y + t * ray->y,
                camera->origin->z + t * ray->z
            );
            if (vec_len(vec_sub(p, cap_center)) <= cylinder->diameter / 2)
                cap_t[i] = t;
            else
                cap_t[i] = FLT_MAX;
            free(p);
        } else {
            cap_t[i] = FLT_MAX;
        }
        free(cap_center);
    }

    float t_min = FLT_MAX;
    if (t1 > 0 && t1 < t_min) t_min = t1;
    if (t2 > 0 && t2 < t_min) t_min = t2;
    if (cap_t[0] > 0 && cap_t[0] < t_min) t_min = cap_t[0];
    if (cap_t[1] > 0 && cap_t[1] < t_min) t_min = cap_t[1];

    return t_min == FLT_MAX ? -1 : t_min;
}

*/

static float base_intersect(t_camera *camera, t_vector *ray, t_figure *plane, float radius)
{
	float		distance;
	t_vector	*intersection_point;
	t_vector	*camera_to_point;

	// Вычисление пересечения луча с плоскостью
	distance = plane_intersect(camera, ray, plane);
	if (distance > 0)
	{
		// Точка пересечения
		intersection_point = new_vec(
			camera->origin->x + ray->x * distance,
			camera->origin->y + ray->y * distance,
			camera->origin->z + ray->z * distance
		);
		// Проверка, находится ли точка в пределах радиуса диска
		camera_to_point = vec_sub(intersection_point, plane->coord);
		if (vec_len(camera_to_point) <= radius)
		{
			free(intersection_point);
			free(camera_to_point);
			return (distance);
		}
		free(intersection_point);
		free(camera_to_point);
	}
	return (0);
}

static void	lateral_plane_intersect(t_camera *camera, t_vector *ray, t_figure *cylinder, float *d_min)
{
	t_vector	*camera_to_cylinder;
	float		a, b, c, discriminant;
	float		t1, t2, m;

	// Вектор от камеры до цилиндра
	camera_to_cylinder = vec_sub(camera->origin, cylinder->coord);
	// Вычисление коэффициентов квадратного уравнения
	a = vec_dot_prod(ray, ray) - pow(vec_dot_prod(ray, cylinder->norm_v3d), 2);
	b = 2 * (vec_dot_prod(ray, camera_to_cylinder) -
			(vec_dot_prod(ray, cylinder->norm_v3d) * vec_dot_prod(camera_to_cylinder, cylinder->norm_v3d)));
	c = vec_dot_prod(camera_to_cylinder, camera_to_cylinder) -
		pow(vec_dot_prod(camera_to_cylinder, cylinder->norm_v3d), 2) - pow(cylinder->diameter / 2, 2);
	discriminant = b * b - 4 * a * c;
	// Если дискриминант меньше нуля, пересечений нет
	if (discriminant < 0)
	{
		free(camera_to_cylinder);
		return ;
	}
	// Вычисление расстояний до пересечения
	t1 = (-b - sqrt(discriminant)) / (2 * a);
	t2 = (-b + sqrt(discriminant)) / (2 * a);
	// Проверка, попадает ли пересечение на боковую поверхность
	m = vec_dot_prod(ray, cylinder->norm_v3d) * t1 +
		vec_dot_prod(camera_to_cylinder, cylinder->norm_v3d);
	if (t1 > 0 && m >= 0 && m <= cylinder->hight)
		*d_min = t1;
	m = vec_dot_prod(ray, cylinder->norm_v3d) * t2 +
		vec_dot_prod(camera_to_cylinder, cylinder->norm_v3d);
	if (t2 > 0 && m >= 0 && m <= cylinder->hight && t2 < *d_min)
		*d_min = t2;
	free(camera_to_cylinder);
}

int	cylinder_intersect(t_camera *camera, t_vector *ray, t_figure *cylinder)
{
	float		d_min;
	float		dist_disc[2];
	t_figure	plane_top;
	t_figure	plane_bottom;

	d_min = FLT_MAX;

	// Проверяем пересечение с боковой поверхностью цилиндра
	lateral_plane_intersect(camera, ray, cylinder, &d_min);
	// Подготовка данных основания и крышки цилиндра
	plane_bottom = *cylinder;
	plane_top = *cylinder;
	plane_top.coord = new_vec(
		cylinder->coord->x + cylinder->norm_v3d->x * cylinder->hight,
		cylinder->coord->y + cylinder->norm_v3d->y * cylinder->hight,
		cylinder->coord->z + cylinder->norm_v3d->z * cylinder->hight
	);
	// Проверяем пересечение с основанием
	dist_disc[0] = base_intersect(camera, ray, &plane_bottom, cylinder->diameter / 2);
	if (dist_disc[0] > 0 && dist_disc[0] < d_min)
		d_min = dist_disc[0];
	// Проверяем пересечение с верхней крышкой
	dist_disc[1] = base_intersect(camera, ray, &plane_top, cylinder->diameter / 2);
	if (dist_disc[1] > 0 && dist_disc[1] < d_min)
		d_min = dist_disc[1];
	// Если пересечение найдено, возвращаем расстояние до него
	if (d_min < FLT_MAX)
		return (d_min);
	return (0);
}
