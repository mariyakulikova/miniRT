/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   figure.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: mkulikov <mkulikov@student.42berlin.de>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/11/25 17:50:01 by mkulikov		  #+#	#+#			 */
/*   Updated: 2024/12/28 16:05:33 by mkulikov		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minirt.h"

t_ftype	get_ftype(char *id)
{
	if (ft_strcmp(id, "sp") == 0)
		return (SPHERE);
	if (ft_strcmp(id, "pl") == 0)
		return (PLANE);
	if (ft_strcmp(id, "cy") == 0)
		return (CYLINDER);
	return (UNDEFINED);
}

t_figure	*new_figure(t_figure args)
{
	t_figure	*figure;

	figure = (t_figure *)malloc(sizeof(t_figure));
	if (!figure)
		return (NULL);
	figure->type = args.type;
	figure->norm_v3d = args.norm_v3d;
	figure->coord = args.coord;
	figure->color = args.color;
	figure->hight = args.hight;
	figure->diameter = args.diameter;
	return (figure);
}


