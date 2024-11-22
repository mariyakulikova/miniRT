/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:26:30 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/22 14:41:25 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	start_mlx(t_minirt *minirt)
{
	minirt->win = (t_window *)malloc(sizeof(t_window));
	if (!minirt->win)
		print_error(-1, strerror(errno), minirt);
	ft_memset(minirt->win, 0, sizeof(t_window));
	minirt->win->mlx_ptr = mlx_init();
	minirt->win->win_ptr = mlx_new_window(minirt->win->mlx_ptr, \
									WIDTH, HIGHT, TITLE);
	minirt->win->img.ptr = mlx_new_image(minirt->win->mlx_ptr, WIDTH, HIGHT);
	minirt->win->img.addr = mlx_get_data_addr(minirt->win->img.ptr, \
									&minirt->win->img.bpp, \
									&minirt->win->img.line_len, \
									&minirt->win->img.endian);
	mlx_key_hook(minirt->win->win_ptr, key_hook, minirt);
	mlx_hook(minirt->win->win_ptr, DestroyNotify, 0, close_window, minirt);
}

int	close_window(t_minirt *minirt)
{
	mlx_loop_end(minirt->win->mlx_ptr);
	mlx_destroy_image(minirt->win->mlx_ptr, minirt->win->img.ptr);
	mlx_destroy_window(minirt->win->mlx_ptr, minirt->win->win_ptr);
	mlx_destroy_display(minirt->win->mlx_ptr);
	// TODO free t_minirt and others it has
	free(minirt->win);
	free(minirt->scene);
	free(minirt);
	exit (0);
}

