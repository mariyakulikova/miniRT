/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:36:18 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/19 15:42:05 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURE_H
# define FIGURE_H

typedef struct s_sphere
{
	t_vector	*center;
	float		radius;
}	t_sphere;


t_sphere	*new_sphere(t_vector *c, float r);
int			sphere_intersect(t_camera *camera, t_vector *ray, t_sphere *sphere);

#endif
