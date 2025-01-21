/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:55:44 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 10:55:56 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error(-1, "open", NULL);
	return (fd);
}

bool	in_range_int(int i, int left, int right)
{
	return ((left <= i) && (i <= right));
}

bool	in_range_float(float i, float left, float right)
{
	return ((left <= i) && (i <= right));
}

bool	is_upper(char i)
{
	return (('A' <= i) && (i <= 'Z'));
}
