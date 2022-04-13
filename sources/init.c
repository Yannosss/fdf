#include "fdf.h"

void	ft_init_env(t_env *env)
{
	env->mlx = NULL;
	env->window = NULL;
	env->img.img_pt = NULL;
	env->img.addr = NULL;
	env->img.bpp = 0;
	env->img.line_len = 0;
	env->img.endian = 0;
	// TBD a check a la fin
}

void	ft_init_mlx(t_env *env)
{
	env->mlx = mlx_init();
	if (env->mlx == NULL)
		ft_exit_mlx(env);
	env->window = mlx_new_window(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	if (env->window == NULL)
		ft_exit_mlx(env);

	env->img.img_pt = mlx_new_image(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (env->img.img_pt == NULL)
		ft_exit_mlx(env);
	env->img.addr = mlx_get_data_addr(env->img.img_pt, &(env->img.bpp), &(env->img.line_len), &(env->img.endian));
	// ft_img_pixel_put(env , WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, COLOR_GREEN);
}

void	ft_init_grid(t_env *env)
{
	int	x;
	int y;
	env->grid = malloc(sizeof(int*) * env->grid_width);
	if (!env->grid)
		ft_exit_mlx(env);
	x = 0;
	while (x < env->grid_width)
	{
		env->grid[x] = malloc(sizeof(t_node) * env->grid_height);
		if (!env->grid[x])
			ft_exit_mlx(env);
		y = 0;
		while (y < env->grid_height)
		{
			env->grid[x][y].x_grid = 0;
			env->grid[x][y].y_grid = 0;
			env->grid[x][y].z_grid = 0;
			y++;
		}
		x++;
	}
	if (!env->grid)
		ft_exit_mlx(env);
}
