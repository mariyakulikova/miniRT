/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:36:18 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/21 11:04:53 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

typedef struct s_gfc
{
	t_vector	*light_vec;
	t_vector	*normal;
	t_color		*diffuse;
	t_vector	*over_p;
	t_vector	*p;
	t_color		*c_tmp;
	t_vector	*v_tmp;
	float		light_dot_normal;
}	t_gfc;

t_figure	*new_figure(t_figure args);
t_figure	*get_cylinder(t_ftype type, char **s);
t_figure	*get_plane(t_ftype type, char **s);
t_figure	*get_sphere(t_ftype type, char **s);
t_ftype		get_ftype(char *id);
float		sphere_intersect(t_vector *camera, t_vector *ray, t_figure *sphere);
float		plane_intersect(t_vector *camera, t_vector *ray, t_figure *plane);
float		cylinder_intersect(t_vector *camera, \
											t_vector *ray, t_figure *plane);
int			get_figure_color(t_vector *ray, t_figure *f, float t, t_data *d);
t_vector	*get_normal(t_figure *f, t_vector *p, t_data *d);
float		cylinder_base_intersect(t_vector *camera, t_vector *ray, \
									t_figure *cylinder, float *d_min);

#endif
