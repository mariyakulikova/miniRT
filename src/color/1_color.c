/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_color.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:38:04 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/27 16:55:24 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	*new_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color	*c;

	c = (t_color *)malloc(sizeof(t_color));
	if (!c)
		return (NULL);
	c->r = r;
	c->g = g;
	c->b = b;
	retunr (c);
}

t_color	*get_color(char *str)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	char			**s;

	s = ft_split(str, ',');
	if (!s)
		return (NULL);
	r = (unsigned char)ft_atoi(s[0]);
	g = (unsigned char)ft_atoi(s[1]);
	b = (unsigned char)ft_atoi(s[2]);
	free_split(s);
	if (in_range_int(r, 0, 255) \
		&& in_range_int(g, 0, 255) \
		&& in_range_int(b, 0, 255))
		return (new_color(r, g, b));
	return (NULL);
}
