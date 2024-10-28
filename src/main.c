/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:31:46 by mkulikov          #+#    #+#             */
/*   Updated: 2024/10/28 11:17:18 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_window	*win;

	t_vector *sp_center = new_vec(3, 2, -32);
	t_sphere *sp = new_sphere(sp_center, 12/2);
	t_vector *cam_ori = new_vec(0, 0, 0);
	t_vector *cam_dir = new_vec(0, 0, -1);
	t_camera *cam = new_camera(cam_ori, cam_dir, 90);
	t_scene *sc = new_scene(cam, sp);
	win = (t_window *)malloc(sizeof(t_window));
	if (!win)
		return (1);
	ft_memset(win, 0, sizeof(t_window));
	start_mlx(win);
	ray_tracing(win->mlx_ptr, win->win_ptr, sc);
	mlx_loop(win->mlx_ptr);
	// TODO free structs
	return (0);
}
