/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:05:15 by mkulikov          #+#    #+#             */
/*   Updated: 2024/10/21 12:26:06 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_scene	*new_scene(t_camera *cs, t_sphere *s)
{
	t_scene	*sc;

	sc = (t_scene *)malloc(sizeof(t_scene));
	if (!sc)
		return (NULL);
	sc->cams;
	sc->sphere = s;
	sc->hight = HIGHT;
	sc->width = WIDTH;
	return (sc);
}
