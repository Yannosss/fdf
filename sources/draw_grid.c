#include "fdf.h"

void ft_draw_grid(t_env *env)
{
	ft_draw_horizontal_lines(env);
	ft_draw_vertical_lines(env);
	mlx_put_image_to_window(env->mlx, env->window, env->img.img_pt, 0, 0);

}

void	ft_draw_horizontal_lines(t_env *env)
{
	int	x;
	int	y;

	y = 0;
	while (y < env->grid_height)
	{
		x = 0;
		while (x < env->grid_width - 1)
		{
			ft_print_line(env, env->grid[x][y], env->grid[x+1][y], COLOR_BLUE);
			// printf("pt [%d][%d] : %d %d\n", x, y, env->grid[x][y].x_screen, env->grid[x][y].y_screen);
			// printf("pt [%d][%d] \n", x, y);
			x++;
		}
		y++;
	}

}

void	ft_draw_vertical_lines(t_env *env)
{
	int	x;
	int	y;

	x = 0;
	while (x < env->grid_width)
	{
		y = 0;
		while (y < env->grid_height - 1)
		{
			ft_print_line(env, env->grid[x][y], env->grid[x][y+1], COLOR_GREEN);
			// printf("pt [%d][%d] : %d %d\n", x, y, env->grid[x][y].x_screen, env->grid[x][y].y_screen);
			// printf("pt [%d][%d] \n", x, y);
			y++;
		}
		x++;
	}

}
