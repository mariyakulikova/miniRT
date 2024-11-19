/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:31:46 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/19 16:42:49 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_window	*win;

	t_vector	*sphere_center = new_vec(0, 0, -32);
	t_sphere	*sphere = new_sphere(sphere_center, 8/2);
	t_vector	*cam_origin = new_vec(0, 0, 0);
	t_vector	*cam_direction = new_vec(0, 0, -1);
	t_camera	*camera = new_camera(cam_origin, cam_direction, 70);
	t_scene		*scene = new_scene(camera, sphere);
	scene->width = WIDTH;
	scene->hight = HIGHT;

	win = (t_window *)malloc(sizeof(t_window));
	if (!win)
		return (1);
	ft_memset(win, 0, sizeof(t_window));
	start_mlx(win);
	ray_tracing(win->mlx_ptr, win->win_ptr, scene);
	mlx_loop(win->mlx_ptr);
	// TODO free structs
	return (0);
}
