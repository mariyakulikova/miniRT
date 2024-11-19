/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_port.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:33:18 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/19 16:34:33 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vport	*get_view_plane(float width, float hight, float fov)
{
	t_vport	*vp;
	float		aspect_ratio;

	fov = 1;
	vp = malloc(sizeof(t_vport));
	if(!vp)
		print_error(-1);
	aspect_ratio = width / hight;
	vp->width = 1;
	vp->hight = vp->width / aspect_ratio;
	vp->x_pixel = vp->width / width;
	vp->y_pixel = vp->hight / hight;
	return(vp);
}

