/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:50:34 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 14:26:14 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdbool.h>
# include <float.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../minilibx-linux/mlx.h"
# define M_PI 3.14159265358979323846
# define EPSILON FLT_EPSILON
# include "../libft/libft.h"
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

#endif
