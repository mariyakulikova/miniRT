/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:50:34 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/22 12:40:47 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# define M_PI 3.14159265358979323846
# define FLT_MAX 3.40282347e+38F
# define EPSILON 1.19209290e-7F
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdbool.h>
# include "types.h"
# include "vector.h"
# include "color.h"
# include "window.h"
# include "camera.h"
# include "figure.h"
# include "scene.h"
# include "tools.h"
# include "ray_tracing.h"
# include "parsing.h"
# include "hook1.h"
# include "hook2.h"
# include "hook3.h"
# include <X11/keysym.h>
# include <X11/X.h>

#endif
