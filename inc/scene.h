/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:02:05 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/20 17:41:38 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

typedef struct s_scene
{
	t_camera	*camera;
	t_sphere	*sphere;
	float		width;
	float		hight;
}	t_scene;

// t_scene	*new_scene(t_camera *camera, t_sphere *sphere);
void	init_scene(t_scene **scene);

#endif
