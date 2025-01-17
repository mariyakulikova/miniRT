/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   2_vec.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cmarguer <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/27 16:33:36 by mkulikov		  #+#	#+#			 */
/*   Updated: 2025/01/17 15:34:40 by cmarguer		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minirt.h"

t_vector	*get_vec(char *str, bool need_check)
{
	char		**s;
	float		x;
	float		y;
	float		z;

	s = ft_split(str, ',');
	if (!s)
		return (NULL);
	x = ft_atof(s[0]);
	y = ft_atof(s[1]);
	z = ft_atof(s[2]);
	ft_free_split(s);
	if (need_check)
	{
		if (in_range_float(x, -1.0f, 1.0f) \
			&& in_range_float(y, -1.0f, 1.0f) \
			&& in_range_float(z, -1.0f, 1.0f))
			return (new_vec(x, y, z));
		else
			return (NULL);
	}
	return (new_vec(x, y, z));
}

t_vector	*calculate_ray_direction(int x, int y, t_data *data)
{
	float		x_ray;
	float		y_ray;
	t_vector	*ray_dir;

	x_ray = (x - data->scene->width / 2) / (float)data->scene->width;
	y_ray = (data->scene->hight / 2 - y) / (float)data->scene->hight;
	ray_dir = new_vec(x_ray, y_ray, data->scene->camera->direction->z);
	vec_norm(ray_dir);
	return (ray_dir);
}
