#include "fdf.h"

int main(int argc, char **argv)
{
	t_env	env;
	// void	*mlx;
	// void	*window;

	if (argc != 2)
		{
			ft_putstr_fd("Wrong number of parameters : 1 is expected\n", 2);
			exit(0);
		}

	ft_init_env(&env);
	ft_init_mlx(&env);

	// ft_read_input_size(&env, argv);

	ft_draw_test_lines(&env);

	ft_event_manager(&env);
	mlx_loop(env.mlx);
	ft_exit_mlx(&env);
	// mlx_destroy_window(env.mlx, env.window);
	// mlx_destroy_display(env.mlx);
	// free(env.mlx);
	return (0);
}




int	ft_draw_test_lines(t_env *env)
{
	t_pt pt_a;
	t_pt pt_b;
	pt_a.x = -5;
	pt_a.y = 100;
	pt_b.x = 5000;
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
	pt_b.y = 5000;
	ft_print_line(env, pt_a, pt_b, COLOR_BLUE);
	pt_a.x = 100;
	pt_a.y = 100;
	pt_b.x = 110;
	pt_b.y = -30;
	ft_print_line(env, pt_a, pt_b, COLOR_WHITE);

	pt_a.x = 100;
	pt_a.y = 100;
	pt_b.x = 10;
	pt_b.y = 110;
	ft_print_line(env, pt_a, pt_b, COLOR_RED);
	pt_a.x = 100;
	pt_a.y = 100;
	pt_b.x = 10;
	pt_b.y = 90;
	ft_print_line(env, pt_a, pt_b, COLOR_GREEN);
	pt_a.x = 100;
	pt_a.y = 100;
	pt_b.x = 90;
	pt_b.y = 500;
	ft_print_line(env, pt_a, pt_b, COLOR_BLUE);
	pt_a.x = 100;
	pt_a.y = 100;
	pt_b.x = 90;
	pt_b.y = 30;
	ft_print_line(env, pt_a, pt_b, COLOR_WHITE);
	mlx_put_image_to_window(env->mlx, env->window, env->img.img_pt, 0, 0);

	return (0);
}



// compilation
// clear && gcc *.c -I ./minilibx-linux/ -L ./minilibx-linux/ -lmlx -lX11 -lXext -lm -lz && ./a.out

// clear && gcc *.c -I ./minilibx-linux/ -L ./minilibx-linux/ -lmlx -lX11 -lXext -lm -lz && valgrind --leak-check=full --show-leak-kinds=all ./a.out


