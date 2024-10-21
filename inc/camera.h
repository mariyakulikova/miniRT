/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:50:35 by mkulikov          #+#    #+#             */
/*   Updated: 2024/10/21 12:00:42 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

typedef struct s_camera
{
	t_vector	*origin;
	t_vector	*direction;
	float		fov;
}	t_camera;

t_camera	*new_camera(t_vector *ori, t_vector *dir, float fov);

#endif
