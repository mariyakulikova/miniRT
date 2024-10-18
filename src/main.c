/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:31:46 by mkulikov          #+#    #+#             */
/*   Updated: 2024/10/18 18:25:29 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	t_window	*win;

	win = (t_window *)malloc(sizeof(t_window));
	if (!win)
		return (1);
	ft_memset(win, 0, sizeof(t_window));
	start_mlx(win);
	mlx_loop(win->mlx_ptr);
	// printf("hello world!\n");
	return (0);
}
