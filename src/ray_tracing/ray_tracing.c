/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:14:03 by mkulikov          #+#    #+#             */
/*   Updated: 2024/10/21 16:16:10 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_view_plane	*new_vplane(float width, float hight, float fov)
{
	t_view_plane	*vp;
	float			ratio;
	(void)fov;

	vp = (t_view_plane *)malloc(sizeof(t_view_plane));
	if (!vp)
		return (NULL);
	ratio = width / hight;
	vp->width = 1;
	vp->hight = vp->width / ratio;
	vp->x_pixel = vp->width / width;
	vp->y_pixel = vp->hight / hight;
	return (vp);
}

void	ray_tracing(void *mlx, void *window, t_scene *sc)
{
	int				mlx_x;
	int				mlx_y;
	int				color = 0;
	float			x_angle;
	float			y_angle;
	float			y_ray;
	float			x_ray;
	t_vector		*ray;
	t_view_plane	*vp;

	mlx_y = 0;
	vp = new_vplane(sc->width, sc->hight, sc->cams->fov);
	y_angle = sc->hight / 2;
	while (y_angle >= (sc->hight / 2) * -1)
	{
		y_ray = y_angle * vp->y_pixel;
		x_angle = sc->width / 2 * -1;
		mlx_x = 0;
		while (x_angle <= sc->width / 2)
		{
			x_ray = x_angle * vp->x_pixel;
			ray = new_vec(x_ray, y_ray, -1);
			vec_norm(ray); // not sure if it's needed
			if (sphere_intersec(sc->cams, ray, sc->sphere))
				color = 16777215;
			else
				color = 0;
			mlx_pixel_put(mlx, window, mlx_x, mlx_y, color);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}
