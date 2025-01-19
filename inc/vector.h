/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:50:52 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/17 19:19:01 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

t_vector	*new_vec(float x, float y, float z);
t_vector	*vec_sub(t_vector *v1, t_vector *v2);
t_vector	*get_vec(char *str, bool need_check);
t_vector	*vec_add(t_vector *v1, t_vector *v2);
t_vector	*vec_by_scaler(t_vector *v, float scaler);
float		vec_len(t_vector *v);
void		vec_norm(t_vector *v);
float		vec_dot_prod(t_vector *v1, t_vector *v2);

#endif
