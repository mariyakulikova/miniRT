/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:52:31 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 16:36:47 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# define HIGHT 900
# define WIDTH 1200
# define WIN_CEF 0.95
# define TITLE "data"

int		key_hook(int keysym, t_data *data);
void	start_mlx(t_data *data);
int		close_window(t_data *data);
int		mouse_hook(int button, int x, int y, t_data *data);
void	my_pixel_put(t_img *img, int x, int y, int color);

#endif
