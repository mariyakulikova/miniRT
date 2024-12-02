/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:36:18 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/02 13:24:14 by mkulikov         ###   ########.fr       */
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

#endif
