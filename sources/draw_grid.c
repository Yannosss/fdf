#include "fdf.h"

void ft_draw_grid(t_env *env)
{
	ft_convert_grid_coordinates(env);
	ft_draw_black_screen(env);
	ft_draw_horizontal_lines(env);
	ft_draw_vertical_lines(env);
	mlx_put_image_to_window(env->mlx, env->window, env->img.img_pt, 0, 0);

}
void	ft_draw_black_screen(t_env *env)
{
int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ft_img_pixel_put(env, x, y, COLOR_BLACK);
			x++;
		}
		y++;
	}
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
			ft_print_line(env, env->grid[x][y], env->grid[x+1][y], env->chosen_color);
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
			ft_print_line(env, env->grid[x][y], env->grid[x][y+1], env->chosen_color);
			// printf("pt [%d][%d] : %d %d\n", x, y, env->grid[x][y].x_screen, env->grid[x][y].y_screen);
			// printf("pt [%d][%d] \n", x, y);
			y++;
		}
		x++;
	}

}
