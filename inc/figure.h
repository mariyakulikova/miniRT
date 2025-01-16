/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:36:18 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/16 14:15:30 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

t_figure	*new_figure(t_figure args);
t_figure	*get_cylinder(t_ftype type, char **s);
t_figure	*get_plane(t_ftype type, char **s);
t_figure	*get_sphere(t_ftype type, char **s);
t_ftype		get_ftype(char *id);
float		sphere_intersect(t_vector *camera, t_vector *ray, t_figure *sphere);
float		plane_intersect(t_vector *camera, t_vector *ray, t_figure *plane);
float		cylinder_intersect(t_vector *camera, t_vector *ray, t_figure *plane);
int			get_figure_color(bool is_shadow, t_figure *figure, t_vector *p, t_data *d);
t_vector	*get_p_point(t_vector *camera, t_vector *ray, float t, t_data *d);

#endif
