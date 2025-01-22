/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarguer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:50:20 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/22 15:06:46 by cmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK2_H
# define HOOK2_H

void		ft_rotate_hook(int keycode, t_data *data);
void	rotate_x(t_vector *v, float angle);
void	rotate_y(t_vector *v, float angle);
void	rotate_z(t_vector *v, float angle);

#endif
