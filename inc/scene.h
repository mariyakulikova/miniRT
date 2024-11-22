/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:02:05 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/22 16:32:28 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

// t_scene	*new_scene(t_camera *camera, t_sphere *sphere);
t_scene	*init_scene(int w, int h);
t_vport	*get_view_port(float width, float hight, float fov);

#endif
