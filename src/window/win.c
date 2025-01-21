/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:56:52 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 15:19:24 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HIGHT)
		return ;
	offset = (img->line_len * y) + (x * (img->bpp / 8));
	*((unsigned int *)(img->addr + offset)) = color;
}

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
	mlx_mouse_hook(data->win->win_ptr, mouse_hook, data);
	mlx_hook(data->win->win_ptr, KeyPress, KeyPressMask, key_hook, data);
	mlx_hook(data->win->win_ptr, DestroyNotify, 0, close_window, data);
}

int	close_window(t_data *data)
{
	mlx_loop_end(data->win->mlx_ptr);
	mlx_destroy_image(data->win->mlx_ptr, data->win->img.ptr);
	mlx_destroy_window(data->win->mlx_ptr, data->win->win_ptr);
	mlx_destroy_display(data->win->mlx_ptr);
	ultimate_free(data);
	exit (0);
}

