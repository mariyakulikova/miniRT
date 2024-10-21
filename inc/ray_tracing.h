/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:41:17 by mkulikov          #+#    #+#             */
/*   Updated: 2024/10/21 15:21:14 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACING_H
# define RAY_TRACING_H

typedef struct s_view_plane
{
	float	width;
	float	hight;
	float	x_pixel;
	float	y_pixel;
}	t_view_plane

void	ray_tracing(void *mlx, void *window, t_scene *scene);

#endif
