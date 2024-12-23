/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:59:58 by mkulikov          #+#    #+#             */
/*   Updated: 2024/12/23 16:28:20 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

t_color	*new_color(unsigned char r, unsigned char g, unsigned char b);
t_color	*get_color(char *str);
int get_figure_color(t_figure *figure);

#endif
