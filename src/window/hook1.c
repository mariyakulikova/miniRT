#include "minirt.h"

void translate(t_vector *v, float tx, float ty, float tz)
{
    printf("Translating vector by (%f, %f, %f)\n", tx, ty, tz);
    v->x += tx;
    v->y += ty;
    v->z += tz;
    printf("New vector position: (%f, %f, %f)\n", v->x, v->y, v->z);
}
void rotate_x(t_vector *v, float angle)
{
    printf("Rotating vector around X axis by %f degrees\n", angle);
    float rad = angle * M_PI / 180.0;
    float y = v->y * cos(rad) - v->z * sin(rad);
    float z = v->y * sin(rad) + v->z * cos(rad);
    v->y = y;
    v->z = z;
    printf("New vector position: (%f, %f, %f)\n", v->x, v->y, v->z);
}

// Function to rotate a vector around the Y axis
void rotate_y(t_vector *v, float angle)
{
    printf("Rotating vector around Y axis by %f degrees\n", angle);
    float rad = angle * M_PI / 180.0;
    float x = v->x * cos(rad) + v->z * sin(rad);
    float z = -v->x * sin(rad) + v->z * cos(rad);
    v->x = x;
    v->z = z;
    printf("New vector position: (%f, %f, %f)\n", v->x, v->y, v->z);
}

// Function to rotate a vector around the Z axis
void rotate_z(t_vector *v, float angle)
{
    printf("Rotating vector around Z axis by %f degrees\n", angle);
    float rad = angle * M_PI / 180.0;
    float x = v->x * cos(rad) - v->y * sin(rad);
    float y = v->x * sin(rad) + v->y * cos(rad);
    v->x = x;
    v->y = y;
    printf("New vector position: (%f, %f, %f)\n", v->x, v->y, v->z);
}

// Function to handle rotation based on key input
int ft_rotate_hook(int keycode, t_data *data)
{
    printf("Rotate hook called with keycode: %d\n", keycode);
    float angle = 10.0; // Rotation angle in degrees

    if (data->m_dist.near_obj == SPHERE) // Sphere
    {
        if (keycode == 0x78)
            rotate_x(data->m_dist.n_obj->coord, angle);
        if (keycode == 0x79)
            rotate_y(data->m_dist.n_obj->coord, angle);
        if (keycode == 0x7a)
            rotate_z(data->m_dist.n_obj->coord, angle);
    }
    else if (data->m_dist.near_obj == PLANE) // Plane
    {
        if (keycode == 0x78)
            rotate_x(data->m_dist.n_obj->norm_v3d, angle);
        if (keycode == 0x79)
            rotate_y(data->m_dist.n_obj->norm_v3d, angle);
        if (keycode == 0x7a)
            rotate_z(data->m_dist.n_obj->norm_v3d, angle);
    }
    else if (data->m_dist.near_obj == CYLINDER) // Cylinder
    {
        if (keycode == 0x78)
            rotate_x(data->m_dist.n_obj->norm_v3d, angle);
        if (keycode == 0x79)
            rotate_y(data->m_dist.n_obj->norm_v3d, angle);
        if (keycode == 0x7a)
            rotate_z(data->m_dist.n_obj->norm_v3d, angle);
    }

    ray_tracing(data->win->mlx_ptr, data->win->win_ptr, data);
    return (0);
}

