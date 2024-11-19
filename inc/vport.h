/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vport.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:35:02 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/19 16:36:21 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VPORT_H
# define VPORT_H

typedef struct	s_vport
{
	float	width;
	float	hight;
	float	x_pixel;
	float	y_pixel;
}				t_vport;


t_vport	*get_view_plane(float width, float hight, float fov);

#endif
