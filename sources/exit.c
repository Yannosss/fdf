#include "fdf.h"

void	ft_exit_mlx(t_env *env)
{
	// TBD a finir
	ft_free_mlx(env);
	if (env->read_line)
	{
		free(env->read_line);
		env->read_line = NULL;
	}
	if (env->splitted_line)
	{
		ft_free_split(env->splitted_line);
		env->splitted_line = NULL;
	}
	ft_free_grid(env);


	exit(0);
}

void	ft_free_mlx(t_env *env)
{
	if (env->window)
	{
		if (env->img.img_pt)
			{
				mlx_destroy_image(env->mlx, env->img.img_pt);
				env->img.img_pt = NULL;
				env->img.addr = NULL;
			}
		mlx_destroy_window(env->mlx, env->window);
		// free env->window ??
		env->window = NULL;
	}
	if (env->mlx)
	{
		mlx_destroy_display(env->mlx);
		free(env->mlx);
		env->mlx = NULL;
	}
}

void	ft_free_grid(t_env *env)
{
	int	i;

	if (env->grid)
	{
		i = 0;
		while (i < env->grid_width)
		{
			if (env->grid[i])
				{
					free(env->grid[i]);
					env->grid[i] = NULL;
				}
			i++;
		}
		free(env->grid);
	}
}
