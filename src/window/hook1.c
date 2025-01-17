#include "minirt.h"

void	translate(t_vector *v, float tx, float ty, float tz)
{
	printf("Translating vector by (%f, %f, %f)\n", tx, ty, tz);
	v->x += tx;
	v->y += ty;
	v->z += tz;
	printf("New vector position: (%f, %f, %f)\n", v->x, v->y, v->z);
}

static void	handle_translation(int keycode, t_vector *coord, float tx, float ty)
{
	if (keycode == XK_i) // Translate up
		translate(coord, 0, ty, 0);
	if (keycode == XK_k) // Translate down
		translate(coord, 0, -ty, 0);
	if (keycode == XK_l) // Translate right
		translate(coord, tx, 0, 0);
	if (keycode == XK_j) // Translate left
		translate(coord, -tx, 0, 0);
}

int	ft_translate_hook(int keycode, t_data *data)
{
	float	tx;
	float	ty;

	printf("Translate hook called with keycode: %d\n", keycode);
	tx = 0.1;
	ty = 0.1;
	if (data->m_dist.near_obj == SPHERE)
		handle_translation(keycode, data->m_dist.n_obj->coord, tx, ty);
	else if (data->m_dist.near_obj == PLANE)
		handle_translation(keycode, data->m_dist.n_obj->coord, tx, ty);
	else if (data->m_dist.near_obj == CYLINDER)
		handle_translation(keycode, data->m_dist.n_obj->coord, tx, ty);
	ray_tracing(data->win->mlx_ptr, data->win->win_ptr, data);
	return (0);
}

