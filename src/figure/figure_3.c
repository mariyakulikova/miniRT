/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:18:03 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/20 14:21:01 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color	*get_diff_c(t_data *d, t_figure *f, float light_dot_normal)
{
	t_color	*diffuse;

	diffuse = NULL;
	if (light_dot_normal < 0)
		diffuse = new_color(0, 0, 0);
	else
		diffuse = color_by_scaler(f->l_color, light_dot_normal);
	if (!diffuse)
		print_error(1, "malloc error", d);
	return (diffuse);
}

static t_vector	*get_p_point(t_vector *ray, float t, t_data *d)
{
	t_vector	*p;
	float		x;
	float		y;
	float		z;

	x = d->scene->camera->origin->x + ray->x * t;
	y = d->scene->camera->origin->y + ray->y * t;
	z = d->scene->camera->origin->z + ray->z * t;
	p = new_vec(x, y, z);
	if (!p)
		print_error(1, "malloc error\n", d);
	return (p);
}

static bool	is_shadowed(t_data *d, t_vector *p)
{
	t_figure	*f;
	t_vector	*l_ray;
	float		distance;
	float		closest_t;

	l_ray = vec_sub(d->scene->light->coord, p);
	distance = vec_len(l_ray);
	vec_norm(l_ray);
	f = find_closest_figure(d->scene->fugures, p, l_ray, &closest_t);
	free(l_ray);
	if (f && closest_t < distance)
		return (true);
	return (false);
}

static void	free_gfc(t_gfc *param)
{
	if (param->light_vec)
		free(param->light_vec);
	if (param->normal)
		free(param->normal);
	if (param->diffuse)
		free(param->diffuse);
	if (param->over_p)
		free(param->over_p);
	if (param->p)
		free(param->p);
	if (param->c_tmp)
		free(param->c_tmp);
	if (param->v_tmp)
		free(param->v_tmp);
}

int	get_figure_color(t_vector *ray, t_figure *f, float t, t_data *d)
{
	t_gfc	param;
	int		res;

	res = 0;
	ft_memset(&param, 0, sizeof(t_gfc));
	param.p = get_p_point(ray, t, d);
	param.normal = get_normal(f, param.p, d);
	param.v_tmp = vec_by_scaler(param.normal, 0.001f);
	param.over_p = vec_add(param.p, param.v_tmp);
	if (is_shadowed(d, param.over_p))
	{
		res = color_to_int(f->a_color);
		free_gfc(&param);
		return (res);
	}
	param.light_vec = vec_sub(d->scene->light->coord, param.over_p);
	vec_norm(param.light_vec);
	param.light_dot_normal = vec_dot_prod(param.light_vec, param.normal);
	param.diffuse = get_diff_c(d, f, param.light_dot_normal);
	param.c_tmp = color_add(f->a_color, param.diffuse);
	res = color_to_int(param.c_tmp);
	free_gfc(&param);
	return (res);
}
