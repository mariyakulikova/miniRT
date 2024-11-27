/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:02:05 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/27 19:00:52 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

// t_scene	*new_scene(t_camera *camera, t_sphere *sphere);
t_scene		*new_scene(int w, int h);
t_vport		*get_view_port(float width, float hight, float fov);
t_a_light	*get_a_light(char **s);
t_camera	*get_camera(char **s);
t_light		*get_light(char **s);

#endif
