/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:36:18 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/25 21:30:07 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

t_sphere	*new_sphere(t_vector *c, float r);
t_figure	*new_figure(char *id, t_vector *norm_v3d, t_vector *coord,\
						 float hight, float diameter, t_color *color);
int			sphere_intersect(t_camera *camera, t_vector *ray, t_sphere *sphere);

#endif
