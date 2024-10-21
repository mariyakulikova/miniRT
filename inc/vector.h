/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:50:52 by mkulikov          #+#    #+#             */
/*   Updated: 2024/10/21 15:09:40 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

struct s_point
{
	float	x;
	float	y;
	float	z;
};

typedef struct s_point	t_vector;
typedef struct s_point	t_point;

t_vector	*new_vec(float x, float y, float z);
t_vector	*vec_sub(t_vector *v1, t_vector *v2);
float		vec_len(t_vector *v);
void		vec_norm(t_vector *v);
float		vec_dot_prod(t_vector *v1, t_vector *v2);

#endif
