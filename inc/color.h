/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:50:57 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 10:51:00 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

t_color	*new_color(float r, float g, float b);
t_color	*get_color(char *str);
int		color_to_int(t_color *c);
t_color	*color_by_scaler(t_color *c, float scaler);
t_color	*color_multi(t_color *c1, t_color *c2);
t_color	*color_add(t_color *c1, t_color *c2);

#endif
