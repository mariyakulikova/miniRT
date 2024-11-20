/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:26:30 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/20 17:16:41 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	start_mlx(t_window **win)
{
	*win = (t_window *)malloc(sizeof(t_window));
	if (!*win)
		return (1);
	ft_memset(*win, 0, sizeof(t_window));
	(*win)->mlx_ptr = mlx_init();
	(*win)->win_ptr = mlx_new_window((*win)->mlx_ptr, WIDTH, HIGHT, TITLE);
	(*win)->img.ptr = mlx_new_image((*win)->mlx_ptr, WIDTH, HIGHT);
	(*win)->img.addr = mlx_get_data_addr((*win)->img.ptr, \
									&(*win)->img.bpp, \
									&(*win)->img.line_len, \
									&(*win)->img.endian);
	mlx_key_hook((*win)->win_ptr, key_hook, win);
	mlx_hook((*win)->win_ptr, DestroyNotify, 0, close_window, win);
	return (0);
}

int	close_window(t_window *win)
{
	mlx_loop_end(win->mlx_ptr);
	mlx_destroy_image(win->mlx_ptr, win->img.ptr);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free(win);
	exit (0);
}

