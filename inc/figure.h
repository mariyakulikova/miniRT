/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:36:18 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/09 14:27:41 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

t_figure	*new_figure(t_figure args);
t_figure	*get_cylinder(t_ftype type, char **s);
t_figure	*get_plane(t_ftype type, char **s);
t_figure	*get_sphere(t_ftype type, char **s);
t_ftype		get_ftype(char *id);
float		sphere_intersect(t_camera *camera, t_vector *ray, t_figure *sphere);
int			plane_intersect(t_camera *camera, t_vector *ray, t_figure *plane);
int			cylinder_intersect(t_camera *camera, t_vector *ray, t_figure *plane);
int			get_figure_color(t_figure *figure, t_vector *p, float t, t_data *d);
void        nearest_sphere(t_data *data, t_dist *dist, t_vector *ray);
void nearest_plane(t_data *data, t_dist *dist, t_vector *ray);
void nearest_cylinder(t_data *data, t_dist *dist, t_vector *ray);

#endif
