/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:05:58 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/03 13:45:14 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	*calculate_cylinder_normal(t_figure *f, t_vector *p)
{
	t_vector	*normal;
	t_vector	*tmp;
	float		n;

	tmp = vec_sub(f->coord, p);
	vec_norm(f->norm_v3d); // Normalize the cylinder's orientation vector
	n = -vec_dot_prod(tmp, f->norm_v3d);
	normal = new_vec(
		-(f->norm_v3d->x * n + f->coord->x - p->x),
		-(f->norm_v3d->y * n + f->coord->y - p->y),
		-(f->norm_v3d->z * n + f->coord->z - p->z));
	vec_norm(normal); // Normalize the calculated normal
	free(tmp);
	return (normal);
}

static t_vector	*get_normal(t_figure *f, t_vector *p, t_data *d)
{
	t_vector	*normal;

	if (f->type == SPHERE)
		normal = vec_sub(p, f->coord);
	else if (f->type == PLANE)
		normal = new_vec(f->norm_v3d->x, f->norm_v3d->y, f->norm_v3d->z);
	else if (f->type == CYLINDER)
		normal = calculate_cylinder_normal(f, p);
	if (!normal)
		print_error(1, "malloc error", d);

	printf("normal: (%f, %f, %f) | ", normal->x, normal->y, normal->z);
	vec_norm(normal);
	return (normal);
}

static t_color	*get_diffuse_color(t_data *d, t_figure *figure, float light_dot_normal)
{
	t_color	*diffuse;

	if (light_dot_normal < 0)
		diffuse = new_color(0, 0, 0);
	else
		diffuse = color_by_scaler(figure->l_color, light_dot_normal);
	if (!diffuse)
		print_error(1, "malloc error", d);
	return (diffuse);
}

static t_vector	*get_p_point(t_vector *camera, t_vector *ray, float t, t_data *d)
{
	t_vector	*p;
	float		x;
	float		y;
	float		z;

	x = camera->x + ray->x * t;
	y = camera->y + ray->y * t;
	z = camera->z + ray->z * t;
	p = new_vec(x, y, z);
	if (!p)
		print_error(1, "malloc error\n", d);
	return (p);
}

int	get_figure_color(t_figure *figure, t_vector *ray, float t, t_data *d)
{
	t_vector	*light_vec;
	t_vector	*normal;
	t_vector	*p;
	t_color		*diffuse;
	float		light_dot_normal;
	int			res;
	t_color		*tmp;

	printf("ray: (%f, %f, %f), t: %f | ", ray->x, ray->y, ray->z, t);

	p = get_p_point(d->scene->camera->origin, ray, t, d);
	printf("p: (%f, %f, %f) ", p->x, p->y, p->z);

	light_vec = vec_sub(d->scene->light->coord, p);
	printf("light_vec: (%f, %f, %f) ", light_vec->x, light_vec->y, light_vec->z);

	vec_norm(light_vec);
	normal = get_normal(figure, p, d);
	printf("lv_norm: (%f, %f, %f) ", light_vec->x, light_vec->y, light_vec->z);
	printf("n_norm: (%f, %f, %f) | ", normal->x, normal->y, normal->z);
	light_dot_normal = vec_dot_prod(light_vec, normal);
	printf("dot: %f\n", light_dot_normal);

	diffuse = get_diffuse_color(d, figure, light_dot_normal);
	tmp = color_add(figure->a_color, diffuse);
	res = color_to_int(tmp);
	free(light_vec);
	free(normal);
	free(diffuse);
	free(tmp);
	return (res);
}
