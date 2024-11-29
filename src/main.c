/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:31:46 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/29 17:17:58 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	check_agrs(int argc, char **argv)
{
	int		len;
	char	*tmp;
	bool	res;

	if (argc != 2)
		print_error(-1, "Need 1 argument\n", NULL);
	len = ft_strlen(*(argv + 1));
	if (len < 4)
		print_error(-1, "File name is not valid\n", NULL);
	tmp = ft_substr(*(argv + 1), len - 3, 3);
	res = ft_strcmp(".rt", tmp) == 0;
	free(tmp);
	if (!res)
		print_error(-1, "File name must have \'.rt\' extention\n", NULL);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	check_agrs(argc, argv);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		print_error(-1, "malloc", NULL);
	ft_memset(data, 0, sizeof(t_data));
	// t_vector	*sphere_center = new_vec(0, 0, -32);
	// t_sphere	*sphere = new_sphere(sphere_center, 8/2);
	// t_vector	*cam_origin = new_vec(0, 0, 0);
	// t_vector	*cam_direction = new_vec(0, 0, -1);
	// t_camera	*camera = new_camera(cam_origin, cam_direction, 70);
	// t_scene		*scene = new_scene(camera, sphere);
	// scene->width = WIDTH;
	// scene->hight = HIGHT;

	read_file(*(argv + 1), data);
	start_mlx(data);
	// ray_tracing(data->win->mlx_ptr, data->win->win_ptr, data->scene);
	mlx_loop(data->win->mlx_ptr);
	return (0);
}
