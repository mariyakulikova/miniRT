/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_port.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:54:17 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 16:32:23 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vport	*get_view_port(float width, float hight, float fov)
{
	t_vport	*vp;
	float	aspect_ratio;

	vp = malloc(sizeof(t_vport));
	if (!vp)
		return (NULL);
	aspect_ratio = width / hight;
	vp->width = 2 * tanf((fov / 2) * (M_PI / 180));
	vp->hight = vp->width / aspect_ratio;
	vp->x_pixel = vp->width / width;
	vp->y_pixel = vp->hight / hight;
	return (vp);
}
