#include "fdf.h"


void	ft_event_manager(t_env *env)
{
	// mlx_loop_hook(env->mlx, &handle_no_event, env);
	//mlx_key_hook(env->mlx, &handle_input, env);
	mlx_hook(env->window, KeyPress, KeyPressMask, &ft_keypress_manager, env);
	mlx_hook(env->window, ON_DESTROY, 0, &ft_exit_cross_pressed, env);
}
int	ft_exit_cross_pressed(t_env *env)
{
	ft_exit_mlx(env);
}

int	ft_keypress_manager(int key, t_env *env)
{
	ft_escape_manager(key, env);
	ft_translation_trim_manager(key, env);
	ft_rotation_trim_manager(key, env);
	ft_zoom_trim_manager(key, env);
	ft_color_trim_manager(key, env);
	return (0);
}

void	ft_escape_manager(int key, t_env *env)
{
	if (key == XK_Escape)
		ft_exit_mlx(env);
}
void	ft_translation_trim_manager(int key, t_env *env)
{
	if (key == XK_Left)
		{
			if (env->trim_x > -100000)
				env->trim_x -= 10;
		}
	if (key == XK_Right)
		{
			if (env->trim_x < 100000)
				env->trim_x += 10;
		}
	if (key == XK_Up)
		{
			if (env->trim_y > -100000)
				env->trim_y -= 10;
		}
	if (key == XK_Down)
		{
			if (env->trim_y < 100000)
				env->trim_y += 10;
		}
	ft_draw_grid(env);
}
void	ft_rotation_trim_manager(int key, t_env *env)
{
	if (key == XK_a)
		{
			if (env->trim_r > -10000)
				env->trim_r -= 5;
		}
	if (key == XK_d)
		{
			if (env->trim_r < 10000)
				env->trim_r += 5;
		}

	if (key == XK_w)
		{
			if (env->trim_th > -10000)
				env->trim_th -= 5;
		}
	if (key == XK_s)
		{
			if (env->trim_th < 10000)
				env->trim_th += 5;
		}
	if (key == XK_q)
		{
			if (env->trim_p > -10000)
				env->trim_p -= 5;
		}
	if (key == XK_e)
		{
			if (env->trim_p < 10000)
			env->trim_p += 5;
		}
	ft_draw_grid(env);
}
void	ft_zoom_trim_manager(int key, t_env *env)
{
	if (key == XK_r)
		{
			if (env->trim_zoom < 1000)
			{
			env->trim_zoom *= 1.2;
			}
		}
	if (key == XK_f)
		{
			if (env->trim_zoom > 0.0001)
			{
			env->trim_zoom /= 1.2;
			}
		}
	ft_draw_grid(env);
}
void	ft_color_trim_manager(int key, t_env *env)
{
	if (key == XK_t)
		{
			if (env->indice_chosen_color < 4)
				env->indice_chosen_color++;
			else
				env->indice_chosen_color = 0;
		}
	env->chosen_color = env->color_list[env->indice_chosen_color];
	ft_draw_grid(env);
}
// int	handle_no_event(void *data)
// {
// 	return (0);
// }

//XK_KP_0
