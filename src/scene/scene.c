/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   scene.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: alvutina <alvutina@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/21 12:05:15 by mkulikov		  #+#	#+#			 */
/*   Updated: 2025/01/14 14:03:54 by alvutina		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "minirt.h"

t_scene	*new_scene(int w, int h)
{
	t_scene	*scene;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	ft_memset(scene, 0, sizeof(t_scene));
	scene->width = w;
	scene->hight = h;
	return (scene);
}

