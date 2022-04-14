#include "fdf.h"

void	ft_convert_grid_coordinates(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	while (x < env->grid_width)
	{
		y = 0;
		while (y < env->grid_height)
		{
			ft_convert_node_coordinate(env, &(env->grid[x][y]));
			y++;
		}
		x++;
	}
}

void	ft_convert_node_coordinate(t_env *env, t_node *node)
{
	float r = env->trim_r * 3.14 / 180;
	float t = env->trim_th * 3.14 / 180;
	float p = env->trim_p * 3.14 / 180;

	// node->x_grid = node->x_grid * 2;
	// node->y_grid = node->z_grid * 2;
	// node->y_grid = node->z_grid * 2;

	// rotations
	node->x_rot = node->x_grid * (cos(r) * cos(p) - sin(r) * cos(t) * sin(p)) +
					node->y_grid * (-1 * cos(r) * sin(p) - sin(r) * cos(t) * cos(p)) +
					node->z_grid * (sin(r) * sin(t));

	node->y_rot = node->x_grid * (sin(r) * cos(p) + cos(r) * cos(t) * sin(p)) +
					node->y_grid * (-1 * sin(r) * sin(p) + cos(r) * cos(t) * cos(p)) +
					node->z_grid * (-1 * cos(r) * sin(t));

	node->z_rot = node->x_grid * (sin(t) * sin (p)) +
					node->y_grid * (sin(t) * cos (p)) +
					node->z_grid * cos (t);

	// projection iso
	node->x_screen = (node->x_rot - node->y_rot) * cos(0.523599) + WINDOW_WIDTH / 2;
	node->y_screen = (node->x_rot + node->y_rot) * sin(0.523599) - node->z_rot + WINDOW_HEIGHT / 2;

	// translation
	node->x_screen = node->x_screen + env->trim_x;
	node->y_screen = node->y_screen + env->trim_y;

	// node->x_screen = node->x_screen + 500;



	// node->x_screen = node->x_rot + 400;
	// node->y_screen = node->y_rot + 200;



	// node->x_screen = (node->x_grid - node->y_grid) * cos(0.523599) + WINDOW_WIDTH / 2;
	// node->y_screen = (node->x_grid + node->y_grid) * sin(0.523599) - node->z_grid;

	// node->x_screen = node->x_grid;
	// node->y_screen = node->y_grid;
}
