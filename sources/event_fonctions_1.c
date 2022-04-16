/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_fonctions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybellot <ybellot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:56:08 by ybellot           #+#    #+#             */
/*   Updated: 2022/04/16 11:58:33 by ybellot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_escape_manager(int key, t_env *env)
{
	if (key == XK_Escape)
		ft_exit_mlx(env, NULL);
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
