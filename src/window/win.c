/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:26:30 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/03 14:05:09 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	start_mlx(t_data *data)
{
	data->win = (t_window *)malloc(sizeof(t_window));
	if (!data->win)
		print_error(-1, "malloc", data);
	ft_memset(data->win, 0, sizeof(t_window));
	data->win->mlx_ptr = mlx_init();
	data->win->win_ptr = mlx_new_window(data->win->mlx_ptr, \
									WIDTH, HIGHT, TITLE);
	data->win->img.ptr = mlx_new_image(data->win->mlx_ptr, WIDTH, HIGHT);
	data->win->img.addr = mlx_get_data_addr(data->win->img.ptr, \
									&data->win->img.bpp, \
									&data->win->img.line_len, \
									&data->win->img.endian);
	mlx_key_hook(data->win->win_ptr, key_hook, data);
	mlx_hook(data->win->win_ptr, ButtonPress, ButtonPressMask, ft_mouse, data);
	mlx_hook(data->win->win_ptr, DestroyNotify, 0, close_window, data);
}

int	close_window(t_data *data)
{
	mlx_loop_end(data->win->mlx_ptr);
	mlx_destroy_image(data->win->mlx_ptr, data->win->img.ptr);
	mlx_destroy_window(data->win->mlx_ptr, data->win->win_ptr);
	mlx_destroy_display(data->win->mlx_ptr);
	// TODO free t_data and others it has
	free(data->win);
	free(data->scene);
	free(data);
	exit (0);
}

