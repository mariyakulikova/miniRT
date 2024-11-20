/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:42:38 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/20 17:29:09 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(int i, char *msg, t_window *win, t_scene *scene)
{
	if (i == -1)
		write(STDERR_FILENO, msg, ft_strlen(msg));
	if (!win)
		free(win);
	if (!scene)
		free(scene);
	exit(i);
}

int	open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_error(-1, strerror(errno), NULL, NULL);
	return (fd);
}
