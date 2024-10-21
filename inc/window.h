/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:39:48 by mkulikov          #+#    #+#             */
/*   Updated: 2024/10/21 15:09:40 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# include <X11/keysym.h>
# include <X11/X.h>
# include "../minilibx-linux/mlx.h"

# define HIGHT 900
# define WIDTH 1200
# define WIN_CEF 0.95
# define TITLE "miniRT"

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_window {
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		min_x;
	int		min_y;
	int		max_x;
	int		max_y;
	int		offset_x;
	int		offset_y;
	float	zoom_ratio;
	float	angle;
}			t_window;

int		key_hook(int keysym, t_window *win);
void	start_mlx(t_window *win);
int		close_window(t_window *win);

#endif
