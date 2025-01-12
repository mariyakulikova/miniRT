/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:12:12 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/12 18:05:58 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	free_a_light(t_a_light *a)
{
	free(a->color);
	free(a->a_color);
	free(a);
}

static void	free_light(t_light *l)
{
	free(l->color);
	free(l->l_color);
	free(l->coord);
	free(l);
}

static void	free_figure(void *f)
{
	t_figure	*fig;

	fig = (t_figure *)f;
	if (fig->a_color)
		free(fig->a_color);
	if (fig->norm_v3d)
		free(fig->norm_v3d);
	if (fig->coord)
		free(fig->coord);
	if (fig->color)
		free(fig->color);
	if (fig->l_color)
		free(fig->l_color);
	free(f);
}

static void	free_camera(t_camera *c)
{
	if (c->origin)
		free(c->origin);
	if (c->direction)
		free(c->direction);
	free(c);
}

void	ultimate_free(t_data *data)
{
	if (data->win)
	{
		free(data->win->mlx_ptr);
		free(data->win);
	}
	if (data->scene)
	{
		if (data->scene->camera)
			free_camera(data->scene->camera);
		if (data->scene->light)
			free_light(data->scene->light);
		if (data->scene->a_light)
			free_a_light(data->scene->a_light);
		ft_lstclear(&(data->scene->fugures), &free_figure);
		free(data->scene);
	}
	free(data);
}

