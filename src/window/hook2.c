#include "minirt.h"

void	rotate_x(t_vector *v, float angle)
{
	float	rad;
	float	y;
	float	z;

	printf("Rotating vector around X axis by %f degrees\n", angle);
	rad = angle * M_PI / 180.0;
	y = v->y * cos(rad) - v->z * sin(rad);
	z = v->y * sin(rad) + v->z * cos(rad);
	v->y = y;
	v->z = z;
	printf("New vector position: (%f, %f, %f)\n", v->x, v->y, v->z);
}

// Function to rotate a vector around the Y axis
void	rotate_y(t_vector *v, float angle)
{
	float	rad;
	float	x;
	float	z;

	printf("Rotating vector around Y axis by %f degrees\n", angle);
	rad = angle * M_PI / 180.0;
	x = v->x * cos(rad) + v->z * sin(rad);
	z = -v->x * sin(rad) + v->z * cos(rad);
	v->x = x;
	v->z = z;
	printf("New vector position: (%f, %f, %f)\n", v->x, v->y, v->z);
}

// Function to rotate a vector around the Z axis
void	rotate_z(t_vector *v, float angle)
{
	float	rad;
	float	x;
	float	y;

	printf("Rotating vector around Z axis by %f degrees\n", angle);
	rad = angle * M_PI / 180.0;
	x = v->x * cos(rad) - v->y * sin(rad);
	y = v->x * sin(rad) + v->y * cos(rad);
	v->x = x;
	v->y = y;
	printf("New vector position: (%f, %f, %f)\n", v->x, v->y, v->z);
}

static void	handle_rotation(int keycode, t_vector *norm_v3d, float angle)
{
	if (keycode == XK_x)
		rotate_x(norm_v3d, angle);
	if (keycode == XK_y)
		rotate_y(norm_v3d, angle);
	if (keycode == XK_z)
		rotate_z(norm_v3d, angle);
}

int	ft_rotate_hook(int keycode, t_data *data)
{
	float	angle;

	printf("Rotate hook called with keycode: %d\n", keycode);
	angle = 10.0;
	if (data->m_dist.near_obj == SPHERE)
		handle_rotation(keycode, data->m_dist.n_obj->coord, angle);
	else if (data->m_dist.near_obj == PLANE)
		handle_rotation(keycode, data->m_dist.n_obj->coord, angle);
	else if (data->m_dist.near_obj == CYLINDER)
		handle_rotation(keycode, data->m_dist.n_obj->coord, angle);
	ray_tracing(data->win->mlx_ptr, data->win->win_ptr, data);
	return (0);
}
