/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alvutina <alvutina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:52:23 by alvutina          #+#    #+#             */
/*   Updated: 2025/01/21 16:35:26 by alvutina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

struct s_point
{
	float	x;
	float	y;
	float	z;
};

typedef struct s_point	t_vector;

typedef struct s_point	t_point;

typedef struct s_sphere
{
	t_vector	*center;
	float		radius;
}	t_sphere;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

typedef enum e_ftype
{
	UNDEFINED,
	SPHERE,
	PLANE,
	CYLINDER
}	t_ftype;

typedef struct s_cylinder_intersect
{
	float		a;
	float		b;
	float		c;
	float		discriminant;
	float		t1;
	float		t2;
	float		m;
	t_vector	*camera_to_cylinder;
}	t_cylinder_intersect;

typedef struct s_sphere_intersect
{
	float	b;
	float	c;
	float	discr;
	float	dist_1;
	float	dist_squared;
	float	radius_squared;
}	t_sphere_intersect;

typedef struct s_figure
{
	t_ftype		type;
	t_vector	*norm_v3d;
	t_vector	*coord;
	t_color		*color;
	t_color		*a_color;
	t_color		*l_color;
	float		hight;
	float		diameter;
}	t_figure;

typedef struct s_vport
{
	float		width;
	float		hight;
	float		x_pixel;
	float		y_pixel;
}	t_vport;

typedef struct s_camera
{
	t_vector	*origin;
	t_vector	*direction;
	float		fov;
}	t_camera;

typedef struct s_a_light
{
	float	ratio;
	t_color	*color;
	t_color	*a_color;
}	t_a_light;

typedef struct s_light
{
	float		ratio;
	t_vector	*coord;
	t_color		*color;
	t_color		*l_color;
}	t_light;

typedef struct s_scene
{
	t_camera	*camera;
	t_sphere	*sphere;
	t_a_light	*a_light;
	t_light		*light;
	t_list		*fugures;
	float		width;
	float		hight;
	t_vport		*vplane;
}	t_scene;

typedef struct s_dist
{
	float			min_dist;
	float			dist;
	int				near_obj;
	t_figure		*n_obj;
	t_vector		*dot_light;
}	t_dist;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}			t_img;

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int		min_x;
	int		min_y;
	int		max_x;
	int		max_y;
	int		offset_x;
	int		offset_y;
	float	zoom_ratio;
	float	angle;
}			t_window;

typedef struct s_data
{
	t_window	*win;
	t_scene		*scene;
	t_dist		m_dist;
	t_figure	*selected_object;
}	t_data;

#endif
