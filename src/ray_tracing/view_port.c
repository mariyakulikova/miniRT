/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_port.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:33:18 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/29 11:56:43 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vport	*get_view_port(float width, float hight)
{
	t_vport	*vp;
	float	aspect_ratio;

	vp = malloc(sizeof(t_vport));
	if (!vp)
		return (NULL);
	aspect_ratio = width / hight;
	vp->width = 1;
	vp->hight = vp->width / aspect_ratio;
	vp->x_pixel = vp->width / width;
	vp->y_pixel = vp->hight / hight;
	return (vp);
}

