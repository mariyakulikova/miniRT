/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   color.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mkulikov <mkulikov@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/27 16:59:58 by mkulikov		  #+#	#+#			 */
/*   Updated: 2024/12/27 16:18:56 by mkulikov		 ###   ########.fr	   */
/*																			*/
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
