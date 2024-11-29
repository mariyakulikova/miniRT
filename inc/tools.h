/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:44:00 by mkulikov          #+#    #+#             */
/*   Updated: 2024/11/29 13:23:44 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

void	print_error(int i, char *msg, t_data *data);
int		open_file(char *file);
bool	in_range_int(int i, int left, int right);
bool	in_range_float(float i, float left, float right);
bool	is_upper(char i);
bool	is_lower(char i);
float	ft_atof(char *str);
void	ft_free_split(char **s);

#endif
