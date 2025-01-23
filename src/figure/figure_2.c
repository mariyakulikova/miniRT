/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:05:58 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/23 13:31:44 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	*calculate_cylinder_normal(t_figure *f, t_vector *p)
{
	t_vector	*normal;
	t_vector	*tmp;
	t_vector	*pro;
	float		n;

	tmp = vec_sub(p, f->coord);
	vec_norm(f->norm_v3d);
	n = vec_dot_prod(tmp, f->norm_v3d);
	pro = vec_by_scaler(f->norm_v3d, n);
	normal = vec_sub(tmp, pro);
	free(tmp);
	free(pro);
	return (normal);
}

t_vector	*get_normal(t_figure *f, t_vector *p, t_data *d)
{
	t_vector	*normal;

	normal = NULL;
	if (f->type == SPHERE)
		normal = vec_sub(p, f->coord);
	else if (f->type == PLANE)
		normal = new_vec(f->norm_v3d->x, f->norm_v3d->y, f->norm_v3d->z);
	else if (f->type == CYLINDER)
		normal = calculate_cylinder_normal(f, p);
	if (!normal)
		print_error(1, "malloc error", d);
	vec_norm(normal);
	return (normal);
}
