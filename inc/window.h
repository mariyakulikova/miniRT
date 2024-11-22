/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:39:48 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/22 16:37:01 by mkulikov         ###   ########.fr       */
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
# define TITLE "data"

int		key_hook(int keysym, t_data *data);
void	start_mlx(t_data *data);
int		close_window(t_data *data);

#endif
