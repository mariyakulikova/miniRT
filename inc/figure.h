/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:36:18 by mkulikov          #+#    #+#             */
/*   Updated: 2024/10/21 16:47:32 by mkulikov         ###   ########.fr       */
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
int			sphere_intersec(t_camera *cam, t_vector *ray, t_sphere *sp);

#endif
