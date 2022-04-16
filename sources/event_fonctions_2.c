/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_fonctions_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:56:08 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/16 12:00:54 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotation_trim_manager(int key, t_env *env)
{
	ft_rotation_trim_manager_r(key, env);
	ft_rotation_trim_manager_th(key, env);
	ft_rotation_trim_manager_p(key, env);
	ft_draw_grid(env);
}

void	ft_rotation_trim_manager_r(int key, t_env *env)
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
}

void	ft_rotation_trim_manager_th(int key, t_env *env)
{
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
}

void	ft_rotation_trim_manager_p(int key, t_env *env)
{
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
}
