/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracing.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:41:17 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/16 11:52:52 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACING_H
# define RAY_TRACING_H

typedef struct s_ray_tracing_params {
    int mlx_x;
    int mlx_y;
    float x_angle;
    float y_angle;
    float y_ray;
    float x_ray;
    float closest_t;
    t_figure *closest_figure;
    t_vector *ray;
    t_vport *vplane;
} t_ray_tracing_params;

void	ray_tracing(void *mlx, void *window, t_data *d);
void	preset_ray_tracing(t_data *d);
t_figure *find_closest_figure(t_list *list, t_vector *camera, t_vector *ray, float *closest_t);

#endif