int ft_translate_hook(int keycode, t_data *data)
{
    printf("Translate hook called with keycode: %d\n", keycode);
    float tx = 0.1, ty = 0.1; // Translation values

    if (data->m_dist.near_obj == SPHERE) // Sphere
    {
        if (keycode == XK_i) // Translate up
            translate(data->m_dist.n_obj->coord, 0, ty, 0);
        if (keycode == XK_k) // Translate down
            translate(data->m_dist.n_obj->coord, 0, -ty, 0);
        if (keycode == XK_l) // Translate right
            translate(data->m_dist.n_obj->coord, tx, 0, 0);
        if (keycode == XK_j) // Translate left
            translate(data->m_dist.n_obj->coord, -tx, 0, 0);
    }
    else if (data->m_dist.near_obj == PLANE) // Plane
    {
        if (keycode == XK_i) // Translate up
            translate(data->m_dist.n_obj->coord, 0, ty, 0);
        if (keycode == XK_k) // Translate down
            translate(data->m_dist.n_obj->coord, 0, -ty, 0);
        if (keycode == XK_l) // Translate right
            translate(data->m_dist.n_obj->coord, tx, 0, 0);
        if (keycode == XK_j) // Translate left
            translate(data->m_dist.n_obj->coord, -tx, 0, 0);
    }
    else if (data->m_dist.near_obj == CYLINDER) // Cylinder
    {
        if (keycode == XK_i) // Translate up
            translate(data->m_dist.n_obj->coord, 0, ty, 0);
        if (keycode == XK_k) // Translate down
            translate(data->m_dist.n_obj->coord, 0, -ty, 0);
        if (keycode == XK_l) // Translate right
            translate(data->m_dist.n_obj->coord, tx, 0, 0);
        if (keycode == XK_j) // Translate left
            translate(data->m_dist.n_obj->coord, -tx, 0, 0);
    }

    ray_tracing(data->win->mlx_ptr, data->win->win_ptr, data);
    return (0);
}

// // Function to rotate a vector around the X axis
// void rotate_x(t_vector *v, float angle)
// {
//     float rad = angle * M_PI / 180.0;
//     float y = v->y * cos(rad) - v->z * sin(rad);
//     float z = v->y * sin(rad) + v->z * cos(rad);
//     v->y = y;
//     v->z = z;
// }

// // Function to rotate a vector around the Y axis
// void rotate_y(t_vector *v, float angle)
// {
//     float rad = angle * M_PI / 180.0;
//     float x = v->x * cos(rad) + v->z * sin(rad);
//     float z = -v->x * sin(rad) + v->z * cos(rad);
//     v->x = x;
//     v->z = z;
// }

// // Function to rotate a vector around the Z axis
// void rotate_z(t_vector *v, float angle)
// {
//     float rad = angle * M_PI / 180.0;
//     float x = v->x * cos(rad) - v->y * sin(rad);
//     float y = v->x * sin(rad) + v->y * cos(rad);
//     v->x = x;
//     v->y = y;
// }

// // Function to handle rotation based on key input
// int ft_rotate_hook(int keycode, t_data *data)
// {
//     float angle = 10.0; // Rotation angle in degrees

//     if (data->m_dist.near_obj == SPHERE) // Sphere
//     {
//         if (keycode == 0x78)
//             rotate_x(data->m_dist.n_obj->coord, angle);
//         if (keycode == 0x79)
//             rotate_y(data->m_dist.n_obj->coord, angle);
//         if (keycode == 0x7a)
//             rotate_z(data->m_dist.n_obj->coord, angle);
//     }
//     else if (data->m_dist.near_obj == PLANE) // Plane
//     {
//         if (keycode == 0x78)
// 		{
//             rotate_x(data->m_dist.n_obj->norm_v3d, angle);
// 			printf("MOVE1");
// 		}
//         if (keycode == 0x79)
//             rotate_y(data->m_dist.n_obj->norm_v3d, angle);
//         if (keycode == 0x7a)
//             rotate_z(data->m_dist.n_obj->norm_v3d, angle);
//     }
//     else if (data->m_dist.near_obj == CYLINDER) // Cylinder
//     {
// 		if (keycode == 0x78)
// 		{
// 			printf("MOVE");
//             rotate_x(data->m_dist.n_obj->norm_v3d, angle);
// 			printf("MOVE");
// 		}
//         if (keycode == 0x79)
//             rotate_y(data->m_dist.n_obj->norm_v3d, angle);
//         if (keycode == 0x7a)
//             rotate_z(data->m_dist.n_obj->norm_v3d, angle);
//     }

//     ray_tracing(data->win->mlx_ptr, data->win->win_ptr, data);
//     return (0);
// }
