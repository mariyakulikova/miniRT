/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:42:38 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/29 16:12:15 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(int i, char *msg, t_data *data)
{
	if (i == -1)
	{
		write(STDERR_FILENO, "Error\n", 6);
		if (msg)
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
	return (('A'<= i) && (i <= 'Z'));
}
