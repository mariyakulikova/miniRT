/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:42:38 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/22 14:44:29 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(int i, char *msg, t_minirt *minirt)
{
	if (i == -1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, msg, ft_strlen(msg));
	}
	if (minirt)
	{
		if (minirt->win)
			free(minirt->win);
		if (minirt->scene)
			free(minirt->scene);
		free(minirt);
	}
	exit(i);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error(-1, strerror(errno), NULL);
	return (fd);
}
