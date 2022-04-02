#include "fdf.h"

void	ft_exit_mlx(t_env *env)
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
	exit(0);
}