/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:51:08 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/18 17:47:31 by ybellot          ###   ########.fr       */
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
	return (0);
}
