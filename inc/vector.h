/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:50:52 by mkulikov          #+#    #+#             */
/*   Updated: 2024/10/18 12:36:39 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

struct s_point
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_point	t_vector;
typedef struct s_point	t_point;

t_vector	*new_vec(double x, double y, double z);
t_vector	*vec_sub(t_vector *v1, t_vector *v2);
double		vec_len(t_vector *v);
void		vec_norm(t_vector *v);
double		vec_dot_prod(t_vector *v1, t_vector *v2);

#endif
