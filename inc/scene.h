/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:51:42 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 10:51:50 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

t_scene		*new_scene(int w, int h);
t_vport		*get_view_port(float width, float hight, float fov);
t_a_light	*get_a_light(char **s);
t_camera	*get_camera(char **s);
t_light		*get_light(char **s);

#endif
