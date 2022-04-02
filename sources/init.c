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
