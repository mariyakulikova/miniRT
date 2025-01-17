/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   vector.h										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cmarguer <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/18 10:50:52 by mkulikov		  #+#	#+#			 */
/*   Updated: 2025/01/17 15:35:12 by cmarguer		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

t_vector	*new_vec(float x, float y, float z);
t_vector	*vec_sub(t_vector *v1, t_vector *v2);
t_vector	*get_vec(char *str, bool need_check);
float		vec_len(t_vector *v);
void		vec_norm(t_vector *v);
float		vec_dot_prod(t_vector *v1, t_vector *v2);
t_vector	*calculate_ray_direction(int x, int y, t_data *data);

#endif
