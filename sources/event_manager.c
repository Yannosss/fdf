#include "fdf.h"


void	ft_event_manager(t_env *env)
{
	// mlx_loop_hook(env->mlx, &handle_no_event, env);
	//mlx_key_hook(env->mlx, &handle_input, env);
	mlx_hook(env->window, KeyPress, KeyPressMask, &ft_keypress_manager, env);
}

int	ft_keypress_manager(int key, t_env *env)
{
	if (key == XK_Escape)
		ft_exit_mlx(env);

	if (key == XK_Left)
		{
			env->trim_x -= 10;
			ft_draw_grid(env);
		}
	if (key == XK_Right)
		{
			env->trim_x += 10;
			ft_draw_grid(env);
		}
	if (key == XK_Up)
		{
			env->trim_y -= 10;
			ft_draw_grid(env);
		}
	if (key == XK_Down)
		{
			env->trim_y += 10;
			ft_draw_grid(env);
		}
	printf("left : trim_x %d\n", env->trim_x);
	printf("left : trim_y %d\n", env->trim_y);

	if (key == XK_a)
		{
			env->trim_r -= 5;
			printf("4 : trim %d\n", env->trim_r);
			ft_draw_grid(env);
		}
	if (key == XK_d)
		{
			env->trim_r += 5;
			ft_draw_grid(env);
		}

	if (key == XK_w)
		{
			env->trim_th -= 5;
			ft_draw_grid(env);
		}
	if (key == XK_s)
		{
			env->trim_th += 5;
			ft_draw_grid(env);
		}
	if (key == XK_q)
		{
			env->trim_p -= 5;
			ft_draw_grid(env);
		}
	if (key == XK_e)
		{
			env->trim_p += 5;
			ft_draw_grid(env);
		}


	// printf("Keypress: %d\n", key);
	return (0);
}

// int	handle_no_event(void *data)
// {
// 	return (0);
// }

//XK_KP_0
