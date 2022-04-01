#include "fdf.h"

int main(void)
{
	t_env	env;
	// void	*mlx;
	// void	*window;

	env.mlx = mlx_init();
	if (env.mlx == NULL)
		return (MLX_ERROR);
	env.window = mlx_new_window(env.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	if (env.window == NULL)
	{
		free(env.mlx);
		return (MLX_ERROR);
	}

	ft_draw(&env);
	ft_event_manager(&env);
	mlx_loop(env.mlx);
	mlx_destroy_window(env.mlx, env.window);
	mlx_destroy_display(env.mlx);
	free(env.mlx);
}

int	ft_draw(t_env *env)
{
	env->img.img_pt = mlx_new_image(env->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	env->img.addr = mlx_get_data_addr(env->img.img_pt, &(env->img.bpp), &(env->img.line_len), &(env->img.endian));
	// ft_img_pixel_put(env , WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, COLOR_GREEN);

	t_pt pt_a;
	t_pt pt_b;
	pt_a.x = 100;
	pt_a.y = 100;
	pt_b.x = 500;
	pt_b.y = 150;
	ft_print_line(env, pt_a, pt_b, COLOR_RED);
	// ft_print_line(env, pt_b, pt_a, COLOR_RED);
	pt_a.x = 100;
	pt_a.y = 100;
	pt_b.x = 500;
	pt_b.y = 50;
	ft_print_line(env, pt_a, pt_b, COLOR_GREEN);
	pt_a.x = 100;
	pt_a.y = 100;
	pt_b.x = 110;
	pt_b.y = 500;
	ft_print_line(env, pt_a, pt_b, COLOR_BLUE);
	pt_a.x = 200;
	pt_a.y = 100;
	pt_b.x = 100;
	pt_b.y = 600;
	ft_print_line(env, pt_a, pt_b, COLOR_WHITE);
	mlx_put_image_to_window(env->mlx, env->window, env->img.img_pt, 0, 0);


	// int i = WINDOW_WIDTH / 2;
	// while (i < WINDOW_WIDTH)
	// 	{
	// mlx_pixel_put(mlx, window,	i, WINDOW_HEIGHT / 2, COLOR_GREEN);
	// i++;
	// 	}
	return (0);
}

void	ft_img_pixel_put(t_env *env, int x, int y, int color)
{
	char    *pixel;

    pixel = env->img.addr + (y * env->img.line_len + x * (env->img.bpp / 8));
	*(int *)pixel = color;
}

int main2(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}


// compilation
// clear && gcc *.c -I ./minilibx-linux/ -L ./minilibx-linux/ -lmlx -lX11 -lXext -lm -lz && ./a.out

// clear && gcc *.c -I ./minilibx-linux/ -L ./minilibx-linux/ -lmlx -lX11 -lXext -lm -lz && valgrind --leak-check=full --show-leak-kinds=all ./a.out


