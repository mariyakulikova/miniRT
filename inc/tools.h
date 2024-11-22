/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:44:00 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/22 17:17:12 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

void	print_error(int i, char *msg, t_data *data);
int		open_file(char *file);
bool	int_in_range(int i, int left, int right);
bool	float_in_range(float i, float left, float right);
bool	is_upper(char i);
bool	is_lower(char i);

#endif
