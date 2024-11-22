/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:50:52 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/22 15:54:11 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

t_vector	*new_vec(float x, float y, float z);
t_vector	*vec_sub(t_vector *v1, t_vector *v2);
float		vec_len(t_vector *v);
void		vec_norm(t_vector *v);
float		vec_dot_prod(t_vector *v1, t_vector *v2);

#endif
