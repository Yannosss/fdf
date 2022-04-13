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
			ft_convert_node_coordinate(&(env->grid[x][y]));
			y++;
		}
		x++;
	}
}

void	ft_convert_node_coordinate(t_node *node)
{

	node->x_screen = (node->x_grid - node->y_grid) * cos(0.523599) + WINDOW_WIDTH / 2;
	// node->x_screen = node->x_grid;
	node->y_screen = (node->x_grid + node->y_grid) * sin(0.523599) - node->z_grid;
	// node->y_screen = node->y_grid;

	// node->x_screen = node->x_grid;
	// node->y_screen = node->y_grid;
}
