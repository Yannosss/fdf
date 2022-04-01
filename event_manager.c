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

	// printf("Keypress: %d\n", key);
	return (0);
}

// int	handle_no_event(void *data)
// {
// 	return (0);
// }