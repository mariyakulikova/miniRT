/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:31:46 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/20 17:18:29 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_agrs(int argc, char **argv)
{
	int		len;
	char	*tmp;
	bool	res;

	if (argc != 2)
		print_error(-1, "Need 1 argument\n", NULL, NULL);
	len = ft_strlen(*(argv + 1));
	if (len < 4)
		print_error(-1, "File name is not valid\n", NULL, NULL);
	tmp = ft_substr(*(argv + 1), len - 3, 3);
	res = ft_strcmp(".rt", tmp) == 0;
	free(tmp);
	if (!res)
		print_error(-1, "File name must have \'.rt\' extention\n", NULL, NULL);
}

int	main(int argc, char **argv)
{
	t_window	*win;
	t_scene		*scene;

	check_agrs(argc, argv);

	// t_vector	*sphere_center = new_vec(0, 0, -32);
	// t_sphere	*sphere = new_sphere(sphere_center, 8/2);
	// t_vector	*cam_origin = new_vec(0, 0, 0);
	// t_vector	*cam_direction = new_vec(0, 0, -1);
	// t_camera	*camera = new_camera(cam_origin, cam_direction, 70);
	// t_scene		*scene = new_scene(camera, sphere);
	// scene->width = WIDTH;
	// scene->hight = HIGHT;

	parse_file(*(argv + 1), &scene);
	if (start_mlx(&win))
		print_error(-1, strerror(errno), NULL, scene);
	ray_tracing(win->mlx_ptr, win->win_ptr, scene);
	mlx_loop(win->mlx_ptr);
	// TODO free structs
	return (0);
}
