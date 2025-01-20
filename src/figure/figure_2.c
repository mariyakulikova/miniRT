/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:05:58 by mkulikov          #+#    #+#             */
/*   Updated: 2025/01/20 17:08:54 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	*calculate_cylinder_normal(t_figure *f, t_vector *p)
{
	t_vector	*normal;
	t_vector	*tmp;
	float		n;

	tmp = vec_sub(f->coord, p);
	vec_norm(f->norm_v3d); // Normalize the cylinder's orientation vector
	n = -vec_dot_prod(tmp, f->norm_v3d);
	normal = new_vec(\
		-(f->norm_v3d->x * n + f->coord->x - p->x), \
		-(f->norm_v3d->y * n + f->coord->y - p->y), \
		-(f->norm_v3d->z * n + f->coord->z - p->z));
	free(tmp);
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

