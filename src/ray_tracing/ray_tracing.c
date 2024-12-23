/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:14:03 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/02 13:28:37 by mkulikov         ###   ########.fr       */
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

void	ray_tracing(void *mlx, void *window, t_scene *scene)
{
	int			mlx_x;
	int			mlx_y;
	float		x_angle;
	float		y_angle;
	int			color;
	float		y_ray;
	float		x_ray;
	t_vector	*ray;
	t_vport		*vplane;
	t_figure	*sphere;

	sphere = find_figure(scene->fugures, SPHERE);
	vplane = get_view_port(scene->width, scene->hight);
	mlx_y = 0;
	y_angle = (scene->hight / 2);
	while (y_angle >= (scene->hight / 2) * (-1))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = (scene->width / 2) * (-1);
		mlx_x = 0;
		while (x_angle <= scene->width / 2)
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vec(x_ray, y_ray, -1);
			vec_norm(ray);
			if (sphere_intersect(scene->camera, ray, sphere))
				color = 16766720;
			else
				color = 16777215;
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}
