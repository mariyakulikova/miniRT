/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:36:18 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/24 13:27:23 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

t_sphere	*new_sphere(t_vector *c, float r);
t_figure	*new_figure(t_figure args);
t_figure	*get_cylinder(t_ftype type, char **s);
t_figure	*get_plane(t_ftype type, char **s);
t_figure	*get_sphere(t_ftype type, char **s);
t_ftype		get_ftype(char *id);
int			sphere_intersect(t_camera *camera, t_vector *ray, t_figure *sphere);
int			plane_intersect(t_camera *camera, t_vector *ray, t_figure *plane);
int			cylinder_intersect(t_camera *camera, t_vector *ray, t_figure *plane);

#endif
