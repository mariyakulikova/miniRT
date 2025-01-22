/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:14:03 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/22 18:11:39 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	preset_ray_tracing(t_data *d)
{
	t_list		*node;
	t_figure	*f;

	if (!d->scene->camera)
		return ;
	d->scene->vplane = get_view_port(d->scene->width, d->scene->hight, \
	d->scene->camera->fov);
	node = d->scene->fugures;
	while (node)
	{
		f = (t_figure *)node->content;
		if (d->scene->a_light)
			f->a_color = color_multi(f->color, d->scene->a_light->a_color);
		else
			f->a_color = new_color(f->color->r, f->color->g, f->color->b);
		if (d->scene->light)
			f->l_color = color_multi(f->color, d->scene->light->l_color);
		else if (d->scene->a_light)
			f->l_color = new_color(f->color->r, f->color->g, f->color->b);
		else
			f->l_color = new_color(f->color->r, f->color->g, f->color->b);
		if (!f->a_color || !f->l_color)
			print_error(1, "malloc error\n", d);
		node = node->next;
	}
}

void	dist_init(t_dist *dist, t_vector *camera, \
						t_vector *ray, t_list *objects)
{
	t_list		*node;
	t_figure	*figure;

	dist->dot_light = malloc(sizeof(t_vector));
	dist->near_obj = 0;
	dist->n_obj = NULL;
	dist->min_dist = FLT_MAX;
	node = objects;
	while (node)
	{
		figure = (t_figure *)node->content;
		if (figure->type == SPHERE)
			dist->dist = sphere_intersect(camera, ray, figure);
		else if (figure->type == PLANE)
			dist->dist = plane_intersect(camera, ray, figure);
		else if (figure->type == CYLINDER)
			dist->dist = cylinder_intersect(camera, ray, figure);
		if (dist->dist > EPSILON && dist->dist < dist->min_dist)
		{
			dist->min_dist = dist->dist;
			dist->near_obj = figure->type;
			dist->n_obj = figure;
		}
		node = node->next;
	}
}

t_figure	*find_closest_figure(t_list *list, t_vector *camera, \
									t_vector *ray, float *closest_t)
{
	t_dist	dist;

	*closest_t = FLT_MAX;
	dist_init(&dist, camera, ray, list);
	if (dist.n_obj != NULL)
	{
		*closest_t = dist.min_dist;
		free(dist.dot_light);
		return (dist.n_obj);
	}
	free(dist.dot_light);
	return (NULL);
}

void	trace_pixel(t_data *d, t_ray_tracing_params *params)
{
	int	color;

	params->x_ray = params->x_angle * d->scene->vplane->x_pixel;
	params->ray = new_vec(params->x_ray, params->y_ray, \
	d->scene->camera->direction->z);
	vec_norm(params->ray);
	params->closest_figure = find_closest_figure(d->scene->fugures, \
		d->scene->camera->origin, params->ray, &params->closest_t);
	if (params->closest_t < FLT_MAX)
		color = get_figure_color(params->ray, params->closest_figure, \
							params->closest_t, d);
	else
		color = 16777215;
	my_pixel_put(&d->win->img, params->mlx_x, params->mlx_y, color);
	free(params->ray);
}

void	ray_tracing(t_data *d)
{
	t_ray_tracing_params	params;

	if (!d->scene->camera)
		return ;
	params.mlx_y = 0;
	params.y_angle = (d->scene->hight / 2) + \
		(d->scene->camera->direction->y * d->scene->hight / 2.0f);
	while (params.y_angle > ((d->scene->hight / 2) * (-1) + \
		(d->scene->camera->direction->y * d->scene->hight / 2.0f)))
	{
		params.y_ray = params.y_angle * d->scene->vplane->y_pixel;
		params.x_angle = (d->scene->width / 2) * (-1) + \
			(d->scene->camera->direction->x * d->scene->hight / 2.0f);
		params.mlx_x = 0;
		while (params.x_angle < (d->scene->width / 2) + \
			(d->scene->camera->direction->x * d->scene->hight / 2.0f))
		{
			trace_pixel(d, &params);
			params.x_angle++;
			params.mlx_x++;
		}
		params.y_angle--;
		params.mlx_y++;
	}
	mlx_put_image_to_window(d->win->mlx_ptr, d->win->win_ptr, \
							d->win->img.ptr, 0, 0);
}
