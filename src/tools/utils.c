/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:42:38 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/22 17:12:40 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(int i, char *msg, t_data *data)
{
	if (i == -1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		write(STDERR_FILENO, msg, ft_strlen(msg));
	}
	if (data)
	{
		if (data->win)
			free(data->win);
		if (data->scene)
			free(data->scene);
		free(data);
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

bool	int_in_range(int i, int left, int right)
{
	return ((i >= left) && (i <= right));
}

bool	float_in_range(float i, float left, float right)
{
	return ((fabs(i - left) < 0.0001) && (fabs(i - right) < 0.0001));
}

bool	is_upper(char i)
{
	return ((i >= 'A') && (i <= 'Z'));
}
