/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:51:08 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/18 17:47:57 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_event_manager(t_env *env)
{
	mlx_hook(env->window, ON_DESTROY, 0, &ft_exit_cross_pressed, env);
	mlx_hook(env->window, KeyPress, KeyPressMask, &ft_keypress_manager, env);
}

int	ft_exit_cross_pressed(t_env *env)
{
	ft_exit_mlx(env, NULL);
	return (1);
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
