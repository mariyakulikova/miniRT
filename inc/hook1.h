#ifndef HOOK1_H
# define HOOK1_H

int ft_rotate_hook(int keycode, t_data *data);
void rotate_z(t_vector *v, float angle);
void rotate_y(t_vector *v, float angle);
void rotate_x(t_vector *v, float angle);
void translate(t_vector *v, float tx, float ty, float tz);
int ft_translate_hook(int keycode, t_data *data);

#endif
